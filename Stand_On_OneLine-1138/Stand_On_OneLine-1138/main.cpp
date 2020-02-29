//
//  main.cpp
//  Stand_On_OneLine-1138
//
//  Created by yoon tae soo on 2020/01/23.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 나는 그냥 10*10 으로 2초를 넘기지 않을 것 같아서 조합으로 풀었다. 일단 아이디어를 생각해서 푸는게 먼저라고
 생각했다. 모든 조합을 사용하면 모든 번호를 나열하고 큰 숫자가 몇개 인지 세준다. 그래서 별 이상 없다면 출력해준다.
 
 이렇게 구린 방법도 있지만, 사람들이 푼 것을 생각하니깐, 어이가 없었다.
 일단 키 순서대로 정렬이 된 상태에서 왼쪽으로 줄을 세운다. 그리고 왼쪽에 각 키 보다 큰 사람이 몇명인지 입력 받는다.
 이렇게 몇명인지 입력 받으면, 채워주는 형식이다.
 
 2 1 1 0
 이렇게 입력 받으면
 최소 1은 - - * - 3번째 위치에 있어야한다. 왜냐하면 앞에 최소 2명이나 더 큰놈들이 존재하기 때문이다.
 2는 최소 앞에 한명이 있어야하니, - 2 1 - 이렇게 된다.
 3은 최소 앞에 한명 있어야한다, - 2 1 3 이 된다. 2와 1은 이미 채워졌다.
 그리고 4는 앞에 없으므로 빈 자리에 넣어준다.
 */

int visited[12] ={0};
int push[11] = {0};
int n;
vector<int> v;
void DFS(int cnt){
    
    if(cnt == n){
        int flag = 0;
        for(int i=0; i<n; i++){
            int counted = 0;
            for(int j=i-1; j>=0; j--){
                    
                if(push[i] < push[j]){
                    counted++;
                }
                
            }
            
            
            if(v[push[i]] != counted){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            for(int i =0; i<n; i++){
                cout << push[i] << " ";
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        
        if(visited[i] == 0){
            visited[i] = 1;
            push[cnt] = i;
            DFS(cnt+1);
            visited[i] = 0;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    int item;
    cin >> n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        cin >> item;
        v.push_back(item);
    }
    
    DFS(0);
    
    return 0;
}
