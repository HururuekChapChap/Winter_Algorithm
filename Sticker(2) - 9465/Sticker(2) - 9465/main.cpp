//
//  main.cpp
//  Sticker(2) - 9465
//
//  Created by yoon tae soo on 2020/01/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T>0){
    
    int N;
    int item;
    cin >> N;
        
    int temp_N = N;
        
    int v[2][100002] = {0};
    int DP[2][100002] = {0};
    
    for(int i=0; i<2; i++){
        for(int j=1; j<=N; j++){
            cin >> item;
            v[i][j] = item;
        }
    }
    
    int loc = 1;
        
        DP[0][1] = v[0][1];
        DP[1][1] = v[1][1];
        DP[0][2] = DP[1][1] + v[0][2];
        DP[1][2] = DP[0][1] + v[1][2];
    
    if(N>=3){
    
    while(loc <= N - (N%3) ){
        int plus= 0;
        
        for(int i=0; i<2; i++){
            
            if(i == 0){
                plus = 1;
            }
            else if( i== 1){
                plus = -1;
            }
            
            int A = v[(i)+plus][loc] + v[(i)][loc+1] + v[(i) + plus][loc+2];
            int B = v[(i)+ plus][loc] + v[(i)][loc+2];
            int C = v[(i) + plus][loc+1] + v[(i)][loc+2];
            
            if(DP[i+plus][loc+2] < A + DP[i][loc-1]){
            DP[i+plus][loc+2] = DP[i][loc-1] + A;
            }
            
            if(B>=C && DP[i][loc+2] < B + DP[i][loc-1]){
                DP[i][loc+2] = DP[i][loc-1] + B;
            }
            else if(C>B && DP[i][loc+2] < C + DP[i][loc-1] ){
                 DP[i][loc+2] = DP[i][loc-1] + C;
            }
            
        }
        
        loc++;
        
    }
    
    if(N%3 == 1){
        
        DP[0][loc] = DP[1][loc-1] + v[0][loc];
        DP[1][loc] = DP[0][loc-1] + v[1][loc];
        
    }
    else if(N%3 == 2){
        
        if( DP[0][loc-1] + v[1][loc] + v[0][loc+1] < DP[1][loc-1] + v[0][loc+1]){
            DP[0][loc+1] = DP[1][loc-1] + v[0][loc+1];
        }
        else{
            DP[0][loc+1] = DP[0][loc-1] +v[1][loc] + v[0][loc+1];
        }
        
        if(DP[1][loc-1] + v[0][loc] + v[1][loc+1] < DP[0][loc-1] + v[1][loc+1]){
            DP[1][loc+1] = DP[0][loc-1] + v[1][loc+1];
        }
        else{
            DP[1][loc+1] = DP[1][loc-1] + v[0][loc] + v[1][loc+1];
        }
        
        
    }
        
    }
    
        /*
        for(int i = 1; i<=N; i++){
            cout << DP[0][i] << " " << DP[1][i] << endl;
        }
         */
  
    int ANW;
    
    if(DP[0][N] < DP[1][N]){
        ANW = DP[1][N];
    }
    else{
        ANW = DP[0][N];
    }
    
        printf("%d\n",ANW);
        T--;
    }
    
    return 0;
}
