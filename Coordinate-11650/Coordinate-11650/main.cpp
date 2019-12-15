//
//  main.cpp
//  Coordinate-11650
//
//  Created by yoon tae soo on 2019/12/15.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int x;
    int y;
};

bool compare(Data v1, Data v2){
    
    if(v1.x == v2.x){
        return v1.y < v2.y;
    }
    
    return v1.x < v2.x;
    
}

int main(int argc, const char * argv[]) {
    
    vector<Data> v;
    
    int N;
    int itemX , itemY;
    cin >> N;
    
    for(int i = 0; i< N; i++){
        cin >> itemX >> itemY;
        v.push_back({itemX, itemY});
    }
    
    sort(v.begin(), v.end(), compare);
    
    
    for(int i = 0; i < v.size(); i++){
       // cout << v[i].x << " " << v[i].y << endl;
        printf("%d %d\n", v[i].x, v[i].y);
    }
    
    return 0;
}
