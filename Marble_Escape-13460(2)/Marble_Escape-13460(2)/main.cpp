//
//  main.cpp
//  Marble_Escape-13460(2)
//
//  Created by yoon tae soo on 2020/01/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

char map[11][11];
int visited[11][11][11][11] = {0};
int UD[4]={1,-1,0,0};
int LR[4]={0,0,1,-1};
int anw =-1;

class Data{
public:
    int Rx;
    int Ry;
    int Bx;
    int By;
    int seq;
};

int BFS(int rx, int ry, int bx, int by){
    
    queue<Data> q;
    
    q.push({rx,ry,bx,by,0});
    
    while(!q.empty()){
        
        int Rx,Ry,Bx,By;
        
        Rx = q.front().Rx;
        Ry = q.front().Ry;
        Bx = q.front().Bx;
        By = q.front().By;
        
        int seq = q.front().seq;
        
        //반환방식으로 해줬는데, 처음에는 anw에 출력해주는 방식으로 하려고 했는데,
        //큐 방식은 어차피 최단거리를 출력해주기 때문에, 가장 먼저 나온 놈이 최단일 수 밖에 없다.
        if(map[Ry][Rx] == 'O'){
            
            //10번 이하로 나올 경우에 출력해주고 그렇지 않으면 -1을 출력해준다.
            if(seq <= 10){
                return seq;
            }
            else{
                return -1;
            }
            
        }
        
        q.pop();
        
        for(int i = 0; i<4; i++){
            
            int temp_Rx = Rx;
            int temp_Ry = Ry;
            int temp_Bx = Bx;
            int temp_By = By;
            
            //이 부분이 파란공 따로 빨간공 따로 액션을 취해주는 부분이다.
            //그 다음 부분이 벽(#)을 만나면 멈춰주고 현재 부분이 구멍(O)을 만나면 멈춰준다.
            while( map[temp_Ry + UD[i] ][ temp_Rx + LR[i] ] != '#' && map[temp_Ry][ temp_Rx] != 'O'){
                
                temp_Rx = temp_Rx + LR[i];
                temp_Ry = temp_Ry + UD[i];
            }
            
            while( map[temp_By + UD[i] ][temp_Bx + LR[i] ] != '#' && map[temp_By][temp_Bx] != 'O' ){
                temp_Bx = temp_Bx + LR[i];
                temp_By = temp_By + UD[i];
            }
            
            //만약 파란 공과 빨간색 공이 같은 위치로 겹친다면
            if(temp_Ry == temp_By && temp_Rx == temp_Bx){
                
                //둘다 구멍에 빠지면 실패니깐 반복문을 나가게 해주고
                if(map[temp_Ry][temp_Rx] == 'O'){
                    continue;
                }
                //경우에 따라서 위치를 재정렬해준다.
                if(i ==0){
                    if(Ry > By){
                        temp_By--;
                    }
                    else{
                        temp_Ry--;
                    }
                }
                else if(i==1){
                    
                    if(Ry<By){
                        temp_By++;
                    }
                    else{
                        temp_Ry++;
                    }
                    
                }
                else if(i==2){
                    if(Rx>Bx){
                        temp_Bx--;
                    }
                    else{
                        temp_Rx--;
                    }
                }
                else if( i==3){
                    if(Rx<Bx){
                        temp_Bx++;
                    }
                    else{
                        temp_Rx++;
                    }
                }
                
            }
            
            //이 부분도 다른 사람의 코드를 이용했는데, 처음에는 visited[][]이렇게 빨간색 공이 방문한 부분만 처리해줄려고 했으나
            //이럴 경우에 오류가 생길 수도 있어서, 파란공과 빨간공 모두 있는 곳을 방문처리 해주는 방식으로 바꿔줬다.
            if(visited[temp_Ry][temp_Rx][temp_By][temp_Bx] == 0){
                visited[temp_Ry][temp_Rx][temp_By][temp_Bx] = 1;
                q.push({temp_Rx,temp_Ry,temp_Bx,temp_By,seq+1});
            }
            
            
        }
        
    }
    
    
    return -1;
}

int main(int argc, const char * argv[]) {
   cin >> N >> M;
    
    /*
     다른 사람의 코드를 보고 결국 더 쉬운 방법을 알게 됐다.
     기존에 내가 한 방법은 예제 코드 까지는 맞지만 결국 틀렸다. 왜 그런지 생각 해보니
     
     7 6
     ######
     #..BR#
     #.####
     #....#
     ###.##
     #O...#
     ######
     
     이렇게 파란색 공이 먼저 있을 경우에 왼쪽으로 움직였을 때, 파란공이 빨간 보다 왼쪽에 있어야 하는데,
     Marble_Escape 첫번째 방식에서는 빨간 공을 기준으로 움직여줬다. 따라서 파란공 따로 빨간공 따로 움직여 줘야한다.
     
     */
    int Rx,Ry,Bx,By;
    
    for(int i = 0; i< N; i++){
        for(int j = 0; j< M; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 'R'){
                Rx = j;
                Ry = i;
            }
            
            if(map[i][j] == 'B'){
                Bx = j;
                By = i;
            }
        }
    }
    
    visited[Ry][Rx][By][Bx] = 1;
    
    cout << BFS(Rx,Ry,Bx,By);
    
    
    return 0;
}
