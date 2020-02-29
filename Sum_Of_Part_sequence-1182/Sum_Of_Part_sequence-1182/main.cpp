//
//  main.cpp
//  Sum_Of_Part_sequence-1182
//
//  Created by yoon tae soo on 2020/02/01.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int total = 0;
int visited[20] = {0};
int push[20] = {0};
vector<int> seq;

/*
 
    완전탐색 문제였다.
    모든 경우에 대해서 선택하는 것인데, N개를 선택 했을 때 부터, 1개까지 선택 했을 때 까지
    모든 경우를 탐색해준다.
    
    쉽다고 생각했는데, 틀리는 부분이 있었다.
    왜 인지 생각을 했는데, 만약에 0을 찾는 다고 했을 때,
    if(sum == M){}else{} 이렇게 되어 있다면 1 -1 1 -1 이렇게 되어 있을 때, 2개만 선택하고 나머지 두개는
    선택을 하지 않게 된다. 그래서 잘 못 했어다.
 
    두번째로 잘 못 된 것은 if(sum == M)이라고 할 때, 처음에 select가 0 일때 ,sum이 0이 가능하다 그래서 갯수를 하나더 증가하게 되는데
    이것 때문에 틀렸었다.
 
    요즘 알고리즘에 대한 그 집중력이 많이 떨어지고 슬럼프가 온 것 같다... 이제 부터 프로그래머스 에서도 연습을 해서 단련을 시켜야 겠다.
 
 */
   
void DFS(int current, int select ,int sum){
    
    if(select <= N){
    
        
    if( select >0 && sum == M){
       
        total++;
    }
    
        
        for(int i = current; i<N; i++){
            
            if(visited[i] == 0){
                
                visited[i] = 1;
              // push[select] = seq[i];
                DFS(i+1, select+1, sum + seq[i] );
                visited[i] = 0;
            
            }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
        
    cin >> N >> M;
    
    for(int i = 0; i<N; i++){
        int item;
        cin >> item;
        seq.push_back(item);
    }
    
    DFS(0,0,0);
    
    cout << total;
    
    return 0;
}
