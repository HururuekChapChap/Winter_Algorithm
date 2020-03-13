//
//  main.cpp
//  Word_Math-1339
//
//  Created by yoon tae soo on 2020/03/12.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 나느 이 문제를 백트레킹으로 문자를 제거 해주는 방식으로 풀었는데,
 훨씬 간단하게 할 수 있었다.
 처음에 생각한 방법이 있었는데, 만약에 AB BA 이런 형식으로 주어지면 어떻게 고려해줘야 할지 고민하기 힘들어서 넘어갔는데,
 지금 생각해보니 상관 없었던거 같다.
 
 그래서 나는 일단 백트레킹으로 총 알파벳이 10개 들어가고 숫자도 0~9 까지 10개 이렇게 해서 많이 돌아봤자 별로 안 돌겠거니 해서
 DFS로 풀었다.
 
 그런데 조금 고민한 문제는 "A"라는 문자에 숫자를 어떻게 넣을지 고민했다. alpa에 모두 -1로 초기화 하고 어차피 숫자가 들어가면 0~9 이기 때문에
 alpa 문자를 다시 재활용 하는 방식을 생각했다.
 
 */

int alpa[26] = {0};
int visited[10] = {0};
int MAX = 0;
vector<char> v;
vector<string> inputs;

void print(){
    
    for(int i = 0; i<26; i ++){
             cout << alpa[i] << " ";
         }
         cout << endl;
         
}

void DFS(int current){
    
    if(current == v.size()){
        int total = 0;
    
        //print();
        for(int i = 0; i<inputs.size(); i++){
            
            int temp = 0;
            //AAA일 경우에 999가 나와야하기 때문에 아래 공식 처럼 해줌
            for(int j = 0; j<inputs[i].length(); j++){
                temp = (temp*10) + alpa[inputs[i][j] - 'A'];
            }
            //cout << temp << " ";
         
            total += temp;
            
        }
        
        //cout << total << endl;
        if(total > MAX){
            MAX = total;
        }
        
    }
    else{
        //현재 알파벳을 뽑음
        char word = v[current];
        //0~9까지 모두 넣어 봄
        for(int i = 0 ; i<10; i++){
            //현재 숫자가 사용되지 않았다면
            if(visited[i] == 0){
                //숫자가 사용됐다는 표시를 해주고
                visited[i] = 1;
                //알파벳에 현재 숫자를 넣어줌
                alpa[word - 'A'] = i;
                //다음 알파벳으로 이동
                DFS(current+1);
                visited[i] = 0;
                
            }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    int N;
    string word;
    cin >> N;
 
    
    for(int i =0; i<N; i++){
        cin >> word;
        
        inputs.push_back(word);
        
        for(int j = 0; j<word.length(); j++){
            char temp_word = word[j];
            
            //알파벳 재방문을 방지
            if(alpa[temp_word - 'A'] == 0){
                //0~9 까지의 숫자를 넣을 것 고려하여 -1로 초기화
                alpa[temp_word - 'A'] = -1;
                v.push_back(temp_word);
            }
            
        }
        
    }
    
    DFS(0);
    
    cout << MAX;
    
    return 0;
}
