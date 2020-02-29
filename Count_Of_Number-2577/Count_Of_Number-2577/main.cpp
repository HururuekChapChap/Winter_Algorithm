//
//  main.cpp
//  Count_Of_Number-2577
//
//  Created by yoon tae soo on 2020/01/07.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int Arr[10] ={0};
    int A,B,C;
    long long int sum = 1;
    cin >> A >> B >> C;
    
    sum = A * B * C;
    
    while(sum>0){
        int temp = sum % 10;
        Arr[temp]++;
        
        sum = sum / 10;
    }
    
    for(int i =0; i<10; i++){
        cout << Arr[i] << endl;
    }
    
    return 0;
}
