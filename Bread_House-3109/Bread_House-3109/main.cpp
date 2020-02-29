//
//  main.cpp
//  Bread_House-3109
//
//  Created by yoon tae soo on 2020/02/28.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int R,C;
int UD[3] = {-1,0,1};

int visited[10000][500] = {0};
string map[10000];

int anw = 0;
int flag;

int DFS(int x, int y){
    
    if(x == C-1){
        anw++;
        return true;
    }
    else{
        
        for(int i = 0; i<3; i++){
            
            int next_x = x +1;
            int next_y = y + UD[i];
            
            if(next_x>=0 && next_x<C && next_y>=0 && next_y<R){
                
                if(map[next_y][next_x] == '.' && visited[next_y][next_x] == 0){
                    
                    visited[next_y][next_x] = 1;
                    
                    if(DFS(next_x,next_y) == 1){
                        return true;
                    }
                    
                }
                
            }
            
        }
        
    }
        
    return false;
}

int main(int argc, const char * argv[]) {
    
    cin >> R>> C;

    for(int i = 0; i< R; i++){
        
        cin >> map[i];
        
    }
    
    for(int i=0;i<R;i++){
        visited[i][0] = 1;
       DFS(0, i);
    }
    
    cout << anw;

    return 0;
}
