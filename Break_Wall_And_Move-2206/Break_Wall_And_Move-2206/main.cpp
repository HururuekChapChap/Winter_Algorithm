//
//  main.cpp
//  Break_Wall_And_Move-2206
//
//  Created by yoon tae soo on 2020/01/07.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

//입력을 문자열로 받는지 몰랐었다. ㅎㅎ
char map[1002][1002] = {0};

/*
 방문 표시를 두개 만들어줬는데, 그 이유는
 
 7 6
 000000
 111110
 111000
 111101
 000001
 011111
 000000
 
 이것 처럼 힘을 가지고 있을 때, 그 부분을 방문 한 경우와
 힘을 가지고 있지 않을때, 그 부분을 방문한 경우 두 분류로 나눠줘야하기 때문이다.
 */
int visited[1002][1002][2] ={0};

int UD[4]={1,-1,0,0};
int LR[4]={0,0,1,-1};
int N, M;

class Data{
public:
    int x;
    int y;
    int seq;
    int power;
};

int BFS(){
  
    queue<Data> q;
    
    visited[1][1][1] = 1;
    q.push({1,1,1,1});
    
    while(! q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        int seq = q.front().seq;
        int power = q.front().power;
       
        //cout << " IN  " << x << " " << y << " " << seq << " " << power << endl;
        
        q.pop();
        
        //마지막 위치에 도달하면 그만 둔다. 그리고 최단 거리이니 처음 나온 것이 답이다.
        if(x == M && y == N){
            return seq;
        }
        
        for(int i = 0; i<4; i++){
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            // 이 부분에서 굉장히 시간을 썼는데,,,, power로 그냥하니, 중간에 1을 먼저 만나버리면 power가 미리 0이 되어 버린 것이다.
            // 그래서 power가 1이 되어야 있어야하는데 0이 되어서 안된것이다. 따라서 temp_power를 만들어줘서 power를 계속 입력 받도록 해준다.
            int temp_power = power;
            
            if(temp_x >=1 && temp_x <= M && temp_y >=1 && temp_y <=N){
                int flag = 0;
            
                if(map[temp_y][temp_x] == '1' && temp_power == 1){
                    flag = 1;
                    temp_power=0;
                }
                else if(map[temp_y][temp_x] == '0'){
                    
                    flag = 1;
                }
                
                if(visited[temp_y][temp_x][temp_power] == 0 && flag == 1){
                    
                    visited[temp_y][temp_x][temp_power] = 1;
                    q.push({temp_x,temp_y,seq+1,temp_power});
                               }
            
            }
            
        }
        
    }
    
    return -1;
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    
    cout << BFS();
    
    return 0;
}
