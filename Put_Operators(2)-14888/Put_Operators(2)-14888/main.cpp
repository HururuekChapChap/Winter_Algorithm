//
//  main.cpp
//  Put_Operators(2)-14888
//
//  Created by yoon tae soo on 2020/02/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

//덧셈 뺄셈 곱셈 나눗셈
int op[4];
int numbers[11];

int N;
int MIN = 1000000000;
int MAX = -1000000000;

int cnt = 0;

int calculation(int next,int sum,int op){
    
    if(op == 0){
        sum += numbers[next];
    }
    else if(op == 1){
        sum -= numbers[next];
    }
    else if(op == 2){
        sum *= numbers[next];
    }
    else{
        
        if(sum <0){
            sum = ((sum*-1) / numbers[next]) * -1;
        }
        else{
            sum = sum/numbers[next];
        }
        
    }
    
    return sum;
    
}

void DFS(int current, int sum){
    
    if(current == N-1){
        cnt++;
        if(sum > MAX){
            MAX = sum;
            
        }
        
        if(sum < MIN){
            MIN = sum;
        }
        
    }
    else{
        
        for(int i = 0;i<4; i++){
            if(op[i] >0){
                op[i]--;
                DFS(current+1,calculation(current+1,sum,i));
                op[i]++;
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i = 0; i<N;i++){
        cin >> numbers[i];
    }
    
    for(int i = 0; i<4; i++){
        cin >> op[i];
    }
    
    DFS(0,numbers[0]);
    
    
    cout << cnt << endl;
    cout << MAX << endl;
    cout << MIN << endl;
    
    
    return 0;
}
