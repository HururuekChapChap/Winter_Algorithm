//
//  main.cpp
//  Factor-1037
//
//  Created by yoon tae soo on 2020/01/18.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> num;
    
    int N;
    int item;
    cin >> N;
    
    for(int i = 0; i<N; i++){
        cin >> item;
        
        num.push_back(item);
    }
    
    //예를 들어 16 이라고 했을 때, 16의 약수는 1,2,4,8,16 이다. 이때, 1과 16은 빠지니 2,4,8인데 정렬을 해준면 첫값과 마지막 값의
    //합이 구하고자 하는 N의 값이다 ㅎㅎ.
    sort(num.begin(),num.end());
    
    cout << num[0] * num[N-1];
    
    return 0;
}
