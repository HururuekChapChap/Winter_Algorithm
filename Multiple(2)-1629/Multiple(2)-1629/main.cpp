//
//  main.cpp
//  Multiple(2)-1629
//
//  Created by yoon tae soo on 2020/03/12.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

long long getMultiple(long long a, long long N, long long C){
    
    
    if(N == 0){
        return 1;
    }
    else{
        long long tempnum = getMultiple(a, N/2, C);
        printf("N: %lld 과 %lld \n",N ,tempnum);
        if(N % 2 == 0){
            return (tempnum * tempnum)%C;
        }
        else{
            
        long long tempnum = getMultiple(a, N-1, C);
            printf("N: %lld 과 %lld \n",N ,tempnum);
            return (a * tempnum )%C;
            
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    long long int a , b ,c ;
    cin >> a >> b >> c;
    
    cout << getMultiple(a, b, c);
    
    return 0;
}
