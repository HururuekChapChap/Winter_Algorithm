//
//  main.cpp
//  OlyPic-8979
//
//  Created by yoon tae soo on 2020/02/24.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int num;
    int gold;
    int silver;
    int copper;
};

bool compare (Data a1, Data a2){
    
    if(a1.gold == a2.gold){
        
        if(a1.silver == a2.silver){
            
            return a1.copper > a2.copper;
        }
        
        return a1.silver > a2.silver;
    }
    
    return a1.gold > a2.gold;
}

int main(int argc, const char * argv[]) {
    
    int N, K;
    vector<Data> v;
    cin >> N >> K;

    int num , gold, silver, copper;
    
    for(int i = 0; i< N; i++){
        cin >> num >> gold >> silver >> copper;
        
        v.push_back({num, gold, silver, copper});
    }
    
    sort(v.begin(), v.end(), compare);
    
    int current = 1;
    int g = v[0].gold, s = v[0].silver, c = v[0].copper;
    
    for(int i = 0; i< N; i++){
        
        if(v[i].gold != g || v[i].silver != s || v[i].copper != c ){
            
            g = v[i].gold;
            s = v[i].silver;
            c = v[i].copper;
            
            current = i + 1;
        }
        
        
        if(v[i].num == K){
            cout << current;
        }
        
       
        
    }
    
    return 0;
}
