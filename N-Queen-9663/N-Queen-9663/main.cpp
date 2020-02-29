//
//  main.cpp
//  N-Queen-9663
//
//  Created by yoon tae soo on 2020/01/23.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int visited[16][16] = {0};
int N;
int total = 0;

/*
 N-Queen 문제,,, 힘들었다. 일단 퀸은 가로,세로 , 모든 대각선으로 이동 할 수 있다.
 대각선을 처음으로 구현 해보는 것이라서 이 부분에서 구현의 문제가 존재했다.
 
 또 N-Queen 문제는 완전탐색이지만 유효하지 않은 방향은 배제 하는 완전탐색인 백트래킹 문제이다.
 이 백트래킹을 구현 할 때는, DFS 방식이 좋다는 것도 알았다.
 왜냐하면 BFS 처럼 여러 방향을 한번씩 다 보는 방식과 달리 DFS는 원래 가던 방향으로 쭉 가는 일관성이 있는 방식이다.
 
 그러나 구현에 문제가 있었다. 평소에 BFS를 사용 많이 했는데, DFS는 재귀의 방식을 사용하기 때문에, 돌아오고 들어가는 방식에서 애먹었다.
 어떤 과정을 마치고 돌아왔을 때, 다시 회귀해줘야하는 것에서 애먹었다.
 
 근데, 이런 구현의 문제를 떠나서 굉장히 어려웠는데, 그 이유는, 알고리즘을 못 찾아서 이다.
 기존에 방식은
 _Q__
 ___Q
 Q___
 __Q_
 이렇게 있다면 같은 모양이 나와도 다 계산하였다.
 그래서 저런 방식이 여러개가 나와버렸다....
 이걸 어떻게 처리야 좋을지 감이 안 잡혔고, 결국 해답을 봤다.
 
 방법은 굉장히 놀라웠는데,
 내가 했던 방식은
 가로로 채워 가는 방식이였다.
 
 예를 들어
 QXXX
 XX__
 X_X_
 X__X
 
 QXXX
 XXQ*
 X*X*
 X_*X
 
 처음 부분에 저렇게 놓는다면 빈 곳을 탐색해 갔다. 그리고 비어있다면 그 부분을 다시 채워넣는다. 진짜로 무식한 완전 탐색이라서
 중복 된 것이 여러개가 나온 것이였다.
 
 다른 사람들은 세로로 두는 것을 생각했다.
 예를 들어
 QXXX    
 XX__
 X_X_
 X__X
 
 QXXX
 XX*_
 XQX*
 X**X
 
 이렇게 세로로 탐색해서 두는 방식이다. 결국 세로 한줄에 하나의 퀸만 놓는 것이다.
 이 둘의 차이는 바로 FOR 문 갯수의 차이였다.
 처음에 가로로 탐색을 할 때는, 이중 포문으로 하였다. 이중 포문으로 한다는 것은 빈 곳을 모두 찾겠다는 것인데,
 포문 하나만 한다는 것은 한 줄에 하나만 놓고 불가능 하다면 안 하겠단 소리다....
 
 이런 짧은 생각의 차이가 큰 것을 만드는게 놀랍다....
 
 */

void DFS(int cnt, int x, int y){
    
    
    //현재 퀸이 놓아진 위치에서 모든 가능한 방향을 칠해준다.
    
    // 아래 && 위로 쭉 증가
    for(int i =0; i<N; i++){
        visited[y][i]++;
        visited[i][x]++;
    }
    
    //y- && x+ || y+ && x++
    for(int i =x ; i<N; i++){
        if(y-(i-x)>=0){
        visited[y-(i-x)][i]++;
        }
        visited[y+(i-x)][i]++;
    }
    //y-- && x-- || y++ && x--;
    for(int i=x; i>=0; i--){
        if(y-(x-i) >=0){
        visited[y-(x-i)][i]++;
        }
        visited[y+(x-i)][i]++;
    }
    
    
    //갯수가 맞다면 증가시켜준다.
    if(cnt == N){
   
            total++;
        
     }
    
    //세로에 하나만 놓는다. cnt가 마지막 4일 땐, 놓지 않도록 한다.
    for(int i = 0; i<N; i++){
        if(visited[i][cnt] == 0 && cnt+1 <=N){
            DFS(cnt+1,cnt,i);
        }
    }
        
    //회구 했을 때, 현재의 위치를 다시 돌려놓는다.
    
        for(int i =0; i<N; i++){
            visited[y][i]--;
            visited[i][x]--;
        }
        
        //y- && x+ || y+ && x++
        for(int i =x ; i<N; i++){
            if(y-(i-x)>=0){
            visited[y-(i-x)][i]--;
            }
            visited[y+(i-x)][i]--;
        }
        //y-- && x-- || y++ && x--;
        for(int i=x; i>=0; i--){
            if(y-(x-i) >=0){
            visited[y-(x-i)][i]--;
            }
            visited[y+(x-i)][i]--;
        }

  
}


int main(int argc, const char * argv[]) {
        
    cin >> N;
    
    for(int i=0; i<N; i++){
        DFS(1,0,i);
    }

    cout << total;
    return 0;
}
