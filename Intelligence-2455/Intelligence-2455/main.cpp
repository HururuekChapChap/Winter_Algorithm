//
//  main.cpp
//  Intelligence-2455
//
//  Created by yoon tae soo on 2020/01/03.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int total = 0;
    int MAX = 0;
    
    int up, down;
    
    
    for(int i = 0; i< 4; i++){
        cin >> down >> up;
        
        total += (-down) + up;
        
        if(total >  MAX){
            MAX = total;
        }

    }
    
     cout << MAX;
    return 0;
}
