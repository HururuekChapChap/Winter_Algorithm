//
//  main.cpp
//  Efficient_Hacking-1325
//
//  Created by yoon tae soo on 2020/02/04.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/*
 
 일단 정답률에 많이 쫄아서 잘 풀지 못한 문제이다. 심지어 시간 복잡도도 잘 못 생각했다.
 정점은 10000개 이고 간선은 100000개 즉, 정점과 간선의 곱은 1억을 나타낸다.
 따라서 충분이 전체 탐색을 해도 가능한 부분이다. 그런데 이런 시간 복잡도를 생각하지 못하고 모조건 시간이 초과 할 거라고 생각했다.
 
 간단한 문제이다. 모든 경우에 대해서 탐색을 해주면 된다.
 
 싸이클이 도는 경우에도
 1->2->3->1
 이렇게 됐을 때, 3개 이다.
 
 그런데 나는 시간 복잡도를 줄여 보고자 너무 많은 생각을 해서 시간안에 풀지 못했다. 한심 ㅠㅠ
 
 1->2-> 3   4
         \ /
          5
         / \
        6   8 -> 1
 
 이런 상황이라고 할때, B를 알면 A를 해결 할 수 있다. 따라서 B에 대해서 탐색을 내려가면 된다.
 연결성을 v[B].push_back[A]
 이렇게 해주면 쭉 연결 된 지점을 내려가준다. 그러면 1을 알면 (1,2,3,5,6,8) 6개를 알게 되는 것이다.
 2도 (1,2,3,5,6,8) 6 개를 알게 된다.
 이렇게 모든 경우를 해주면 된다.
 
 이런 간단한 문제를 시간 복잡도를 잘 못 생각해서 무조건 시간 초과 된다고 생각해서 오랫 동안 생각했다.
 질문에 도움도 받고
 
 마지막에 정렬을 해준 이유는 굳이 필요 없는데 혹시나 했다.
 
 */

vector<int> v[10002];
queue<int> q;
int visited[10002] = {0};
int posible[10002] = {0};
int N, M;

//연결성을 탐색해준다.
int BFS(int i){
    int cnt = 1;
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    
    while(! q.empty()){
        int B = q.front();
        
        q.pop();
        for(int i = 0; i< v[B].size(); i++){
            int A = v[B][i];
            
            if(visited[A] == 0){
                
                visited[A] = 1;
                
                cnt ++;
                
                q.push(A);
            }
            
        }
    }
   
    return cnt;
}

int main(int argc, const char * argv[]) {
    
    int A, B;
    int MAX = 0;
    vector<int> anw;
    cin >> N >> M;
    
    for(int i=1; i <=M; i++){
        cin >> A >> B;
        v[B].push_back(A);
    }
 
    for(int i = 1; i<=N; i++){
        
        for(int i = 1; i<=N; i++){
            visited[i] = 0;
        }
        
      int total = BFS(i);
        
        if(total > MAX){
            anw.clear();
            anw.push_back(i);
            MAX = total;
        }
        else if(total == MAX){
            anw.push_back(i);
        }
        
    }
    
    sort(anw.begin(), anw.end());
    
    for(int i=0; i<anw.size(); i++){
        printf("%d ", anw[i] );
    }
  
  
    
    
    return 0;
}
