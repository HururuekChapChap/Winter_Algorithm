//
//  main.cpp
//  Sand_Bum_Building-6593
//
//  Created by yoon tae soo on 2020/02/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 
 이 문제는 상하좌우 윗층 아랫층을 이동하는 문제이다. 예전에 토마토? 문제에서 한번 만났던 것 같다.
 비슷한 문제이다. 같은 BFS 방식으로 탐색을 해주면 되는데, 차이점은 UD(윗층,아래층), NS(북,남), EW(동서) 이동하는 경우가
 증가했다는 것이다.
 
 그리고 연속적으로 탐색하는 문제는 꼭 초기화 해주는 거 잊지 말자 ㅎㅎㅎ
 */

char map[30][30][30];
int visited[30][30][30] = {0};

int UD[6] = {1,-1,0,0,0,0};
int NS[6] = {0,0,1,-1,0,0};
int EW[6] = {0,0,0,0,1,-1};

int L,R,C;
int start_L, start_R, start_C;

class Data{
public:
    int l;
    int x;
    int y;
    int seq;
};

int BFS(){
    queue<Data> q;
    q.push({start_L,start_C,start_R,0});
    visited[start_L][start_R][start_C] = 1;
    
    while(! q.empty()){
        
        int level = q.front().l;
        int x = q.front().x;
        int y = q.front().y;
        int seq = q.front().seq;
        
        q.pop();
        
        if(map[level][y][x] == 'E'){
            return seq;
        }
        
        for(int i = 0; i<6; i++){
            
            int temp_level = level + UD[i];
            int temp_x = x + EW[i];
            int temp_y = y + NS[i];
            
            if(temp_level>=0 && temp_level<L && temp_x>=0 && temp_x<C && temp_y>=0 && temp_y<R){
                
                if(visited[temp_level][temp_y][temp_x] == 0
                   && (map[temp_level][temp_y][temp_x] == '.'
                       || map[temp_level][temp_y][temp_x] == 'E')){
                    
                    visited[temp_level][temp_y][temp_x] = 1;
                    q.push({temp_level,temp_x,temp_y,seq+1});
                    
                }
                
            }
            
        }
        
        
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    while(true){
        
       for(int i = 0; i<30; i++){
              for(int j = 0; j<30; j++){
                  for(int n = 0; n<30; n++){
                      map[i][j][n] = ' ';
                      visited[i][j][n] =0;
                      }
                      
                  }
              }
    
    cin >> L >> R >> C;
        
        if(L == 0 && R == 0 && C==0){
            break;
        }
    
    for(int i = 0; i<L; i++){
        for(int j = 0; j<R; j++){
            for(int n = 0; n<C; n++){
                cin >> map[i][j][n];
                
                if(map[i][j][n] == 'S'){
                    start_L = i;
                    start_R = j;
                    start_C = n;
                }
                
            }
        }
    }
    
   int anw =  BFS();
    
    if(anw == -1){
        //cout << "Trapped!" << endl;
        printf("Trapped!\n");
    }
    else{
        //cout <<"Escaped in " << anw <<" minute(s)." << endl;
         printf("Escaped in %d minute(s).\n", anw);
    }
    
    }
    return 0;
}
