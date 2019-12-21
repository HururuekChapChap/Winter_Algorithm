//
//  main.cpp
//  Turtle-2959
//
//  Created by yoon tae soo on 2019/12/21.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    //매우 당황스러웠던 문제,,,,,
    int item;
    vector<int> v;
    
    for(int i =0; i< 4;i++){
        cin >> item;
        v.push_back(item);
    }
    //정렬을 해주고
    sort(v.begin(), v.end());
    //첫번째와 그 다음 것을 곱해주면 답 ㅋㅋ
    cout << v[0] * v[2];
    
    return 0;
}
