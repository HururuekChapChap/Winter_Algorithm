//
//  main.cpp
//  Tree_Diameter-1967
//
//  Created by yoon tae soo on 2020/01/23.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 내 알고리즘은 운 좋게 1.2초가 나와서 통과 하였다.
 이 알고리즘은, 모든 정점에 대해서 탐색을 해주는 방식이다.
 총 N 번 탐색을 해주는데, 이때, 가장 길이가 긴 것을 반환해준다.
 그런데 visited 값을 초기화 해줘야 하기 때문에 총 N*N 정도의 시간이 나온다.
 그래서 구린 알고리즘이다 ㅎㅎ.
 
 다른 사람들은 원의 지름 방법을 이용했다. 루트가 1이라는 전제 하에, 1에서 부터 가장 먼 곳을 찾아준다.
 그리고 그곳에서 다시 탐색을 해준다. 그러면 최장 길이의 지름이 나온다.
 
                        1
                       / \
                      2.  3
                     / \   \
                    4.  5.  6
 
 이렇다고 할 때, 1에서 부터 6 까지 가는 지름이 가장 길다고 할 때, 6에서 부터 다시 가장 길이가 긴 곳을 찾아주면
 5 - 2 - 1 - 3- 6 이렇게 나올 수 있는 것이다.
 */

class Data{
public:
    int to;
    int weight;
};

int visited[10001] = {0};
vector<Data> v[10001];
int N;

int BFS(int current){
    //방문 표시를 초기화 해준다.
    for(int i = 0; i< 10001; i++){
        visited[i] = 0;
    }
    //노드 번호와 길이 값을 저장해준다.
    queue<pair<int, int>> q;
    int MAX = 0;
    
    visited[current] = 1;
    
    q.push(make_pair(current, 0));
    
    while(! q.empty()){
        
        int from = q.front().first;
        int weight = q.front().second;
        
        //길이가 더 긴 지름이 있다면 갱신해준다.
        if(weight > MAX){
            MAX = weight;
        }
        
        q.pop();
        
        for(int i = 0; i<v[from].size(); i++){
                
            int temp_to = v[from][i].to;
            int temp_weight = v[from][i].weight;
                
            if(visited[temp_to] == 0){
                visited[temp_to] = 1;
                //현재 까지의 길이에서 다음 노드 까지의 길이를 더해준다.
                q.push(make_pair(temp_to, temp_weight + weight));
            }
            
            
        }
        
    }
    
    return MAX;
}

int main(int argc, const char * argv[]) {
        
    cin >> N;
    int to, from , weight;
    int anw = 0;
    
    for(int i = 2; i<=N; i++){
        cin >> from >> to >> weight;
        v[from].push_back({to,weight});
        v[to].push_back({from,weight});
    }
    
    //모든 노드를 탐색해준다.
    for(int i = 1 ; i<=N; i++){
        int temp = BFS(i);
        
        if(temp > anw){
            anw = temp;
        }
        
    }
    
    cout << anw;
    
    
    return 0;
}
