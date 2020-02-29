//
//  main.cpp
//  Body-7568
//
//  Created by yoon tae soo on 2020/01/29.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    int Arr[201][2] = {0};
    int Rank[201] = {0};
    
    cin >> N;
    
    for(int i = 0; i<N; i++){
        cin >> Arr[i][0] >> Arr[i][1];
    }
    
    for(int i=0;i<N; i++){
        
        int x = Arr[i][0];
        int y = Arr[i][1];
        int cnt = 0;
        for(int j=0; j<N; j++){
            
            if(Arr[j][0] > x && Arr[j][1] > y){
                cnt++;
            }
            
        }
        
        Rank[i] = cnt+1;
    }
    
    for(int i = 0; i<N; i++){
        cout << Rank[i] << " ";
    }
    return 0;
}
