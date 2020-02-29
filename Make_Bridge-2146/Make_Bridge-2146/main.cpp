//
//  main.cpp
//  Make_Bridge-2146
//
//  Created by yoon tae soo on 2020/01/14.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int map[101][101] = {0};
int visited[101][101] = {0};
int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,1,-1};

class Data{
public:
    int y;
    int x;
    int seq;
};

queue<Data> c;
int N;
int MAX = 987654321;

/*
 굉장히 난감했다,,, 분명히 알고리즘은 맞는데 왜 틀렸는지 전혀 감이 안 잡혔다.
 생각해보니, BFS가 최단거리를 찾아주지만, 결국 처음 반환해주는 값이 최단거리를 보장해주지 않는다.
 결국 MAX라는 변수에 최대 값을 넣어주고 가장 작은 최소값을 찾아주는 방식으로 바꿔주었다.
 
 방법은 간단하다 Init_BFS로 내륙지역과 외륙지역을 나눠준다.외륙지역은 큐에 넣어주고 내륙지역은 넣어주지 않는다.
 그리고 visited에 대륙을 나눠준다.
 
 그리고 spread_BFS로 대륙을 하나씩 늘려가는데, 만나는 지역을 있을 때, MAX값과 비교해서 더 작다면 MAX값을 갱신해준다.
 */

void Init_BFS(int y, int x, int continent){
    queue<pair<int, int>> q;
    
    q.push(make_pair(y, x));
    map[y][x] = -2;
    visited[y][x] = continent;
    
    while(! q.empty()){
        
        int y = q.front().first;
        int x = q.front().second;
        int flag = 0;
        
        q.pop();
        for(int i = 0; i< 4; i++){
            
            int temp_y = y + UD[i];
            int temp_x = x + LR[i];
            
            if(temp_x >=0 && temp_x<N && temp_y>=0 && temp_y <N){
                
                if(visited[temp_y][temp_x] == 0 && map[temp_y][temp_x] == 1){
                    visited[temp_y][temp_x] = continent;
                    map[temp_y][temp_x] = -2;
                    q.push(make_pair(temp_y, temp_x));
                }
                
                if(map[temp_y][temp_x] == 0 && flag == 0){
                    flag = 1;
                    map[y][x] = -1;
                    c.push({y,x,0});
                }
                
            }
            
        }
    }
    
}

void spread_BFS(){
    
    while(!c.empty()){
         
        int y = c.front().y;
        int x = c.front().x;
        int seq = c.front().seq;
        
        c.pop();
        
        for(int i = 0; i < 4; i++){
        
            int temp_y = y + UD[i];
            int temp_x = x + LR[i];
            
            if(temp_x >=0 && temp_x <N && temp_y>=0 && temp_y < N){
                
                if(map[temp_y][temp_x] == 0){
                    visited[temp_y][temp_x] = visited[y][x];
                    map[temp_y][temp_x] = seq + 1;
                    c.push({temp_y,temp_x,seq+1});
                }
                else if(map[temp_y][temp_x] > 0 && visited[y][x] != visited[temp_y][temp_x]){
                    
                    int temp = map[temp_y][temp_x] + seq;
                    
                    if(temp < MAX){
                        MAX = temp;
                    }
                }
              
                
            }
            
        }
            
        
    }

}

int main(int argc, const char * argv[]) {
    
    
    int item;
    cin >> N;
    
    for(int i =0; i<N; i++){
        for(int j = 0; j<N ; j++){
            cin >> item;
            map[i][j] = item;
        }
    }
    
    int cnt = 0;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                cnt++;
                Init_BFS(i,j,cnt);
            }
        }
    }
    
    spread_BFS();
    
    cout << MAX;
    
    return 0;
}
