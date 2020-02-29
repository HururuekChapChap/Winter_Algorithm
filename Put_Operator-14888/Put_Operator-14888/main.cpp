//
//  main.cpp
//  Put_Operator-14888
//
//  Created by yoon tae soo on 2020/02/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 
 이 문제는 단순한 순열 문제이다.
 그런데 살짝 다른 문제이기도 한데, 보통은 순열을 한다면 한줄로 쭉 된 곳에서 쭉 하나씩 보는 형식을 생각하기 쉽다.
 나도 처음에는 그런 방식으로 풀었다.
 그런데 이런 방식은 모든 경우를 다 확인하는 것이라서 10!를 넘어가면 너무 큰경우를 확인하게 된다는 문제가 생긴다.
 
 따라서 시간을 줄이기 위해서는 연산이 4개이니 각 연산자에 횟수를 담아준다.
 그리고 같은 방식으로 DFS를 들려준다.
 
 둘다 같은 DFS를 돌려주는 방식이지만, 차이는 횟수에서 난다.
 자세한 코드는 Put_Operator(2)에서 확인 할 수 있다.
 둘이 큰 차이는 존재 하지 않지만, 위와 같은 방식도 존재한다는 것을 알면 좋을 것 같다.
 */

char push[10];
int visited[10];
vector<int> v;
vector<char> operators;

int MAX = -1000000000;
int MIN = 1000000000;


void DFS(int current, int sum){
    
    if(current == sum){
        
        int total = v[0];
        for(int i=0; i<sum; i++){
            
            char cal = push[i];
            
            if(cal == '+'){
                total += v[i+1];
            }
            else if(cal == '-'){
                total -= v[i+1];
            }
            else if(cal == '*'){
                total *= v[i+1];
            }
            else{
                
                if(total <0){
                    total = ((total*-1) / v[i+1]) * -1;
                }
                else{
                    total = total/v[i+1];
                }
                
            }
            
        }
        
        if(total > MAX){
            MAX = total;
        }
        if(total < MIN){
            MIN = total;
        }
        
        //cout << total << endl;
        
    }
    else{
        for(int i=0; i<operators.size(); i++){
            if(visited[i] == 0){
                
                visited[i] = 1;
                push[current] = operators[i];
                DFS(current+1,sum);
                visited[i] = 0;
                
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int N,item,sum = 0;
    cin >> N;
    
    for(int i = 0; i<N; i++){
        cin >> item;
        v.push_back(item);
    }
    
    for(int i=0; i<4; i++){
        cin >> item;
        char command;
        sum += item;
        
        if(i==0){
            command='+';
        }
        else if(i==1){
            command='-';
        }
        else if(i==2){
            command='*';
        }
        else{
            command='/';
        }
        
        for(int j=0;j<item; j++){
            operators.push_back(command);
        }
        
    }
    
    DFS(0,sum);
    
    cout << MAX << endl;
    cout << MIN << endl;
    
    
    return 0;
}
