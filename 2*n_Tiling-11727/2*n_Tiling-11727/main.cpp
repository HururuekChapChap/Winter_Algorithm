//
//  main.cpp
//  2*n_Tiling-11727
//
//  Created by yoon tae soo on 2020/01/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int Arr[2];
    Arr[0] = 1;
    Arr[1] = 3;
    
    int n;
    int cnt = 2;
    cin >> n;

    if(n == 1){
        cout << Arr[0];
    }
    else if(n==2){
        cout << Arr[1];
    }
    else{
        
        while(cnt != n){
            cnt++;
            
            int temp = Arr[0]*2 + Arr[1];
            Arr[0] = Arr[1];
            Arr[1] = temp % 10007;
            
        }
        
        cout << Arr[1];
    }
    return 0;
}
