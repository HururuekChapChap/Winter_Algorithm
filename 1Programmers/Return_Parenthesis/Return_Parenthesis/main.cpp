//
//  main.cpp
//  Return_Parenthesis
//
//  Created by yoon tae soo on 2020/03/11.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

/*
 흠 다시 집중해서 보니 문제가 살짝 복잡하지만,, 문제를 잘 읽는게 중요한 문제다.
 
 일단 균현 잡힌 문자열은
 '(' 의 개수와 ')' 의 개수가 같다면 이를 균형잡힌 괄호 문자열
 즉, (와 )의 갯수가 같을 때 균형 잡힌 문자열이다.
 
 올바른 문자열은
 '('와 ')'의 괄호의 짝도 모두 맞을 경우에는 이를 올바른 괄호 문자열
 
 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다."
 이 문장을 처음 봤을때는 제 정신이 아니여서 먼 소리지 했는데, 즉 ( 과 )의 갯수가 같을 때, 분리한다는 것이다.
 
 "문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다."
 
 그리고 이렇게 분리하고 나서 올바른 문자 인지 아닌지 판별해야한다.
 처음에는 어떻게 해야 좋을지 고민을 했다.
 큐를 써야하나 스택을 써야하나 큐와 스택을 동시에 써야하나? 근데,, 잠이 왔다...
 헷갈려서 일단 잠시 놔두고
 
 다음 조건을 읽었다.
 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
 4-3. ')'를 다시 붙입니다.
 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
 4-5. 생성된 문자열을 반환합니다.
 
 즉 이걸 보면, ))()((()
 이렇게 되어 있을때, ))()((은 올바른 문자열이 아니다.
 따라서
 ( 이렇게 하고 다음 문자인 ()를 판단한다.
 ()는 올바른 문자열이라서 그대로 넣어준다. 더이상 할게 없어서 그만 둔다. 그리고 마지막에 )를 넣어준다.
 ( () ) 이렇게 하고 나서 앞 뒤 문자를 제외하고 )()( 문자를 돌린다.
 ( () ) ()() 그럼 이러한 형태로 된다.
 
 즉, 스택으로 넣어주면 된다는 것을 깨닳았다.
 
 */

string solution(string p) {
    string answer = "";
    stack<string> s;
    //(
    int close_parent = 0;
    //)
    int open_parent = 0;
    
    int start = 0;
    bool flag = true;
    for(int i = 0; i<p.size() ; i++){
        
        char word = p[i];
        //시작 점이 ) 일때만 올바르지 않은 문자열이 된다.
        if(i == start && word == ')'){
            flag = false;
        }
        
        if(word == ')'){
            close_parent ++;
        }
        else if(word == '('){
            open_parent ++;
        }
        
        //괄호의 갯수가 같다면 판단을 해준다.
        if(close_parent == open_parent){
            //올바른 문자가 아니라면
            if(flag == false){
                // ( 을 넣어준다 . 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
                answer += '(';
                // ')'를 다시 붙입니다.  u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
                // 따라서 ) 을 넣어주고
                string temp_word =")";
                //문자를 뒤집어 준다음
                for(int j = start + 1; j<i; j++){
                    
                    char temp = p[j];
                    
                    if(temp == ')'){
                        temp_word += '(';
                    }
                    else if(temp == '('){
                        temp_word += ')';
                    }
                        
                }
                //임시의 문장을 스택에 넣어줍니다.
                s.push(temp_word);
                
            }
            else{
                //올바른 문자라면 그대로 넣어줍니다.
                for(int j = start ; j<= i; j++){
                    answer += p[j];
                }
                
            }
            //판별이 끝났으면 시작 문자를 다음 문자로 바꿔줍니다.
            start = i + 1;
            flag = true;
        }
        
        
    }
    //스택의 문자를 넣어줍니다.
    while(! s.empty()){
        answer += s.top();
        s.pop();
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    
    string word;
    cin >> word;
    
    cout << solution(word);
    return 0;
}
