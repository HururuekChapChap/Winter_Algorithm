//
//  main.cpp
//  Term_Project-9466
//
//  Created by yoon tae soo on 2020/01/29.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 
 이 문제 사이클 확인 문제 인데,,, 쉽지 않았다.
 한 한시간 반 정도 걸린 것 같다.
 일단 학생수가 100만 이였기 때문에, 시간 관리 차원을 어떻게 해야하나 정말 고민을 많이 했다.
 
 일단 모든 학생에 대해서 탐색을 해줘야 하기 때문에, 기본적으로 100만은 돌아간다. 그리고 사이클을 확인 하는 차원에서
 매번 100만 번 돌아가면 10초 걸리기 때문에 무조건 시간 초과가 된다.
 따라서 방문 표시를 해줘야한다. 그래야 한번 돌 때의 순환을 줄일 수 있다.
 
 그래서 사용한 방법은 큐와 DFS의 탐색을 사용하였다.
 
 예를 들어,  4-> 6-> 7-> 4 이렇게 순환을 돈다면 매번 방문 표시를 해준다.
 7 다음이 4가 나오기 때문에, 이미 방문 표시를 한 것이다. 그러면서 push라는 스택에 순차적으로 넣어준다.
 그리고 반환해서 나온 값 부터 현재 위치 까지 사이클 표시를 해준다.
 
 굉장히 고민한 부분은
 5-> 4-> 6-> 7-> 4
 이렇게 되어 있을 때, 5를 어떻게 처리 해줘야 하나에서 굉장히 고민을 많이 했다. 4에서 이미 순환을 마쳤는데, 5에서 다시 탐색을 하게
 된다면 이 5와 4는 사이클을 안 도는데, 어떻게 표현 해줘야하나,,, 그런데 생각을 해보니 4에서 이미 시이클이 마쳤다면 5는 4의 사이클에
 들어 갈 수 없었다.
 
 쉽지 않은 문제였다.
 
 */

//방문여부 체크
int visited[100001] = {0};
//순환여부 체크
int cycle[100001] = {0};
//학생에 대한 정보
int v[100001];
//큐
vector<int> push;

//반환식으로 한다면 쭉들어 갔다가 다시 쭉 나와야 하기 때문에 두번 돌게 된다. 따라서 많은 시간이 걸리기 때문에 좋지 않다.
void DFS(int current){
    //방문표시를 해준다.
    visited[current] = 1;
    //큐에 넣어준다.
    push.push_back(current);
    
    //방문을 안했다면 DFS로 탐색을 돌려준다.
    if(visited[v[current]] == 0){
        DFS(v[current]);
    }
    //순환을 도는 지점을 확인 했고 아직 순환을 돌지 않았다면
    else if(visited[v[current]] == 1 && cycle[v[current]] == 0){
        //시작은 반환된 놈으로 시작하고
        int start = v[current];
        //현재 위치에서 마치게 되도록 한다.
        int end = current;
        //순환을 체크 해주기 위해서 flag 변수를 사용했다.
        int flag = 0;
       
        //순환표시를 해준다.
        //큐의 특성상 순차적으로 들어가게 되어 있다.
        //처음 들어간 놈이 맨 앞에 있을 것이고 맨 마지막에 들어간 놈이 맨 뒤에 있을 것이다.
        for(int i = 0; i<push.size(); i++){
            
            //시작위치랑 같다면 flag를 1로 만들어준다.
            if(push[i] == start){
                flag = 1;
            }
            
            //flag가 1인 놈들은 모두 순환을 돌기 때문에 1로 표시해준다.
            if(flag == 1){
                 cycle[push[i]] = 1;
            }
          
            //end 값에 도착하면 flag를 꺼준다.
            if(push[i] == end){
                flag = 0;
            }
        
        }
        
    }
   
    
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T>0){
    
    int N;
    cin >> N;
    int cnt = 0;
    
    for(int i = 1; i<=N; i++){
        //cin >> v[i];
        scanf("%d", &v[i]);
    }
    
    //모든 학생들에 대해서 탐색을 해준다.
    for(int i =1 ; i<=N; i++){
        
        if(visited[i] == 0){
            //cout << i << " start " << endl;
        DFS(i);
        }
        //스택 초기화
        push.clear();
    }
    
    //순환을 돌지 않는 놈들의 갯수를 세준다.
    for(int i = 1; i<=N; i++){
        if(cycle[i] == 0){
            cnt++;
        }
        //cout << cycle[i] << " ";
    }
    
    cout << cnt << "\n";
    
        T--;
    //초기화 해준다.
    for(int i = 1; i<=N; i++){
            visited[i] = 0;
            cycle[i] = 0;
            v[i] = 0;
        }
        
    }
    return 0;
}
