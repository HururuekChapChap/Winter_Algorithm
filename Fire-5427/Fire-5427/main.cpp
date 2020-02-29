//
//  main.cpp
//  Fire-5427
//
//  Created by yoon tae soo on 2020/02/29.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>


/*
 
 드디어 300을 찍었다. 이 문제는 그렇게 많이 어렵거나 하지는 않았지만, 그냥 구현 문제 였다.
 하지만 메모리 초과가 발생했는데, 내가 벽이 아닐 경우에 다 큐를 넣도록 하여서 불도 큐에 넣게 되어 메모리 초과가 발생했다.
 
 불이 닿을 예정인 곳도 이동 할 수 없다고 하니 일단 불을 먼저 이동 시킨다. 여기서 중요한건 불과 사람의 초수가 같아야 한다는 것이다.
 그리고 나서 상근이를 이동시켜준다.
 
 상근이의 이동을 볼때,빨리 출구에 도달해야하기 때문에, 다시 뒤로 돌아가는 일은 없어야 한다. 따라서 방문 표시를 해준다.
 
 */
using namespace std;

char map[1001][1001];
int visited[1001][1001] = {0};

int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,1,-1};

int w, h;

class Data{
public:
    int x;
    int y;
    int seq;
};

queue<Data> fire;
queue<Data> sangeun;

int BFS(int x, int y){
    //상근이 위치를 넣어준다.
    sangeun.push({x,y,0});
    //방문표시를 해준다.
    visited[y][x] = 1;
    //상근이가 불에 잡식 되기 전까지
    while( !sangeun.empty() ){
        
        int x = sangeun.front().x;
        int y = sangeun.front().y;
        int seq = sangeun.front().seq;
        
        sangeun.pop();
        
        //상근이가 탈출하면 몇초만에 탈출했는지 반환
        if(x-1 < 0 || x+1 >=w || y-1 <0 || y+1 >=h){
            return seq+1;
        }
        
        //불이 존재하고 불의 초수가 상근이 초수랑 같음이 참일때,
        while(!fire.empty() && seq == fire.front().seq ){
            
            int fire_x = fire.front().x;
            int fire_y = fire.front().y;
            int fire_seq = fire.front().seq;
            
            fire.pop();
            
            for(int i = 0; i<4; i++){
                
                int fire_move_x = fire_x + LR[i];
                int fire_move_y = fire_y + UD[i];
                //범위를 넘지않고
                if(fire_move_x>=0 && fire_move_x<w && fire_move_y>=0 && fire_move_y<h){
                    //여기서 메모리 초과가 발생했는데, 벽이 아니고 불이 아니라면
                    if(map[fire_move_y][fire_move_x] != '#' && map[fire_move_y][fire_move_x] != '*'){
                       //이동한 지역을 불로 변화시킨다.
                        map[fire_move_y][fire_move_x] = '*';
                        fire.push({fire_move_x,fire_move_y,fire_seq+1});
                    }
                    
                }
                
            }
        }
        
        for(int i = 0; i<4; i++){
            
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x >=0 && temp_x < w && temp_y >=0 && temp_y <h){
                //상근이를 이동시킨다.
                if(map[temp_y][temp_x] == '.' && visited[temp_y][temp_x] == 0){
                
                    visited[temp_y][temp_x] = 1;
                    sangeun.push({temp_x,temp_y,seq+1});
                
                }
                
            }
            
        }
        
    }
    
    
    return -1;
}

int main(int argc, const char * argv[]) {

    int t;
    cin >> t;
    
    while(t>0){
    
    cin >> w >> h;
    
    int x=0,y=0;
        //입력받는다.
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w ; j++){
            cin >> map[i][j];
            
            visited[i][j] = 0;
            //불이라면 불큐에 넣어준다.
            if(map[i][j] == '*'){
                fire.push({j,i,0});
            }
            //상근이의 위치
            else if(map[i][j] == '@'){
                x = j;
                y = i;
            }
            
        }
    }
    
    int anw = 0;
    anw = BFS(x,y);
    
    if(anw == -1){
        printf("IMPOSSIBLE\n");
    }
    else{
        printf("%d\n",anw);
    }
        
        while(!fire.empty()){
            fire.pop();
        }
        
        while(!sangeun.empty()){
            sangeun.pop();
        }
    
        t--;
    }
    
    
    return 0;
}
