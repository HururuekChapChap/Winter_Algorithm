//
//  main.cpp
//  Repairman_Hang-1449
//
//  Created by yoon tae soo on 2020/01/30.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double water[1001];
    double tape;
    int cnt = 1;
    int N;
    cin >> N >> tape;
    for(int i =0; i<N; i++){
        cin >> water[i];
    }
    
    sort(water, water+N);
    double len = (water[0] - 0.5) + tape;
    
    for(int i =0; i<N; i++){
        
        if(water[i] > len){
            len = (water[i] - 0.5) + tape;
            cnt++;
        }
        
    }
    
    cout << cnt;
    return 0;
}
