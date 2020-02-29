//
//  main.cpp
//  Bomb_String-9935
//
//  Created by yoon tae soo on 2020/02/25.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 이 문제는 어떻게 풀어야할지 감을 못 잡았다...
 그래서 질문게시판을 이용했다. 약간의 힌트를 얻었는데,,, 마지막 문자를 확인한다는 것이였다.
 그래서 어떻게 해야하나 고민을 했는데, 누웠더니 생각이 났다.
 
 문자를 쭉 확인 하면서 스택 배열에 넣어준다.
 그런데 그 문자가 마지막 문자라면 스택 배열로 부터 폭탄 문자 까지 문자가 일치 한지 확인을 해주고
 문자가 일치한다면 현재 넣어준 push_size를 터트린 크기 만큼 줄여준다. 줄여주는 과정에서 문자를 \n으로 만들어 준다.
 그리고 그 다음 문자가 다시 폭탄 이라면 다시 반복을 해준다.
 
 이러한 과정을 거치면 길이가 0일 때, FRULA를 출력해주고
 아니라면 스택에 넣어준 문자를 출력해준다.
 
 이러한 문제를 푸는데,,,, 생각의 전환이 필요한것 같다. 나는 처음에 스택은 생각 했지만, 마지막 문자를 기준으로 문자를 터트릴 거는 생각을 못했다.
 그냥 평범한 방법으로 푼다면 시간초과가 발생하기 때문에,,, 좋은 방법을 생각하지 못했다.
 */

int main(int argc, const char * argv[]) {
    
    //문자와 폭탄문자를 입력 받는다.
    string word;
    string bomb;
    cin >> word;
    cin >> bomb;
    
    vector<char> stack;
    //배열의 크기를 문자 길이 만큼 생성해준다.
    stack.resize(word.length());
    //폭탄의 시작을 정해주는 마지막 문자만 뽑아준다.
    char check_Start = bomb[bomb.length()-1];
    //스택의 시작은 0이다.
    int push_size = 0;
    // 이 부분에서 고생 했는데 문자열의 길이를 구하는 length를 사용해서 뺏을 때, 0 보다 작게 나온다면 숫자가 깨진다는 걸 몰랐다.
    int len = bomb.length();
    
    for(int i =0 ; i< word.length(); i++){
        
        //스택에 단어를 넣어준다.
        stack[push_size] = word[i];
        
        //마지막 단어 인지 확인을 하고, 현재 스택의 길이가 단어의 길이보다 길어야한다
        if(word[i] == check_Start && push_size >= len - 1){
                
            int flag = 1;
            int temp = len;
            // 그 길이 에서 빼준 길이가 동일한지 안한지 확인해준다.
            for(int j = push_size; j> push_size - len; j--){
                temp--;
                // 만약에 다르다면 상관없으니깐, flag를 0으로 바꿔준다.
                if(stack[j] != bomb[temp]){
                    flag = 0;
                    break;
                }
                
            }
            
            if(flag == 1){
                
                int temp_size = push_size;
                // 그 문자를 초기화 해주고 push_size를 줄여준다.
                for(; push_size > temp_size - len; push_size--){
                    
                    stack[push_size] = '\n';
                }
                
                
            }
            
        }
        
        push_size++;
        
    }
    
    //cout << push_size << endl;
    
    if(push_size == 0){
        cout << "FRULA";
    }else{
    
        for(int i = 0; i<push_size; i++){
            cout << stack[i];
        }
        
    }
        
    return 0;
}
