//
//  main.cpp
//  Path_Of_Prime_Number-1963
//
//  Created by yoon tae soo on 2020/01/17.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int Arr[10][10][10][10] = {0};
int visited[10][10][10][10] = {0};

/*
 
 */

int BFS(int i, int end){
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(i, 0));
    visited[(i/1000) % 10][(i/100) % 10][(i/10) % 10][i %10] = 1;
    
    while(! q.empty()){
        
        int num = q.front().first;
        int seq = q.front().second;
        
        if(num == end){
            return seq;
        }
        
        int a = num %10;
        int b = (num/10) % 10;
        int c = (num/100) % 10;
        int d = (num/1000) % 10;
        
        q.pop();
        
        for(int i = 0; i<10; i++){
    
            if(Arr[d][c][b][i] == 1 && visited[d][c][b][i] == 0){
                visited[d][c][b][i] = 1;
                q.push( make_pair( d*1000 + c *100 + b*10 + i, seq+1) );
            }
            
            if(Arr[d][c][i][a] == 1 && visited[d][c][i][a] == 0){
                visited[d][c][i][a] = 1;
                 q.push( make_pair( d*1000 + c *100 + i*10 + a, seq+1) );
            }
            
            if(Arr[d][i][b][a] == 1 && visited[d][i][b][a] == 0){
                visited[d][i][b][a] = 1;
                 q.push( make_pair( d*1000 + i *100 + b*10 + a, seq+1) );
            }
            
            if(Arr[i][c][b][a] == 1 && visited[i][c][b][a] == 0){
                visited[i][c][b][a] = 1;
                 q.push( make_pair( i*1000 + c *100 + b*10 + a, seq+1) );
            }
            
            
        }
    }
    
    return - 1;
}

int main(int argc, const char * argv[]) {
    
    for(int i = 1000; i<10000; i++){
        int flag = 0;
        int a = i %10;
        int b = (i/10) % 10;
        int c = (i/100) % 10;
        int d = (i/1000) % 10;
        for(int j = 2; j*j<= i;j++){
            
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            //cout << i << endl;
            Arr[d][c][b][a] = 1;
            
        }
        
    }
    int T;
    cin >> T;
    
    while(T>0){
    
        for(int d =  0; d<10; d++){
            for(int c = 0; c<10; c++ ){
                for(int b = 0; b <10; b++){
                    for(int a = 0; a <10; a++){
                        visited[d][c][b][a] = 0;
                    }
                }
            }
            
        }
        
    int A,B;
    cin >> A >> B;
    
    int anw = BFS(A,B);
    
    if(anw == - 1){
        printf("Impossible\n");
        //cout << "Impossible"<<endl;
    }
    else{
        printf("%d\n",anw);
        //cout << anw << endl;
    }
        T--;
    }
    
    return 0;
}
