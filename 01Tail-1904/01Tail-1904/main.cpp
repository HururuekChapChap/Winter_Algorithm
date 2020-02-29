//
//  main.cpp
//  01Tail-1904
//
//  Created by yoon tae soo on 2020/01/20.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int Arr[1000001]= {0};
    
    Arr[1] = 1;
    Arr[2]= 2;
    
    
    int N;
    cin >> N;
    
    for(int i=3; i<=N; i++){
        Arr[i] = (Arr[i-1] + Arr[i-2])%15746;
    }
    
    cout << Arr[N];
    return 0;
}
