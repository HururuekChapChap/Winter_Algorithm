//
//  main.cpp
//  Count_Day-1476
//
//  Created by yoon tae soo on 2020/01/10.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int E,S,M;
    int temp_E=1,temp_S=1,temp_M=1;
    int cnt = 0;
    cin >> E >> S >> M;
    
    while(true){
        cnt++;
        
        if(temp_E == E && temp_S == S && temp_M == M){
            break;
        }
        
        temp_E++;
        temp_S++;
        temp_M++;
        
        if(temp_E>15){
            temp_E=1;
        }
        
        if(temp_S>28){
            temp_S=1;
        }
        
        if(temp_M>19){
            temp_M=1;
        }
        
        
    }
    
    cout << cnt;
    return 0;
}
