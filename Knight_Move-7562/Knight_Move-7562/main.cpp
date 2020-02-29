//
//  main.cpp
//  Knight_Move-7562
//
//  Created by yoon tae soo on 2020/01/04.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int map[301][301] = {0};
int UD[8]={2,2,1,-1,1,-1,-2,-2};
int LR[8]={1,-1,2,2,-2,-2,1,-1};
int N;
int LX, LY;

class Data{
public:
    int x;
    int y;
    int cnt;
};


int BFS(int x, int y){
    queue<Data> q;
    
    map[y][x] = 1;
    
    q.push({x,y,0});
    
    while(! q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        
        q.pop();
        
        if(x == LX && y == LY){
            
            return cnt;
        }
        
        for(int i = 0; i<8; i++){
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x <N && temp_x >= 0 && temp_y <N && temp_y >= 0){
                
                if(map[temp_y][temp_x] == 0){
                    map[temp_y][temp_x] = 1;
                    q.push({temp_x,temp_y,cnt+1});
                }
                
            }
            
                
        }
        
        
    }
    
    return 0;
    
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T>0){
    
    cin>> N;
    
    int x, y;
    
    cin >> x >> y;
    cin >>LX >> LY;
    
    cout << BFS(x, y) << endl;
    
        for(int i=0; i<301; i++){
            for(int j=0; j<301; j++){
                map[i][j] = 0;
            }
        }
        
        T--;
    }
    return 0;
}
