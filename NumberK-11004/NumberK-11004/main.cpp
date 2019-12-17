//
//  main.cpp
//  NumberK-11004
//
//  Created by yoon tae soo on 2019/12/17.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> v;
    int N, K;
    int item;
    cin >> N >> K;
    
    for(int i = 0; i< N; i++){
        scanf("%d", &item);
        v.push_back(item);
    }
    
    sort(v.begin(), v.end());
    
    cout << v[K-1];
    return 0;
}
