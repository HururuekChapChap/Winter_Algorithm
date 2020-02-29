//
//  main.cpp
//  Bipartite_Graph(2)-1707
//
//  Created by yoon tae soo on 2020/01/10.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*

 이런 문제는 처음이였고, 점점 BFS든지,,, 백준 문제의 난이도가 올라가고 있고,, 내 실력은 후우 ㅠㅠ
 어려웠다... 결국 구글의 아이디어의 도움을 받아서 풀 수 있었는데,,, 거의 근접하게 접근 했으나,, 못했다.
 
 내 처음 방식은 모든 정점을 확인하는 것이다.
 예를들어
 
 1- 2 - 4
 | /
 3
 
 이렇게 되어 있다면, 정점 1을 확인 했을 때,  Check[2]와 Check[3] =1로 칠해준다. 그러고 나서 2와 3을 queue에 넣어주고
 2를 뽑아준다. 2는 1과 3과 4와 연결되어 있다. 1은 정점 1과 같으니 continue로 넘겨주고 3을 확인 했을 때, Check[3] = 1이기 때문에,
 이분 그래프가 아니다. 따라서 -1을 리턴해준다.
 이런 방식을 모든 정점에 대해서 해준다면 정답은 맞다. 하지만 모든 정점에 대해서 확인 해준다면 시간초과가 나온다 ㅠㅠ.
 
 그래서 어떻게 해줘야하나,,, 참 고민을 많이 했는데, 막상 떠오르는게 없었다.
 결국 방법을 찾았는데,,, 방법은 비슷하나 차이가 있다.
 
 모든 정점에 방문표시를 나눠서 해주는 것이다.
 위의 예시를 들어서 한다면, 1은 Check[1]을 1로 해준다. 그리고 1과 연결된 정점은 2와 3이다. queue에 2의 반대인
 1을 넣어줘서 2,1와 3,1을 넣어준다.
 이 Check[2]와 Check[3]에 1이 아닌 2를 넣어준다. 그리고 나서 2정점이 큐에서 나온다.
 2는 3과 4와 연결 되어 있는데, 현재 2의 위치인 Check[2]와 Check[3]이 같은 값을 가지고 있다. 따라서 이건 이분 그래프가
 아니라는 것을 확인 할 수 있고, 방문 표시를 해주는 형식으로 되어 있기 때문에, 모든 정점에 대해서 탐색을 해줄 필요가 없어진다.
 
 
 */

int Check[20001];
vector<int> v[20001];

int BFS(int current){
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(current, 2));
    Check[current] = 1;
    
    while(! q.empty() ){
            
        int item = q.front().first;
        int item_color = q.front().second;
        
        q.pop();
        
        for(int i=0;i<v[item].size(); i++){
            
            if( Check[ v[item][i] ] == 0){
                
                Check[ v[item][i] ] = item_color;
                
                if(item_color ==2){
                     q.push(make_pair(v[item][i], 1));
                }
                else{
                   q.push(make_pair(v[item][i], 2));
                }
                
            }
            else if( Check[ v[item][i] ] == Check[ item ] ){
                return - 1;
            }
            
        }
        
        
    }
    
    return 0;
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    while(T>0){
    
    int V, E;
    int vertex, edge;
    cin >> V >> E;
    
    for(int i=0; i<E; i++){
        cin >> vertex >> edge;
        
        v[vertex].push_back(edge);
        v[edge].push_back(vertex);
    }
    
    int anw=0;
    
    for(int i=1; i<= V; i++){
        
        if(Check[i] == 0){
        anw = BFS(i);
        
        }
        if(anw == -1){
            cout << "NO" << endl;
            break;
        }
        
    }
    
    if(anw==0){
        cout << "YES" << endl;
    }
        
        for(int i=0;i<20001;i++){
            v[i].clear();
            Check[i] = 0;
        }
        
        T--;
    }
    return 0;
}
