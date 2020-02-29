//
//  main.cpp
//  Search_Document-1543
//
//  Created by yoon tae soo on 2020/02/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 
 이 문제 내가 너무 어렵게 생각 한 것 같은데,, 논리적으로는 맞았다.
 일단 문제 제시가 공백을 주어지는 것이기 때문에, getline 함수를 사용 했다.
 
 문제의 핵심은 일단, 중복 되는 것을 계산하지 않고 가장 단어가 많이 나오는 갯수를 출력하는 것이다.
 그래서 나는 일단 단어가 존재하는 위치를 모두 vectro에 저장했다. 그리고 하나씩 확인 해주는 것이다.
 
 다른 사람들은 그냥 처음 부터 시작해서 문자를 발견하면 추가해주고 이런 씩으로 간단하게 했는데,
 나는 너무 어렵게 생각한 것 같다.ㅎㅎㅎ
 
 */

int main(int argc, const char * argv[]) {
    
    
    vector<int> v;
    
    string document;
    getline(cin, document);
    
    string item;
    getline(cin, item);
    
    //문서에서 단어가 존재하는 위치를 다 찾아줘서 벡터에 저장핸다.
    for(int i=0;i<document.size(); i++){
        int cnt = 0;
        
        if(i+item.size()-1 < document.size()){
            
            int flag = 1;
        for(int j=i;  j< i+ item.size()  ; j++){
            
            if(item[cnt] != document[j]){
                flag = 0;
                break;
            }
            
            cnt++;
        }
        
        
        if(flag == 1){
            v.push_back(i);
        }
        
        }
        
    }
    
    int MAX = 0;
    
    for(int i=0; i<v.size(); i++){
        int cnt = 1;
        int location = v[i]+item.size();
        for(int j=i+1; j<v.size();j++){
            
            if(location<=v[j]){
                cnt++;
                location = v[j] + item.size();
            }
            
        }
        
        if(cnt > MAX){
            MAX = cnt;
        }
        
    }
    
    cout << MAX;
    
    
    return 0;
}
