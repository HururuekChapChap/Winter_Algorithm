//
//  main.cpp
//  Tetreemino-14500
//
//  Created by yoon tae soo on 2020/02/27.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 
 테트리미노 문제,, 한시간 정도에 풀었다.
 일단 예전에 한번 풀어 본적 있는 문제 였다.
 
 4개의 모형
 
 1)ㅁㅁㅁㅁ
 
 2)ㅁㅁㅁ
   ㅁ
 
 3)  ㅁㅁ
   ㅁㅁ
 
 4)ㅁㅁ
   ㅁㅁ
 
 은 모두 DFS로 4번 만에 이동 할 수 있는 모양이다.
 
 하지만
  ㅁ
 ㅁㅁㅁ
 이러한 모양은 DFS로 할 수가 없다.
 
 왜냐하면 DFS로 할 경우 방문을 한 지점은 다시 원래 대로 돌아 갈 수 없기 때문이다.
 따라서 저런 모양일 경우에 대해서는 내가 직접 작성하였다.
 
 이 문제는 예전에 어떻게 하면 방문 탐색을 할 수 있을까. 문제로 한번 생각해 본적이 있는 문제였다.
 
 */

vector<vector<int>> v;
int N, M;

//이동방향을 정해준다. 상하좌우
int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,1,-1};

//방문표시를 해준다.
int visited[501][501] = {0};

int MAX = 0;

//4개의 모형에 대해서 탐색
void DFS(int current, int x, int y,int sum){
    
    //4개의 방향으로 이동했으면 최대값을 구해준다.
    if(current == 4){
        
        if(sum > MAX){
            MAX = sum;
            
        }
        
    }
    else{
        
        for(int i=0; i<4; i++){
            
            int next_x = x + LR[i];
            int next_y = y + UD[i];
            
            if(next_x >=0 && next_x <M && next_y>=0 && next_y<N){
                
                if(visited[next_y][next_x] == 0){
                    visited[next_y][next_x] = 1;
                    //방문표시를 하고 나서 그 다음 방향으로 이동을 해준다.
                    DFS(current+1, next_x , next_y, sum + v[next_y][next_x]);
                    visited[next_y][next_x] = 0;
                }
                
            }
            
        }
        
    }
    
}

//마지막 모형을 위한 탐색
void Not_DFS(int x, int y){
    
    //가로로 한번 세로로 한번
    /*
     가로
      ㅁ
     ㅁㅁㅁ. ㅁㅁㅁ
            ㅁ
     
     세로
      ㅁ  ㅁ
     ㅁㅁ  ㅁㅁ
      ㅁ  ㅁ
     */
    for(int i=0; i<2; i++){
        
        int temp = 0;
        //가로
        if(i == 0){
            
            if(x-1 >=0 && x+1<M){
                
                for(int j = 0; j<2; j++){
                    
                    if(j == 0 && y-1>=0){
                        temp = v[y][x] + v[y][x-1] + v[y][x+1] + v[y-1][x];
                    }
                    else if (j==1 && y+1<N){
                        temp = v[y][x] + v[y][x-1] + v[y][x+1] + v[y+1][x];
                    }
                    
                    if(temp > MAX){
                        MAX = temp;
                    }
                    
                }
                
            }
            
        }
        //세로
        else if(i == 1){
            
            if(y-1>=0 && y+1<N){
                
                for(int j = 0; j<2; j++){
                    
                    if(j == 0 && x-1>=0){
                        temp = v[y][x] + v[y-1][x] + v[y+1][x] + v[y][x-1];
                    }
                    else if(j == 1 && x+1<M){
                        temp = v[y][x] + v[y-1][x] + v[y+1][x] + v[y][x+1];
                    }
                    
                    if(temp > MAX){
                        MAX = temp;
                    }
                    
                }
                
            }
            
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    v.resize(N);
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            int item;
            cin >> item;
            v[i].push_back(item);
        }
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            
            DFS(0,j,i,0);
            Not_DFS(j,i);
            
        }
    }
    
    cout << MAX;
    
    
    return 0;
}
