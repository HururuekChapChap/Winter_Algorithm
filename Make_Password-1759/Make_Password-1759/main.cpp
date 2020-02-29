//
//  main.cpp
//  Make_Password-1759
//
//  Created by yoon tae soo on 2020/01/30.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>

/*
 이 문제는 단순 조합 문제였다. 다만 모든 경우를 다 도는 것이 아니라
 제한 조건을 둬서 모든 경우를 돌지 않겠끔 하는 문제였다.
 */

using namespace std;

char alpa[16];
int visited[16];
char push[16];
int L,C;


void DFS(int cnt){
    
    if(cnt == L){
        
        int vowel = 0;
        int consonant = 0;
        int flag = 0;
        for(int i = 0; i<L; i++){
            
            if(push[i-1] < push[i]){
            
            if(push[i] == 'a' || push[i] == 'e'|| push[i] == 'i'|| push[i] == 'o'|| push[i] == 'u'){
                vowel++;
            }
            else{
                consonant++;
            }
                
            }
            else{
                flag = 1;
                break;
            }
            
        }
        
        if(vowel >=1 && consonant >=2 && flag == 0){
        
        for(int i=0; i<L; i++){
            cout << push[i];
        }
        cout << "\n";
        }
    }
    else{
        
        for(int i=0; i<C; i++){
            
            if(visited[i] == 0 && push[cnt -1] < alpa[i] ){
                
                visited[i] = 1;
                push[cnt] = alpa[i];
                DFS(cnt+1);
                visited[i] = 0;
                
            }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
        
    cin >> L >> C;
    
    for(int i = 0; i<C; i++){
        cin >> alpa[i];
    }
    
    sort(alpa, alpa+C);
    
    DFS(0);
    
    return 0;
}
