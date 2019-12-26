//
//  main.cpp
//  Safty_Zone-2468
//
//  Created by yoon tae soo on 2019/12/26.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class Data{
public:
    int x;
    int y;
};

int N;
int Arr[101][101] = {0};
int visited[101][101] = {0};
int NUM[101] = {0};
int UD[4] = {0,0,1,-1};
int LR[4] = {1,-1,0,0};

void BFS(int x, int y, int t){
    
    queue<Data> q;
    
    q.push({x,y});
    visited[x][y] = 1;
    
    
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        
        q.pop();
        
        for(int i = 0; i<4; i++){
            
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x >=0 && temp_x < N && temp_y >= 0 && temp_y < N){
                
                //비의 높이 보다 낮은 곳은 이미 비로 점령당했기 때문에 검사 해줄 필요가 없다.
                if(visited[temp_x][temp_y] == 0 && Arr[temp_x][temp_y] > t){
                    visited[temp_x][temp_y] = 1;
                    q.push({temp_x,temp_y});
                }
                
            }
            
        }
        
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    int item;
    cin >> N;
    
    //세로
    for(int i = 0; i<N; i++){
        //가로
        for(int j = 0; j< N; j++){
            cin >> item;
            //빌딩의 높이
            NUM[item] = 1;
            
            Arr[j][i] = item;
        }
        
    }
    
    //모든 빌딩이 비 높이 1 보다 높을 때, 안전영역은 모두 하나다.
    int anw = 1;
    
    //비의 높이가 1 부터 100 까지라서 전체를 검사 해준다.
    for(int t = 1; t<101; t++){
        
        //속도를 조금이라도 빠르게 해주기 위해서 처리해줬다.
        if(NUM[t] == 1){
            int cnt = 0;
        //이 부분이 맘에 안들었지만 방법이 없었다. 매 순간마다 검사해준다.
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                
                if(visited[j][i] == 0 & Arr[j][i] > t){
                    cnt++;
                    BFS(j, i, t);
                }
                
            }
            
        }
            
            if(cnt > anw){
                anw = cnt;
            }
            
            //매순간 초기화 해준다.
            for(int k = 0; k <101; k++){
                for(int m = 0; m < 101; m++){
                    visited[m][k]=0;
                }
            }
            
        }
        
    }
    
    cout << anw;
    
    
    return 0;
}
