//
//  main.cpp
//  Sticker-9465
//
//  Created by yoon tae soo on 2020/01/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    int item;
    int Arr[2][100001];
    vector<int> v[2];
    cin >> N;
    
    v[0].push_back(0);
    v[1].push_back(0);
    
    for(int i = 0;i<2;i++){
        for(int j = 0; j<N; j++){
            cin >> item;
            v[i].push_back(item);
        }
    }
 
    int flag = -1;
    int plus;
    int loc = 1;
    int cnt = 0;
    
    while(cnt < (N /3)){
        
       
            
        int temp_plus = 0;
        int flag_plus = 0;
            
        for(int i = 1; i<3; i++){
    
            if(flag == i-1){
                continue;
            }
            
            if( i == 1){
                plus = 1;
            }
            else{
                plus = -1;
            }
            
        for(int j = 0; j<3; j++){
            
            int total = Arr[(i-1)]
            int temp = 0;
            int temp_flag = 0;
            
            if(j==0){
               temp = v[(i-1)+plus][loc] + v[(i-1)][loc+1] + v[(i-1) + plus][loc+2];
                temp_flag = (i-1) + plus;
            }
            else if(j==1){
                temp = v[(i-1)+ plus][loc] + v[(i-1)][loc+2];
                temp_flag = (i-1);
            }
            else if(j==2){
                temp = v[(i-1) + plus][loc+1] + v[(i-1)][loc+2];
                temp_flag = (i-1);
            }
            
            if(temp > temp_plus){
                flag_plus = temp_flag;
                temp_plus = temp;
                
     
            }
        
            
            cout << j << " " << temp_flag << " "<< temp_plus  <<endl;
            
        }
            
        }
        
        loc += 3;
        cnt++;
        
        cout << total << " "  <<flag << endl;
            
        }
    
    
  
    
    if(N%3 == 1){
        
        if(flag == 0){
            total += v[1][loc];
        }
        else if(flag == 1){
            total += v[0][loc];
        }
        else if(flag == -1){
            
            if(v[1][loc] > v[0][loc]){
                total += v[1][loc];
            }
            else{
                total += v[0][loc];
            }
            
        }
        
    }
    else if(N%3 == 2){
        
        int temp_A = 0;
        int temp_B = 0;
        
        if(flag == 0){
            
            temp_A = v[1][loc] + v[0][loc+1];
            temp_B = v[1][loc+1];
            
        }
        else if(flag == - 1){
            int a = v[1][loc] + v[0][loc+1];
            int b= v[1][loc+1];
            
            if(a> b){
                temp_A = a;
            }
            else{
                temp_A = b;
            }
            
            int c= v[0][loc] + v[1][loc+1];
            int d = v[0][loc+1];
            
            if(c>d){
                temp_B = c;
            }
            else{
                temp_B =d;
            }
            
        }
        else if(flag == 1){
            
            temp_A = v[0][loc] + v[1][loc+1];
            temp_B = v[0][loc+1];
        }
        
        if(temp_A > temp_B){
            total += temp_A;
        }
        else{
            total += temp_B;
        }
        
    }
    
    cout << total;
    
    
    
    return 0;
}
