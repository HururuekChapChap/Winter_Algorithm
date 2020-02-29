//
//  main.cpp
//  Tomato-7569
//
//  Created by yoon tae soo on 2020/01/03.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H, anw;

int BOX[101][101][101];

int FB[6]={0,0,1,-1,0,0};
int LR[6]={0,0,0,0,1,-1};
int UD[6]={1,-1,0,0,0,0};

class Data{
public:
    int H;
    int N;
    int M;
    int day;
};

queue<Data> q;

void BFS(){
    int day = 0;
    while(!q.empty()){
        
        int h = q.front().H;
        int n = q.front().N;
        int m = q.front().M;
         day = q.front().day;
        
        q.pop();
        for(int i =0; i< 6; i++){
            
            int temp_H = h + UD[i];
            int temp_N = n + FB[i];
            int temp_M = m + LR[i];
            
            if(temp_H >=0 && temp_H < H && temp_N >=0 && temp_N < N && temp_M >=0 && temp_M < M){
                    
                if(BOX[temp_H][temp_N][temp_M] == 0 ){
                    BOX[temp_H][temp_N][temp_M] = 1;
                    q.push({temp_H,temp_N,temp_M, day+1});
                }
                
            }
            
        }
        
    }
    
    anw = day;
    
}

int main(int argc, const char * argv[]) {
    //가로 , 세로, 높이
    cin >> M >> N >> H;
    
    for(int h = 0; h< H; h++){
        
        for(int n = 0; n < N; n++){
            
            for(int m =0; m<M; m++){
                cin >> BOX[h][n][m];
         
            if(BOX[h][n][m] == 1){
                q.push({h,n,m,0});
            }
            }
            
        }
        
    }
    
    BFS();
    
    int flag = 1;
    
    for(int h = 0; h< H; h++){
           
           for(int n = 0; n < N; n++){
               
               for(int m =0; m<M; m++){
            
                   //cout << BOX[h][n][m] << " ";
                   
                   if(BOX[h][n][m] == 0 ){
                       flag = 0;
                   }
               }
               //cout << endl;
               
           }
       // cout <<endl;
           
       }
    
    
    if(flag == 0){
        cout << - 1;
    }
    else{
        cout << anw;
    }
    
    return 0;
}
