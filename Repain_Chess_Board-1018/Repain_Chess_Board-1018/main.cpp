//
//  main.cpp
//  Repain_Chess_Board-1018
//
//  Created by yoon tae soo on 2020/01/24.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 이 문제는 그냥 완전탐색 문제이다. 그런데 처음에 틀렸었다.
 틀린 이유는 간단하다. 시작하는 문자로 바꿔치기 해줬는데, 시작하는 문자와 반대의 문자로 탐색도 해줘야 했다.
 
 근데 틀렸다.... 이 틀린 부분에 대해서는 잘 모르겠다. 왜 틀린건지.
 
 결국 이 문제를 해결하기 위해서 열심히 고민했었는데, 정확한 이유를 찾지 못해서
 그냥 탐색을 white일 때와 black 일때, 이 두가지에 대해서 탐색을 해줬다.
 왜냐하면 어차피 둘 중 하나이기 때문이다.
 결국 맞았다.
 
 */

char Board[51][51];
int N,M;

class Data{
public:
    int x;
    int y;
    char paint;
};

int BFS(int current_x, int current_y,char current_paint){
    queue<Data> q;
    
    q.push({current_x,current_y,current_paint});
    int cnt = 0;
    while(! q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        char paint = q.front().paint;
      
        //칠해져야하는 색깔과 다르다면 증가시켜준다.
        if(Board[y][x] != paint){
            cnt++;
        }
        
        q.pop();
        
        char next_paint;
        //다음에 칠해져야할 색깔, 검정이면 하얀색으로 하얀색이면 검정으로
        if(paint == 'B'){
            next_paint = 'W';
        }
        else{
            next_paint = 'B';
        }
        
        //범위 내에서 0~7까지 이니깐,
        if(x<=current_x+7 && y<=current_y+7){
            // 가로가 7일 때, 세로가 0 부터 6 까지 일때
            // 세로를 한칸 증가시키고 가로를 처음 위치로
            // 색깔은 현재 위치의 색깔로 왜냐하면 가로줄의 마지막 색이 가로줄의 처음 색과 동일하기 때문
            if(x == current_x+7 && y < current_y+7){
                q.push({current_x, y+1, paint});
            }
            // 가로가 0 부터 6까지
            // 가로를 한칸 이동
            else if(x<current_x+7){
                q.push({x+1,y,next_paint});
            }
        }
        
    }
 
    return  cnt;
    
}

int main(int argc, const char * argv[]) {
    
    int MAX = 987654321;
    cin >> N >> M;
    
    for(int i=0;i<N; i++){
        for(int j=0; j<M; j++){
            cin >> Board[i][j];
        }
    }
    
 
    
    for(int i = 0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i + 7 <N && j+7 < M){
                int White = BFS(j,i,'W');
                int Black = BFS(j,i,'B');
                int item;
                
                //둘중에 더 작은 것을 item에 넣고 item이 MAX 보다 작다면 갱신해준다.
                if(White < Black){
                    item = White;
                }
                else{
                    item = Black;
                }
                
                if(item < MAX){
                    MAX = item;
                }
                
            }
        }
    }
    
    
 
    cout << MAX;
    
    return 0;
}
