//
//  main.cpp
//  coding_test-01.12-1
//
//  Created by yoon tae soo on 2020/01/12.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    int Arr[31]= {0};
       
       int cnt = 1;
       int total;
       while(cnt<n){
           
           int temp = cnt;
            total = 0;
           while(temp >0){
               
               total += temp %2;
               temp = temp / 2;
           }
           
           Arr[total]++;
           
           cnt++;
       }
       
       total = 0;
       
       while(n >0){
           total += n %2;
           n = n/2;
       }
       
    for(int i = 1; i<=30; i++){
        cout << Arr[i] << " " ;
    }
       
    return 0;
}
