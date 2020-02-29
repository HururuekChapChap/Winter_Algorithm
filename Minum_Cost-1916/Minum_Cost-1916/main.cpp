//
//  main.cpp
//  Minum_Cost-1916
//
//  Created by yoon tae soo on 2020/02/12.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 
 자바와 씨플플로 다익스트라 공부를 했다. 내가 이번 코딩에서 중점적으로 한 것은 알고리즘이 아니다.
 내가 중심으로 한 것은 클래스를 이용한 우선순위 큐에 활용이였다.
 
 이번에는 아차원 배열의 vector를 v[] 를 사용하지 않고 vector<vector> 형식으로 하였다.
 그래서 어떻게 해야하나 고민을 많이 했는데, 크기 만큼 resize를 해주고 시작해야한다.
 
 이렇게 resize 해주고 Data클래스를 vector에 넣어줘야하는데 new Data()이렇게 클래스를 생성해주는 자바와 달리
 Data() 이렇게 선언해주면 된다. 간단하다.
 
 그리고 우선순위 큐에서 작은 값으로 꺼내주기 위해서는 새롭게 구축 방식을 만들어줘야한다.
 기본적으로 구성해 준 greater이 존재하지만, 이는 맨 앞에 있는 녀석으로 정렬을 해준다.
 따라서 사용자가 원하는 방식으로 정렬을 해주기 위해서는 내가 지정해준 방식으로 해줘야하는데, 이럴 때,
 구조체를 선언하고 아래와 같이 해줘야한다.
 
 나머지는 자바에서 써놓은 다이스트라 알고리즘과 같다.
 */

class Data{
    
private:
    int to;
    int weight;
    
public:
    Data(int to, int weight){
        this->to = to;
        this->weight = weight;
    }
    
int getTo(){
        return to;
    }
    
int getWeight(){
        return weight;
    }

    
};

struct cmp{
    bool operator()(Data a, Data b){
        return a.getWeight() > b.getWeight();
      }
};

vector<vector<Data>> v;
int Distance[1001];

void Dijstra(int start){
    
    priority_queue<Data,vector<Data>, cmp> pq;
    Distance[start] = 0;
    pq.push(Data(start,0));
    
    while(! pq.empty()){
        Data item = pq.top();
        
        int from = item.getTo();
        int current_distance = item.getWeight();
        
        pq.pop();
        
        for(int i = 0; i<v[from].size() ; i++){
            
            int to = v[from][i].getTo();
            int next_distance = current_distance + v[from][i].getWeight();
            
            if(next_distance < Distance[to]){
                Distance[to] = next_distance;
                pq.push(Data(to,next_distance));
            }
        }
        
        
    }
    
}


int main(int argc, const char * argv[]) {
 
    int N;
    cin >> N;
    v.resize(N+1);
    
    for(int i = 1; i<N+1; i++){
        Distance[i] = 987654321;
    }
    
    int M, from, to, weight;
    cin >> M;
    
    for(int i = 0; i<M; i++){
        cin >> from >> to >> weight;
        v[from].push_back(Data(to,weight));
    }
    
    
    int start , end;
    cin >> start >> end;
    
    Dijstra(start);
    
    
    cout << Distance[N];
   
    return 0;
}
