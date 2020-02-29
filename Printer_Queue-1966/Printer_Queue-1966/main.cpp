//
//  main.cpp
//  Printer_Queue-1966
//
//  Created by yoon tae soo on 2020/01/05.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a> b;
}

int main(int argc, const char * argv[]) {
    
    queue<pair<int,int>> q;
    vector<int> v;
    
    int T;
    
    cin >> T;
    
    while(T>0){
    
    int N,M,item;
    cin >> N >> M;
    
    for(int i = 0; i<N; i++){
        cin >> item;
        v.push_back(item);
        q.push(make_pair(item, i));
    }
    
    sort(v.begin(),v.end(),compare);
    
    int loc = 0;
    int anw=0;
    
    while(!q.empty()){
        
        int temp = q.front().first;
        int seq = q.front().second;
        
        q.pop();
        
        if(temp == v[loc]){
            
            anw++;
            
            if(seq == M){
                cout << anw << endl;
            }
            
            loc++;
            
        }
        else{
            q.push(make_pair(temp, seq));
        }
        
        
    }
        
        v.clear();
        
        T--;
    }
    return 0;
}
