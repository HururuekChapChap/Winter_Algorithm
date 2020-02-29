//
//  main.cpp
//  Average_Score-10039
//
//  Created by yoon tae soo on 2020/01/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int sum = 0;
    int item;
    
    for(int i = 0; i<5; i++){
        cin >> item;
        
        if(item <40){
            sum += 40;
        }
        else{
            sum += item;
        }
    }
    
    cout << sum/5;
    return 0;
}
