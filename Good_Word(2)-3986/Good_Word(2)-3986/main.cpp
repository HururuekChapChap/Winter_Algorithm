//
//  main.cpp
//  Good_Word(2)-3986
//
//  Created by yoon tae soo on 2020/02/27.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/*
 이 문제를 너무 어렵게 생각했다.... 일단 스택을 사용해야 할 것 같았는데,,, 너무너무 어렵게 생각했다.ㅋㅋㅋㅋ
 일단 설명을 굉장히 어렵게 해놨기 때문에 어렵게 생각한 것 같다.
 
 처음에는 swift 복습용으로 풀기로 맘 먹었다. 그러는 과정에서 많은 오류를 발견했는데, 내가 방향을 잘못 잡았다.
 
 if(j<len-1 && chr == word[j+1]){
     j += 2;
     continue;
 }
 
 처음에는 이 부분이 잘못된 부분인 줄 알았다. 왜냐하면 내가 체크를 할 때, ABAABA라고 할때,
 ABA에서 앞 부분에 A가 존재하기 때문에 break를 해서 탐색을 중지하도록 하였다. 따라서 저 코드를 먼저 줘서 앞에 있는 A를 먼저 탐색하도록
 했다.
 
 그런데 사실은
 
 if(stack.contains(chr) == true){
        flag = false;
        break;
    }
 
 이 부분이 잘못 된 것이였다.
 
 왜냐하면
 ABAB라고 한다면 서로 교차 되어서 잘못된 것을 빠르게 판단해줄 수 있지만
 ABABBABA 라고 한다면 교차가 되지 않고 해결될 수도 있었다.
 
 내가 확실히 잘못 생각했다.
 이 문제는 그냥 스택을 넣고 빼고 하는 단순한 문제엿는데, 너무 복잡하게 생각해버렸따 ㅠㅠ. 충분히 쉬운문제로 출제될 가능성이 높은 문제이다.
 
 */

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    string word;
    
    int anw = 0;
    for(int i = 0; i<N; i++){
        cin >> word;
        
        stack<char> stacks;
        int len = word.length();
        int j = 0;
        while(j < len){
            
            char chr = word[j];
            
            if(j<len-1 && chr == word[j+1]){
                j += 2;
                continue;
            }
            //비었으면 넣어준다.
            if(stacks.empty()){
                stacks.push(chr);
            }
            else{
                
                char pop_chr = stacks.top();
                //현재 스택에 최상단에 있는 값과 같은지 확인한다.
                if(chr == pop_chr){
                    stacks.pop();
                }
                //아니면 스택에 넣어준다.
                else{
                    stacks.push(chr);
                }
            }
            
            j += 1;
        }
        
        if(stacks.empty()){
            anw++;
        }
        else{
            while(! stacks.empty()){
                stacks.pop();
            }
        }
        
    }
    
    cout << anw;
    
    
    return 0;
}
