//
//  main.cpp
//  Stick-1094
//
//  Created by yoon tae soo on 2020/01/03.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int X;
    cin >> X;
    
    int stick = 64;
    int total = 0;
    int sum = 1;
    
    if(X == 64){
        cout << 1;
    }
    else{
    
    while(stick >0){
        
        int temp = stick/2;
        
        if(temp + total < X){
            total += temp;
            sum++;
        }
        else if(temp + total == X){
            
            break;
        }
       
        
        stick /= 2;
        
    }
     
        cout << sum ;
        
    }
    
    return 0;
}
