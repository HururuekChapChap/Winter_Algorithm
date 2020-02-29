//
//  main.cpp
//  Catch_Me
//
//  Created by yoon tae soo on 2020/01/07.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int C, B;
int visited[200001][2]={0};
int loc[3]={-1,1,2};

class Data{
public:
    int B;
    int C;
    int seq;
};

int main(int argc, const char * argv[]) {
    
    cin >> C >> B;
    
    queue<Data> q;
    
    q.push({B,C,0});
    
    while(!q.empty()){
       
        int temp_B = q.front().B;
        int temp_C = q.front().C;
        int seq = q.front().seq;
        
        if(temp_B == temp_C){
            cout << seq;
            break;
        }
        
        if(temp_C >200000){
            cout << -1;
        }
        
        q.pop();
        
        for(int i = 0; i<3; i++){
            int temp;
            
            if(i == 2){
                temp = temp_B*loc[i];
            }
            else{
             temp = temp_B + loc[i];
            }
            
            if(temp >=0 && temp <= 200000 ){
            
                if(visited[temp][(seq+1)%2] == 0){
                    
                    visited[temp][(seq+1)%2] = 1;
                    
                    q.push({temp, temp_C + seq + 1, seq+1});
                    
                }
            
                
            }
            
        }
        
        
    }
    
    return 0;
}
