//
//  main.cpp
//  Coordinate2-11651
//
//  Created by yoon tae soo on 2019/12/16.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Data{
public:
    int x;
    int y;
};

bool compare(Data v1, Data v2){
    
    if(v1.y == v2.y){
        return v1.x < v2.x;
    }
    
    return v1.y < v2.y;
    
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<Data> v;
    int N;
    int x, y;
    cin >> N;
    
    for(int i =0 ; i< N; i++){
        cin >> x >> y;
        
        v.push_back({x, y});
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i< N; i++){
        printf("%d %d \n", v[i].x , v[i].y);
    }
    
    return 0;
}
