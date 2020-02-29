//
//  main.cpp
//  History-1613
//
//  Created by yoon tae soo on 2020/02/16.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 이문제는 첨에 접근 방법을 고민했었다.
 어떻게 하면 될지,,,
 그런데 생각해 보니, 단순히 앞에 있는지 없는지만 판단해주면 됏다.
 그래서 어떰 정점에 보다 앞에 존재한다면 v 값에 넣어준다.
 그리고 탐색을 해준다.
 */

int visited[401] = {0};
int map[401][401] = {0};
//정점 앞에 존재하는 것들을 넣어준다.
vector<int> v[401];
int N, M;

//DFS로 풀 수 있지만 단순한 존재여부 탐색은 BFS가 빨라서 BFS로 탐색을 해줬다.
void BFS(int item){
    queue<int> q;
    q.push(item);
    visited[item] = 1;
    
    while(!q.empty()){
        int from = q.front();
        
        q.pop();
        for(int i= 1; i<=N; i++){
            if(map[from][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                q.push(i);
                
                //정점 벡터에 넣어준다.
                v[item].push_back(i);
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
        
    int from, to;
    
    cin >> N >> M;
    
    for(int i = 0; i< M; i++){
        cin >> from >> to;
        map[from][to] = 1;
    }
    
    //모든 정점에대해서 해준다,
    for(int i= 1; i<=N; i++){
        
        BFS(i);
        //방문표시를 초기화 해준다.
        for(int i = 1 ; i<=N; i++){
            visited[i] = 0;
        }
        
    }
    
    int S;
    cin >> S;
    
    for(int i =0 ; i<S; i++){
        int flag = 0;
        scanf("%d %d",&from,&to);
        //cin>> from >> to;
        
        //앞에 존재한다
        for(int i = 0; i < v[from].size(); i++){
            if(v[from][i] == to){
                flag = -1;
                break;
            }
        }
        
        //뒤에 존재한다.
        for(int i = 0; i< v[to].size() ; i++){
            if(v[to][i] == from){
                flag = 1;
                break;
            }
        }
        
        //관련성이 없을경우 0을 출력
        printf("%d\n",flag);
        
    }
    
    return 0;
}
