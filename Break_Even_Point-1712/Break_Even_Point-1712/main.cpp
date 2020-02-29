//
//  main.cpp
//  Break_Even_Point-1712
//
//  Created by yoon tae soo on 2020/01/17.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int A, B ,C;
    cin >> A >> B>> C;
    
    int temp = C - B;
    
    if(temp<=0){
        cout << -1;
    }
    else{
        cout << A/temp + 1;
    }
    
    return 0;
}
