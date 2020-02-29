//
//  main.cpp
//  Red_Green_Color-Blindness-10026
//
//  Created by yoon tae soo on 2020/01/04.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
char map2[101][101];
int visited[101][101]={0};
int visited2[101][101]={0};
int UD[4]={1,-1,0,0};
int LR[4]={0,0,1,-1};
int N;

class Data{
public:
    int x;
    int y;
};

void BFS(int x, int y, char alpa){
    
    queue<Data> q;
    
    visited[y][x]=1;
    q.push({x,y});
    
    while(! q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        
        q.pop();
        
        for(int i =0; i< 4; i++){
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x>=0 && temp_x < N && temp_y >=0 && temp_y < N){
                
                if(map[temp_y][temp_x] == alpa && visited[temp_y][temp_x] == 0){
                    visited[temp_y][temp_x] = 1;
                    q.push({temp_x,temp_y});
                }
                
            }
        }
        
    }
    
}

void BFS2(int x, int y, char alpa){
    
    queue<Data> q;
    
    visited2[y][x]=1;
    q.push({x,y});
    
    while(! q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        
        q.pop();
        
        for(int i =0; i< 4; i++){
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x>=0 && temp_x < N && temp_y >=0 && temp_y < N){
                
                if(map2[temp_y][temp_x] == alpa && visited2[temp_y][temp_x] == 0){
                    visited2[temp_y][temp_x] = 1;
                   q.push({temp_x,temp_y});
                }
                
            }
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            cin >> map[i][j];
            
            if(map[i][j] == 'R'){
                map2[i][j] = 'G';
            }
            else{
                map2[i][j] = map[i][j];
            }
        }
    }
    
    int cnt = 0;
    int cnt2 = 0;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            
            
            if(visited[i][j] == 0){
                BFS(j,i,map[i][j]);
                cnt++;
            }
            
            if(visited2[i][j] == 0){
                BFS2(j, i, map2[i][j]);
                cnt2++;
            }
             
            
            
        }
        
        
    }
    
    cout << cnt << " " << cnt2;
    
    
    return 0;
}
