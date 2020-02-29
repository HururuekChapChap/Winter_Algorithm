//
//  main.cpp
//  Escape-3055
//
//  Created by yoon tae soo on 2020/01/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int R, C;
int end_x, end_y;
char map[51][51];
int visited[51][51]={0};
int UD[4]={1,-1,0,0};
int LR[4]={0,0,1,-1};

class Data{
public:
    int x;
    int y;
    int seq;
};

queue<Data> water;

int BFS(int x, int y){
    
    queue<Data> s;
    
    s.push({x,y,0});
    
    visited[y][x] = 2;
    
    while(!s.empty()){
        
        int x= s.front().x;
        int y= s.front().y;
        int seq = s.front().seq;
      
        s.pop();
        
        //굴 위치에 도달하면 현재 순서를 반환해준다.
        if(x == end_x && y == end_y){
            return seq;
        }
        
        //이미 물이 점령을 해버렸으면 아래 단계를 하지 않는다. 왜냐하면 다람쥐는 이미 죽었기 때문
        if(visited[y][x] == 1){
                   continue;
               }
        
        
        for(int i =0; i<4; i++){
                  
                  int temp_x = x + LR[i];
                  int temp_y = y + UD[i];
                  
                  if(temp_x>=0 && temp_x <C && temp_y >=0 && temp_y <R){
                      
                      //다람쥐는 빈 공간도 이동하고 굴 까지 이동하기 때문에 이렇게 해준다.
                      if(map[temp_y][temp_x] == '.' || map[temp_y][temp_x] == 'D'){
                          
                          //방문을 안 했다면 방문 해줬다고 표시해주는데, 다람쥐니깐 2로 해준다.
                          if(visited[temp_y][temp_x] == 0){
                              visited[temp_y][temp_x] = 2;
                              s.push({temp_x,temp_y,seq+1});
                          }
                          
                      }
                      
                  }
                  
                  
              }
        
        
        while(! water.empty()){
            int wx = water.front().x;
            int wy = water.front().y;
            int wseq = water.front().seq;
            
            //물이 다람쥐 순서와 같이아햐기 때문에 다르다면 반복문을 나간다.
            if(seq != wseq){
                break;
            }
            
            water.pop();
            
            for(int i = 0; i<4; i++){
                
                int temp_wx = wx + LR[i];
                int temp_wy = wy + UD[i];
                
                if(temp_wx>=0 && temp_wx<C && temp_wy>=0 && temp_wy <R){
                     
                    //빈공간 뿐만 아니라 물은 다람쥐가 있는 지역도 물은 침범이 가능하기 때문에 이렇게 해준다.
                    if(map[temp_wy][temp_wx] == '.' || map[temp_wy][temp_wx] =='S'){
                        
                        //물이 이미 찬 공간이 아니라면 다 방문 표시해준다.
                        if(visited[temp_wy][temp_wx] != 1){
                            visited[temp_wy][temp_wx] = 1;
                            map[temp_wy][temp_wx] = '*';
                            water.push({temp_wx,temp_wy,wseq+1});
                        }
                        
                    }
                    
                }
                
            }
        }
        
    
        }
        
    return -1;
    }
    

int main(int argc, const char * argv[]) {
    
    /*
     다람쥐 문제,,, 한 한시간 정도 걸려서 푼 것 같다. 나름 생각을 필요로 하는 문제였고
     요즘 따라 BFS가 생각을 필요로 하는게 많은 것 같다. 시뮬레이션 느낌도 많이나고,,,,
     
     일단 처음에 생각한 방식은 잘못 됐다. 처음에는 물을 하나 해주고 다람쥐 해주고 이런 씩으로 해주기 위해서
     visited[][][]이렇게 세가지 형태로 하도록 할려고 했지만 만약 첫번째 이동 때, 1,2를 방문 했으면 두번째 이동 때도
     1,2가 유지 되어야 하지만 저렇게 [][][] 세가지 형태로 했을 경우에는 그것을 보장해주지 못한다.
        예시는 이것이다.
        4 7
        .D....*
        ...S...
        .......
        *......
     
     따라서 방문 표시를 물과 다람쥐 이렇게 두가지로 달리하였다. 이렇게 생각한 기틀은 물은 계속 채워지기 때문이다. 예를 들어
     .D..***
     *..S.**
     **....*
     ***....
     두번째 이동일 때, 무조건 저런 형태가 된다. 즉, 물 중 어떤 걸 먼저 움직 였든 최종적으로 저 형태를 이루기 때문이다. 따라서 위와 같이 하였따.
    
     
     */
    
    cin >> R >> C;
    
    int x_S, y_S;
    
    for(int i=0;i<R;i++){
        for(int j =0; j<C; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 'S'){
                x_S = j;
                y_S = i;
            }
            else if(map[i][j] == '*'){
                water.push({j,i,0});
                visited[i][j] = 1;
            }
            else if(map[i][j] == 'D'){
                end_x = j;
                end_y = i;
            }
        }
    }
    
    int anw = BFS(x_S, y_S);
    
    if(anw == -1){
        cout << "KAKTUS";
    }
    else{
        cout << anw;
    }
    
    
    
    return 0;
}
