//
//  main.cpp
//  Iceberge - 2573
//
//  Created by yoon tae soo on 2020/01/13.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Data{
public:
    int x;
    int y;
    int seq;
};

int visited[301][301] = {0};
int map[301][301]={0};
int UD[4] = {0,0,1,-1};
int LR[4] = {1,-1,0,0};

queue<Data> q;

/*
 코딩은 정말 작은 실수에도 많은 것이 바뀌는 것을 알려준 문제이다 ㅠㅠ.
 처음에는 DFS로 몇개의 파트로 나눠져 있는지 확인 할려고 했는데, 이게 메모리 초과가 나왔다.
 큐에 스택까지 하는 행위이다 보니깐 메모리초과가 나올만 했다.
 
 결국 BFS로 파트의 갯수를 탐색해주도록 하였다.BFS로 한다면 추가로 쌓이는 것을 막아줄 수 있다.
 
 그리고 자세한 코드 설명은 아래에 주석으로 닮았다.
 */

int Is_seperated_DFS(vector<vector<int>> v,int x, int y ,int N, int M){
    
    for(int i = 0; i< 4; i++){
        
        int temp_x = x + LR[i];
        int temp_y = y + UD[i];
        
        if(temp_x >=0 && temp_x < M && temp_y>=0 && temp_y <N){
                
            if( v[temp_y][temp_x] > 0 && visited[temp_y][temp_x] == 0){
                visited[temp_y][temp_x] = 1;
                Is_seperated_DFS(v, temp_x, temp_y, N, M);
            }
            
        }
        
    }
    
    return 1;
}

int Is_seperated_BFS(vector<vector<int>> v,int x, int y ,int N, int M){
    queue<Data> s;
    
    visited[y][x] = 1;
    s.push({x,y,0});
    while(!s.empty()){
        
        int x = s.front().x;
        int y = s.front().y;
        
        s.pop();
        
        for(int i = 0; i<4; i++){
         
            int temp_x = x +LR[i];
            int temp_y = y +UD[i];
            
            
        if(temp_x>=0 && temp_x <M && temp_y >=0 && temp_y <N){
                       
            if(v[temp_y][temp_x] >0 && visited[temp_y][temp_x] == 0){
                visited[temp_y][temp_x] = 1;
                s.push({temp_x,temp_y,0});
            }
            
          }
            
        }
    
    }
  
    
    return 1;
}

int BFS(vector<vector<int>> v, int N, int M){
    
    //처음 부터 나눠져 있을 것을 대비하여 -1로 하였다.
    int anw_seq = -1;
    
    //큐가 더 이상 들어 있는게 없다면 빙하가 다 녹았다는 의미이고 부분으로 나눠지지 못했다는 걸 의미한다.
    while(!q.empty()){
        //일수가 증가한다.
        anw_seq++;
        int cnt = 0;
        
        //파트가 몇개로 나눠져 있는지 탐색해준다.
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if( visited[i][j] == 0 && v[i][j] > 0  ){
                    //cout << i << " " << j << endl;
                    Is_seperated_BFS(v, j, i, N, M);
                    cnt++;
                }
            }
        }
        
        //탐색을 마치고 나서 visited는 일수 마다 탐색해줘야 하기 때문에 초기화 해준다.
        for(int i = 0; i<N; i++){
                  for(int j = 0; j<M; j++){
                      //v는 해당 일수의 지속적인 변화를 담았다. 그리고 일수 마다변화를 담는 것은 map이다.
                      map[i][j] = v[i][j];
                      
                      visited[i][j] = 0;
                  }
              }
        
        //파트가 2개 이상으로 나눠졌으면 일수를 출력해준다.
        if(cnt > 1){
            return anw_seq;
        }
        
        // 지속적인 반복을 돌려준다.
        while(!q.empty()){
            
            int x = q.front().x;
            int y = q.front().y;
            int seq = q.front().seq;
            
            //큐로 쭉 넣어줬는데, 일수가 다르다면 반복을 멈춘다.
            if(anw_seq < seq){
                break;
            }
            
            //일수가 같다면 최상단의 값을 지워준다.
            q.pop();
                   
        //상하좌우로 이동을 해준다.
        for(int i = 0; i< 4; i++){
            
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x>=0 && temp_x <M && temp_y >=0 && temp_y <N){
            
            //해당 일수의 값이 바다 일 경우에 지속적으로 줄여준다.
            //여기서 내가 실수한것이 음수 값이 존재한다는 것을 깜빡했다 == 0 에서 <= 0 으로 바꿔줘야 했다.
            if(map[temp_y][temp_x] <= 0){
                v[y][x]--;
            }
                
            }
            
        }
        
        //아직 빙하가 살아 있다면 일수를 증가시켜서 큐에 담아준다.
        if(v[y][x] >0){
            q.push({x,y,seq+1});
        }
        
        }
        
    }
    
    return 0;
    
}

int main(int argc, const char * argv[]) {
    
    
    int N, M;
    int item;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    
    for(int i = 0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> item;
            //v는 지속적인 변화를 닮기 위해 사용하였따.
            v[i][j] = item;
            //map은 일수별 변화를 닮기 위해서 사용하였다.
            map[i][j] = item;
            
            if(item != 0){
                //바다가 아니라면 큐에 담아준다.
                q.push({j,i,0});
            }
            
        }
    }
    
    int anw = BFS(v,N,M);
    
    cout << anw;
    

    return 0;
}
