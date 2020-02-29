//
//  main.cpp
//  Monkey_Which_Wants_To_Be_Horse-1600
//
//  Created by yoon tae soo on 2020/02/13.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 
 아 어려웠다... 이런 걸 어떻게 생각할지,,,, 어렵다 진짜로 ㅎㅎㅎㅎ
 그런데 얻어간 것이 많다. 굉장히 많은 삽질을 했기 때문이다 ㅎㅎㅎㅎ.
 
 일단 처음에 너무 쉬운것 같아서,, 이게 16% 정답률을 가지고 있는 문제라고??? 생각했다.
 그래서 쭉 생각해보니,,,, 말의 이동으로 이동하는데, 중간에 장애물이 있으면, 이동 할 수가 없구나 라고 생각을 했다.
 예전에 폭탄 문제를 풀어 본적이 있는데,, 실패 했었던,,,
 그래서 이걸 어떻게 해결하지??? 고민을 엄청했는데,,,
 
 1) 말의 이동으로 이동할 수 있는 모든 경우를 다 배열안에 넣고 이동하다가 중간에 벽(1)이 있다면 불가능 하게 하는 걸 생각했다.
 그런데 이러한 방식은 만약에 말의 이동이
 _00
 00__
 이렇게 지그제그로 이동하는 경우라면, 어떻게 처리하지,,,,, 한마디로 불가능 했다...
 
 점점 아이디어가 고갈 되는 상태에서 다시 DFS로 탐색해주면 되겠다는 생각을 했다.
 2) 그래서 생각해 낸 것이 IS_OKey_DFS() 함수 였다.
 모든 경우는 3번 안에 이동 할 수 있다. 그래서 3번 안에 장애물을 피해서 가고자 하는 위치에 도달 할 수 있다면 갈 수 있다는 것을 알았다.
 
 앞으로 이렇게 중간에 뭔가가 있는지 탐색이 필요하는 문제는 DFS로 풀어주면 좋을 것 같다.
 
 그런데 다른 사람이 올려준 반례를 보는데,,, 장애물은 말로 뛰어 갈 수가 있었다. ㅎㅎㅎ
 그래서 내가 문제를 너무 과하게 생각했다고 깨닳았다.
 그래서 다시 원상 복귀 시켰는데,,,, 최소라고 생각한 것이 최소가 아니였다
 예를 들어
 0 0 0 0
 1 1 1 0
 1 1 1 1
 1 1 0 0
 이러한 것이 있다고 할 때, 처음 부터 이동한다고 할 때
 + + 0 0
 1 1 1 +
 1 1 1 1
 1 1 0 0
 시작 부터 말로 점프 기술을 써버리면 도착지점에 도달 할 수 없게 된다.
 따라서
 0->0->0->0
          |
 1  1  1  0
 1  1  1  1
 1  1  0  0
 
 이렇게 하나씩 이동하게 만들면 된다. 즉, 점프 기술을 몇번 썻을 때, 방문 했냐 안했냐,,
 이렇게 나눠져서 해줘야했다.
 그리고 처음 방문 했다면 counts에 넣어줘야한다. BFS를 했을 경우에 처음 방문 위치가 최단이기 때문이다.
 그리고 마지막에 최소값을 찾아주면 된다.
 */

vector<vector<int>> map;
int visited[201][201][31] = {0};
int counts[201][201][31] = {0};

int UD[12] = {1,-1,0,0,-2,-2,-1,-1,2,2,1,1};
int LR[12] = {0,0,1,-1,-1,1,-2,2,-1,1,-2,2};
int K;
int W,H;

class Data{
public:
    int x;
    int y;
    int left_k;
    int moved;
};

int yes_okey = 0;
void IS_OKey_DFS(int current, int x, int y, int end_x, int end_y){
    
    
    if(current == 3){
        
        if(x == end_x && y == end_y){
            yes_okey = 1;
        }
        
    }
    else if (current <3){
        
        for(int i = 0; i<4; i++){
            
            int temp_X = LR[i] + x;
            int temp_Y = UD[i] + y;
                       
            if(temp_X>=0 && temp_X<W && temp_Y>=0 && temp_Y <H){
            
            if(map[temp_Y][temp_X] == 0){
            IS_OKey_DFS(current+1, temp_X, temp_Y, end_x, end_y);
            }
                
            }
        }
        
    }
    
}

void BFS(){
    queue<Data> q;
    visited[0][0][K] = 0;
    q.push({0,0,K,0});
    
    while(! q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        int left_k = q.front().left_k;
        int moved = q.front().moved;
    
        
        //cout << x << "  " << y << " " << left_k << " "  <<moved << endl;
        q.pop();
        
        for(int i = 0; i<12; i++){
            
            int temp_X = LR[i] + x;
            int temp_Y = UD[i] + y;
            
           
            
            if(temp_X>=0 && temp_X<W && temp_Y>=0 && temp_Y <H){
                
                //경로에 장애물이 없어야하는 체크 방법을 만들어야함.
                
                if(map[temp_Y][temp_X] == 0){
                    
                    if(i>3){
                        
                        if(left_k>0){
                            
                            if(visited[temp_Y][temp_X][left_k-1] == 0){
                                visited[temp_Y][temp_X][left_k-1] = 1;
                                counts[temp_Y][temp_X][left_k-1] = moved+1;
                                q.push({temp_X,temp_Y,left_k-1,moved+1});
                            }
                            
                        }

                        
                    }
                    else{
                        
                        if(visited[temp_Y][temp_X][left_k] == 0){
                            visited[temp_Y][temp_X][left_k] = 1;
                             counts[temp_Y][temp_X][left_k] = moved+1;
                             q.push({temp_X,temp_Y,left_k,moved+1});
                        }
                        
                    }
                  
                    
                }
                
            }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> K;
    cin >> W >> H;
    
    map.resize(H);
    int item;
    
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            cin >> item;
            map[i].push_back(item);
        }
    }
    
    if(W-1 == 0 && H - 1 == 0){
        cout << 0;
    }
    else{
        
    BFS();
    int MIN = 987654321;
    for(int i = 0; i<=K; i++){
                   //cout << counts[H-1][W-1][i] << " ";
        if(counts[H-1][W-1][i] != 0 && MIN > counts[H-1][W-1][i] ){
            MIN = counts[H-1][W-1][i];
        }
               }
    
    if(MIN == 987654321){
        cout << -1;
    }
    else{
        cout << MIN;
    }
         
    }
    
    return 0;
}
