//
//  main.cpp
//  Sort_Of_Age_10814
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
    int age;
    int loc;
    string name;
};

//sort
bool compare ( Data v1, Data v2){
    
    if(v1.age == v2.age){
        return v1.loc < v2.loc;
    }
    
    return v1.age <  v2.age;
    
}

//stable_sort
bool compare2(Data v1, Data v2){
    
    if(v1.age < v2.age){
        return true;
    }
    else{
        return false;
    }
    
}

int main(int argc, const char * argv[]) {
    
    vector<Data> v;
    int N;
    int age;
    string name;
    cin >> N;
    
    for(int i = 0; i< N; i++){
        cin >> age >> name;
        v.push_back({age, i ,name});
    }
    
    sort(v.begin(), v.end(), compare);
    // stable_sort(v.begin(), v.end(), compare2);
    // 같은 값이면 임의로 정렬하는 sort와 다르게 stable_sort는 compare2와 같이 선언해주면 배열에 있는 순서대로 정렬을 해준다.
    // 또한 sort는 quick sort의 알고리즘 인 반면, stable_sort는 합병정렬 merge_sort라는 장점이 있다.
    
    for(int i = 0; i< N; i++){
        //cout << v[i].age << " " << v[i].name << endl;
        printf("%d %s\n", v[i].age , v[i].name.c_str());
    }
    
    return 0;
}
