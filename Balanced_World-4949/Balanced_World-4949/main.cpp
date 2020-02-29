//
//  main.cpp
//  Balanced_World-4949
//
//  Created by yoon tae soo on 2020/02/07.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/*
 스택 문제로 풀었다.
 어렵지 않았다.
 방법은 (와 [가 나오면 스택에 넣고 )가 나오면 (이 스택에서 매칭 되어야하고
 ]가 나오면 [이 매칭 되어야 한다.
 
 스트링에 한줄로 띄어 쓰기 까지 받기 위해서는 getline이라는 함수를 사용해야한다.
 
 오늘은 뭔가 다소 생각하기 싫어서 문제 푸는데 깊은 생각을 할 수가 없었다.
 */

int main(int argc, const char * argv[]) {
    
    string word;
    stack<char> s;
    
    while(true){
    
        while(!s.empty()){
            s.pop();
        }
        
    getline(cin, word);
        
        if(word == "."){
            break;
        }
    
    int flag = 1;
    
    for(int i = 0; i<word.length(); i++){
        
        char item = word[i];
        char temp;
       // cout << item << " ";
        
        if(item == '(' || item == '['){
            s.push(item);
        }
        else if(item == ')'){
            
            if(s.empty()){
                flag = 0;
                break;
            }
            
            temp = s.top();
            //cout << temp << endl;
            s.pop();
            
            if(temp != '('){
                flag = 0;
                break;
            }
            
        }
        else if(item == ']'){
            
            if(s.empty()){
                flag = 0;
                break;
            }
            
            temp = s.top();
           // cout << temp << endl;
            s.pop();
            
            if(temp != '['){
                flag = 0;
                break;
            }
            
        }
         
        
        
    }
    
    if(flag == 1 && s.empty()){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
        
    }
    return 0;
}
