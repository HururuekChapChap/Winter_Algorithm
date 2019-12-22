//
//  main.cpp
//  Serial_Number-1431
//
//  Created by yoon tae soo on 2019/12/22.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int len;
    int total;
    string name;
};

//정렬방식
bool compare (Data v1, Data v2){
    
    if(v1.len == v2.len){
        
        if(v1.total == v2.total){
            return v1.name < v2.name;
        }
        
        return v1.total < v2.total;
        
    }
    
    return v1.len < v2.len;
    
}

int main(int argc, const char * argv[]) {
    
    vector<Data> v;
    
    int N;
    string item;
    cin >> N;
    
    for(int i = 0; i< N; i++){
        cin >> item;
        int total = 0;
        int len = item.length();
        //숫자의 합을 계산 해준다.
        for(int j = 0; j< item.length(); j++){
            if(item[j] - '0' >=0 && item[j] - '0' <=9){
                total += item[j] - '0';
            }
        }
        
        //그리고 넣어준다.
        v.push_back({len, total, item});
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i =0; i< N; i++){
        cout << v[i].name << endl;
    }
    
    return 0;
}
