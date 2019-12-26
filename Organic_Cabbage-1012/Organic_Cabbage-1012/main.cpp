//
//  main.cpp
//  Organic_Cabbage-1012
//
//  Created by yoon tae soo on 2019/12/26.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Arr[51][51] = {0};
int UD[4] = {0,0,1,-1};
int LR[4] = {1,-1,0,0};

 int M , N ,K;

class Data{
public:
    int x;
    int y;
};

void BFS(int X, int Y){
    
    queue<Data> q;
    
    q.push({X,Y});
    
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        
        Arr[x][y] = 0;
        
        q.pop();
        
        for(int i = 0; i< 4; i++){
            
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x >=0 && temp_x < M && temp_y >=0 && temp_y < N){
                
                if(Arr[temp_x][temp_y] != 0){
                    //배추를 발견하면 발견한 위치를 0으로 바꿔줘서 재탐색을 방지한다.
                    Arr[temp_x][temp_y] = 0;
                    q.push({temp_x,temp_y});
                }
                
            }
            
        }
        
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T >0){
        
    int X, Y;
    int cnt = 0;
    cin >> M >> N >> K;
    
    //입력 값을 넣어준다.
    for(int i = 0; i<K; i++){
        cin >> X >> Y;
        
        //배추가 존재하는 곳에 1을 넣는다.
        Arr[X][Y] = 1;
        
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            
            //배추가 존재하는 곳이면 BFS 돌려서 탐색해준다.
            if(Arr[j][i] != 0){
                BFS(j,i);
                cnt++;
            }
            
        }
    }
    
    cout << cnt << '\n';
    
        T--;
    }
    
    return 0;
}
