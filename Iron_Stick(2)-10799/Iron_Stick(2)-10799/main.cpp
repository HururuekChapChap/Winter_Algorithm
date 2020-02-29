//
//  main.cpp
//  Iron_Stick(2)-10799
//
//  Created by yoon tae soo on 2020/02/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/*
 쇠막대기 문제는 오늘 가장 이펙트가 컸던 문제였다.
 일단, 처음에는 괄호 사이에 레이저가 몇개 인지 계산을 하였는데, 이러면 시간 초과가 발생했다.
 예를 들어, (()())이렇게 된다면 1번 괄호가 6번 괄호를 만나면 1번 부터 6번까지 레이저가 몇개 인지 계산을 해준는 방식으로 했다.
 이러면 확실히 답은 맞지만 시간초과를 피할 수 없다.
 
 따라서 어떻게 해야하나 고민을 많이 했는데, 막대기를 보면 해답이 보인다고 해서 막대기를 열심히 보니 답이 나왔다.
 일단 ( ( ( ()() ) () ) ) 이렇게 되어있을때,
 ( ()() )
 이렇게는 하나이고 이것을 자르면 3개가 나온다.
 괄호를 넣어줄 때, 막대기 층이 하나 생긴다.
 따라서, 레이저가 아닐 경우에는 스택에 넣어주고 )가 보이면 빼준다.
 
 정말 간단하게 풀 수 있는 문제인데, 아이디어가 생각 안 났다.
 
 */

int main(int argc, const char * argv[]) {
    
    stack<char> s;
    string word;
    cin >> word;
    
    int anw = 0;
    for(int i = 0; i<word.length(); i++){
        
        // 괄호가 (라면 넣어준다.
        if(word[i] == '('){
            s.push('(');
        }
        //괄호가 )라면 스택에서 빼주는데, 레이저라면 현재 막대기의 갯수를 더해주고 아니라면 하나를 추가해준다.
        
        else if (word[i] == ')'){
            
            s.pop();
            
            if(word[i-1] == '('){
                anw += s.size();
            }
            else{
                anw++;
            }
            
        }
        
    }
    
    cout << anw;
    return 0;
}
