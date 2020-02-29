//
//  main.cpp
//  Divid_Sum-2231
//
//  Created by yoon tae soo on 2020/01/23.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    int anw = 987654321;
    
    for(int i = 1 ; i <=N; i++){
        int temp = i;
        int total = i;
        while(temp>0){
            total += temp % 10;
            temp = temp/10;
        }
        
        
        if(total == N){
           
            if( anw > i ){
                anw = i;
            }
            
        }
        
    }
    
    if(anw == 987654321 ){
        cout << 0;
    }
    else{
    cout << anw;
    }
    return 0;
}
