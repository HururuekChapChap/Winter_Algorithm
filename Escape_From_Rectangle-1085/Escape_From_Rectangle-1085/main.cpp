//
//  main.cpp
//  Escape_From_Rectangle-1085
//
//  Created by yoon tae soo on 2020/01/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int x,y,w,h;
    int Arr[4];
    
    cin >> x >> y >> w >> h;
    
    Arr[0] = x;
    Arr[1] = w-x;
    Arr[2] = y;
    Arr[3] = h - y;
    
    int max = Arr[0];
    
    for(int i = 1; i<4; i++){
        
        if(max > Arr[i]){
            max = Arr[i];
        }
    }
    
    cout << max;
    return 0;
}
