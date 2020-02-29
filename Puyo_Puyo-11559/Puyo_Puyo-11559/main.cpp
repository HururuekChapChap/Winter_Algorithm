//
//  main.cpp
//  Puyo_Puyo-11559
//
//  Created by yoon tae soo on 2020/02/01.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

int visited[12][6] = {0};
char map[12][6];
int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,1,-1};

using namespace std;

/*
  이 문제는 그렇게 막 엄청 어렵진 않았는데, 처음 보는 유형이라서 당황했다. 오히려 집중해서 했으면 더 빨리 풀었을 것이다.
  일단 저번에 푼 것 처럼 계속 탐색을 해줘야 한다. 그리고 계속 수정해줘야한다. 이런 문제는 빙산인가? 그런 문제에 풀어본 기억이 난다.
  그런데 이제, 이동을 해줄 때가 문제이다. 이동 해줄 대 어떻게 해줘야 효율적으로 해주지 하다가 실수를 했다.
  예를 들어
 
  ...Y..
  DD..Y..
  DD....
 
  이렇게 되어 있을 때, break가 없어서 내려오면서 하나로 겹쳐지게 된다.
  이걸 생각하지 못해서 틀렸다.
  
  또한, 방문 표시를 해줄 때, 1 이면 파괴 해주고 -1 이면 파괴 해주지 않는 것인데,
  한번 턴을 돌 때, 기존에 있던 -1을 포함해줘서 오류가 생겼다.
  예를 들어
  첫번째 턴일 때,
 
  0 0 0 -1 0 0
  0 0 0 -1 0 0
  0 0 0 -0 0 0
 
  두번째 턴일 때, 모여 있는 D가 4개 이상이라서 -1을 1로 바꿔줘야하는데,
  0 0 0 -1 0 0
  -1 -1 0 -1 0 0
  -1 -1 0 0 0 0
  
  기존에 있던 Y의 -1도 포함하여 1로 바꿔주었다.
  그래서 겹치지 않게 한번 턴 돌 때, 4개 이상이면 1로 바꿔주고 아니면 2로 바꿔준다.
 
 
  
 
 */

class Data{
public:
    int x;
    int y;
};

int BFS(int x, int y){
    //탐색할 문자
    char alpa = map[y][x];
    queue<Data> q;
    //현재 위치를 담아준다.
    q.push({x,y});
    //연결성 파일을 위해서 -1로 해준다.
    visited[y][x] = -1;
    //현재 위치도 포한해야하니 시작을 1로 해준다.
    int cnt = 1;
    
    while(!q.empty()){
                
        int x= q.front().x;
        int y = q.front().y;
        
        q.pop();
        
        for(int i = 0; i<4; i++){
            
            int temp_x = x + LR[i];
            int temp_y = y + UD[i];
            
            if(temp_x>=0 && temp_x<6 && temp_y>=0 && temp_y <12){
            
            //방문하지 않았고 문자도 동일하다면 큐에 넣어준다.
            if(visited[temp_y][temp_x] == 0 && map[temp_y][temp_x] == alpa){
                visited[temp_y][temp_x] = -1;
                cnt++;
                q.push({temp_x,temp_y});
            }
                
            }
            
        }
        
    }

    //갯수가 4개 이상이라면 방문한 -1을 1로 바꿔준다.
    if(cnt >= 4){
        
        for(int i = 0; i<12 ; i++){
            for(int j = 0; j<12 ; j++){
                if(visited[i][j] == -1){
                    visited[i][j] = 1;
                }
            }
        }
        
        return 1;
    }
    //갯수가 4개 이상이 아니라면 방문한 -1을 2로 바꿔줘서 다음 턴에 중복이 생기지 않게 해준다.
    else{
        
        for(int i = 0; i<12 ; i++){
            for(int j = 0; j<12 ; j++){
                if(visited[i][j] == -1){
                    visited[i][j] = 2;
                }
            }
        }
    }
    
    return 0;
}


//아래로 이동해주는 함수
void move(int x){
    
    //맨 아래에서 부터 위로 올라가는데
    for(int i = 11; i>=0 ; i--){
        //현재 위치가 공백이라면
        if(map[i][x] == '.'){
            //그 공백 위로 부터 문자가 있는지 탐색해준다.
            for(int j = i - 1; j>=0; j--){
                //문자가 있다면 현재 위치랑 문자랑 바꿔준다. 이게 아래로 끌고 내려오는 방법이다.
                if(map[j][x] != '.'){
                    map[i][x] = map[j][x];
                    map[j][x] = '.';
                    break;
                }
            }
        }
    }
    
    
    
}



int main(int argc, const char * argv[]) {
    
    for(int i = 0; i<12 ;i++){
        for(int j = 0; j<6; j++){
            cin >> map[i][j];
        }
    }
    
    int anw = 0;
    
    while(true){
    
        //현재 파괴된 것이 있는지 없는지 확인
    int total = 0;
    
      for(int i = 0; i<12 ;i++){
          for(int j = 0; j<6; j++){
              if(visited[i][j] == 0 && map[i][j] != '.'){
                  //파괴를 위해 탐색을 해준다.
               total += BFS(j,i);
                
              }
          }
      }
        
           
    //파괴가 없다면 반복문을 나간다.
        if(total == 0){
            break;
        }
        
        anw++;

    
    for(int i = 0; i<12 ;i++){
        for(int j = 0; j<6; j++){
            //4개 이상이 되어 파괴 시켜줘야하는 것은 파괴 시켜 공백으로 바꾸준다.
            if(visited[i][j] == 1){
                visited[i][j] = 0;
                map[i][j] ='.';
            }
            //파괴 되지 않은 것은 연속에 탐색을 위해 방문 표시를 0으로 바꿔준다.
            if(visited[i][j] == 2){
                visited[i][j] = 0;
            }
        }
    }
    
    // 파괴 시켰으니 공백이 존재하기 때문에 이동시켜준다.
    for(int i=0;i<6; i++){
        move(i);
    }
        
 
    }
    

    
    cout << anw;
    
    return 0;
}
