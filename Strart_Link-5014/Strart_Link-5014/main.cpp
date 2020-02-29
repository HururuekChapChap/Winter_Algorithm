//
//  main.cpp
//  Strart_Link-5014
//
//  Created by yoon tae soo on 2020/01/11.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

long long int Arr[1000001]={0};
int UD[2];
int F, S, G, U , D;

/*
 이 문제는 간단한 문제이다.
 일반적인 BFS 문제로서 현재 층에서 U를 더해주고 D를 빼주는 위치를 큐에 넣어주는 것이다.
 문제를 잘 읽지 않아서 1층 부터 시작인지 모르고 S 보다 크거나 같을 때라는 조건을 하였는데,
 만약에 가고자 하는 층이 3층이라고 하고 현재 위치가 2층 그리고 증가가 2층 감소가 1이라고 하면
 
 2->(-1)-> 1 ->(2) -> 3 이렇게 1층이 필요하다는 것을 간과했다. 최근 2일 중 가장 쉬운 BFS 문제였다. 행복~
 */

long long int BFS(){
    queue<pair<int,long long int> >q;
    Arr[S] = 1;
    q.push(make_pair(S, 1));
    
    while(!q.empty()){
        
        int loc = q.front().first;
       long long  int seq = q.front().second;
        
        if(loc == G){
            return seq;
        }
        
        q.pop();
    
        for(int i=0; i<2; i++){
            
            int temp = loc + UD[i];
            
            if(temp>=1 && temp<=F){
                
                if(Arr[temp] == 0){
                    Arr[temp] = seq + 1;
                    q.push(make_pair(temp, seq+1));
                }
                
            }
            
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    cin >> F >> S >> G >> U >> D;
    
    UD[0] = U;
    UD[1] = D*-1;
    
    long long int anw = BFS();
    
    if(anw == -1){
        cout << "use the stairs";
    }
    else{
        cout << anw-1;
    }
    
    return 0;
}
