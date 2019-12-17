//
//  main.cpp
//  Greedy_Panda-1937
//
//  Created by yoon tae soo on 2019/12/17.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[501][501] = {0};
int cnt[501][501] ={0};
int v[501][501] = {0};

int low[4] = {1,-1,0,0};
int high[4] = {0,0,1,-1};

int DFS(int y, int x, int N){
    
    //방문 표시를 해준다.
    visited[y][x] = 1;
    
    int temp_x, temp_y;
    int temp_total = 0;
    int total = 0;
    
    //상하좌우 위치를 바꿔주는 부분
    for(int i = 0; i< 4; i++){
        
        temp_x = x + low[i];
        temp_y = y + high[i];
        
        if(temp_x >=0 && temp_x <N && temp_y >=0 && temp_y < N){
        
            //대나무의 숲이 더커야하니깐
        if(v[temp_y][temp_x] > v[y][x] ){
            
            //아직 방문하지 않은 곳이라서 DFS로 탐색해서 들어가준다.
            if(visited[temp_y][temp_x] == 0){
                // 이렇게 반환된 값을 temp_total에 넣어준다. DFS는 재귀형식이기 때문에 스택이라는거!!
           temp_total = DFS(temp_y, temp_x, N);
            }
            //이미 탐색한 곳이라면, 이미 탐색한 곳은 건너뛰고 결과만 가지고 온다.
            else{
                temp_total = cnt[temp_y][temp_x];
            }
            
        }
        
        
        // 4번 돌려서 가장 큰 부분을 total에 넣어준다.
        if(temp_total > total){
            total = temp_total;
        }
            
        }
        
    }
    
    // 그것을 DP값!, cnt 부분에 넣어준다. 그래서 최대값 찾기도 쉽고 DP값을 위에서 활용해야하기 때문
    cnt[y][x] = total + 1;
    
    //최대 연결 갯수랑 현재 갯루를 반환해준다.
    return total + 1;
    
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    //입력을 해주는 부분
    for(int i = 0; i< N; i++){
        
        for(int j = 0; j < N; j++){
            cin >> v[i][j];
        }
        
    }
    
    //전 구역을 탐색하는데, 방문하지 않은 곳만 한다.
    for(int i = 0; i< N; i++){
           
           for(int j = 0; j < N; j++){
               
               if(visited[i][j] == 0){
               DFS(i,j,N);
               
               }
            
           }
           
       }
    
    int total = 0;
    //최대값을 찾는 부분
    for(int k= 0; k< N; k++){
                          
        for(int a = 0; a < N; a++){
            
            if(total < cnt[k][a] ){
                total = cnt[k][a];
            }
            
            }
    }
    
    cout << total;
    

    return 0;
}
