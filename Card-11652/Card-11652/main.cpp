//
//  main.cpp
//  Card-11652
//
//  Created by yoon tae soo on 2019/12/18.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<long long int> v;
    vector<pair<long long int, long long int>> cnt;
    long long int N, item, current_item, loc = 0, total = 0, number;
    
    cin >> N;
    
    //입력을 받아 준다. 이때, 입력량을 배열로 담긴 쫌 그러니 벡터로 넣어준다.
    for(int i = 0; i< N; i++){
        cin >> item;
        v.push_back(item);
    }
    
    //정렬을 해준다. 정렬을 해주고 나면 같은 숫자는 모여있게 된다.
    sort(v.begin(), v.end());
    
    //미리 하나를 넣어준다.
    current_item = v[0];
    //cnt는 숫자의 중복여부와 데이터를 저장해주는 공간이다.
    cnt.push_back(make_pair(current_item,1));
    
    //여기서 같은 숫자라면 값을 증가해주고 다르다면 push_back으로 새롭게 추가해준다.
    //loc은 계속 하나씩 증가하는데, 이유는 이미 정렬이 된 상태이기 때문에
    //지나간 숫자는 다시 볼일이 없다.
    for(int i =1; i<N; i++){
        if(current_item == v[i]){
            cnt[loc].second++;
        }
        else{
            current_item = v[i];
            cnt.push_back(make_pair(current_item,1));
            loc++;
        }
    }
    
    //여기는 가장 숫자가 많은 첫을 찾아주는 공간이다.
    for(int i=0;i<cnt.size(); i++){
        //cout << cnt[i].first << " " << cnt[i].second << endl;
        
        if(cnt[i].second > total){
            number = cnt[i].first;
            total = cnt[i].second;
        }
        
    }
    
    //출력!
    cout << number;
    
    return 0;
}
