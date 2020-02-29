//
//  main.cpp
//  Number_Of_Sum-1789
//
//  Created by yoon tae soo on 2020/02/10.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

/*
 이 문제를 해결하려고 할 때, 1 부터 만들어 보려고 했다.
 1 (1) 2(2) 3(1,2) 4(1,3) 5(1,4) 6(1,2,3) 7(1,2,4)
 이렇게 합을 구해보면 그냥 더하기의 합을 구하면 된다.
 */

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long int S;
    cin >> S;
    
    long long int sum = 0;
    long long int i;
    int flag = 0;
   
    for(i = 1; i<=S; i++){
        sum += i;
        //cout << sum << endl;
        if(sum > S){
            break;
        }
        else if( sum == S){
            flag = 1;
            break;
        }
    }
    
    if(flag == 1){
        cout << i;
    }
    else{
        cout <<i-1;
    }
    return 0;
}
