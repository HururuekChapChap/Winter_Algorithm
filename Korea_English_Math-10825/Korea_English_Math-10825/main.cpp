//
//  main.cpp
//  Korea_English_Math-10825
//
//  Created by yoon tae soo on 2019/12/18.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    string name;
    int kor;
    int eng;
    int math;
};

bool compare(Data v1, Data v2){
    
    if(v1.kor == v2.kor){
        
        if(v1.eng == v2.eng){
            
            if(v1.math == v2.math){
                
                // 이부분이 신기했는데, 아스키코드 순으로 정렬을 해준다. 이때, 길이도 큰거는 나중에 작은것은 먼저 해준다.
                // 처음에는 내가 이 부분을 while문을 돌려서 각 경우로 나눠서 해줬는데, 위치가 달라 질 수 있어서
                // 내가 조절하기 힘들었다. 예를 들어 정렬을 해주는데, A B로 한번 정렬 해주고
                // 다시 정렬 해줄 때 , B A로 들어 올 수 있어서 나눠 주기가 힘들었다.
                
                return v1.name < v2.name;
                
            }
            
            return v1.math > v2.math;
        }
        return v1.eng < v2.eng;
    }
    
    return v1.kor > v2.kor;
}

int main(int argc, const char * argv[]) {
    
    int N;
    int kor, eng, math;
    string name;
    vector<Data> v;

    
    
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> name >>kor >> eng >> math;
        
        v.push_back({name, kor, eng, math});
    }
     
    //합병정렬을 사용해준다.
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i< N; i++){
        printf("%s\n", v[i].name.c_str());
        //cout << v[i].name << endl;
    }
    
    return 0;
}
