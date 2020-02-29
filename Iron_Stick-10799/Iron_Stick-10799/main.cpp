//
//  main.cpp
//  Iron_Stick-10799
//
//  Created by yoon tae soo on 2020/02/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string word;
    cin >> word;
    
    stack<int> s;
    vector<int> v;
   
    int anw = 0;
    
    for(int i = 0; i<word.length(); i++){
        
        if(word[i] == '(' && word[i+1] != ')'){
            s.push(i);
        }
        else if(word[i] == ')' && word[i-1] != '('){
            int start = s.top();
            int cnt = 0;
            s.pop();
           
            for(int j = start ; j < i;){
                
                if(word[j] == '(' && word[j+1] == ')'){
                    cnt++;
                    j = j +2;
                }
                else{
                    j++;
                }
                
            }
            
            // cout << start << " " << i << " " << cnt <<endl;
            
            anw += cnt+1;
        
        
        }
       
        
    }
    
    cout << anw;
    return 0;
}
