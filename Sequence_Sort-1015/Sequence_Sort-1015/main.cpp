//
//  main.cpp
//  Sequence_Sort-1015
//
//  Created by yoon tae soo on 2019/12/19.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int num;
    int seq;
};

bool compare(Data v1, Data v2){
    
    if(v1.num == v2.num){
        return v1.seq < v2.seq;
    }
    
    return v1.num < v2.num;
}

bool compare2(Data v1, Data v2){
    return v1.seq < v2.seq;
}

int main(int argc, const char * argv[]) {
    
    
    //문제를 이해하는데 애먹었다.
    //무슨소린지 알아듣지 못해서 ㅠㅠ
    
    int N;
    cin >> N;
        
    //현재 값과 위치 값을 넣어주는 Data 클래스를 만들어주고
    vector<Data> P;
    int item;
    
    for(int i = 0; i<N; i++){
        cin >> item;
        P.push_back({item,i});
    }
    
    //그리고 숫자가 작은 수로 정렬을 해준다. 이때, 값이 동일하다면 seq값이 더 작은 쪽으로 정렬을 먼저 해준다.
    //사전순으로 앞서는 것을 출력 이라고 문제에 적혀 있기 때문이다.
    //이게 처음에 무슨 소린가 생각을 많이 했는데, index 번호를 말하는 것이였다.
    sort(P.begin(), P.end(), compare);
    
    
    // 이렇게 정렬을 해주고 나서, 이제 현재 num 값에 i 값을 넣어준다.
    // 넣어주는 이유는 num 순으로 정렬을 해줬을 때, 그게 B[i] 값으로 정렬이 된 것이다.
    // 우리가 구해야하는 것은 p[index] = i 이기 때문에 교체 해준다.
    for(int i = 0; i< N; i++){
        
        P[i].num = i;
    }
    
    // 이제 seq 순서대로 정렬을 해준다. 그러면 이제 p[index]의 index 순서대로 정렬이 된것이고
    sort(P.begin(), P.end(), compare2);
    
    // p[index] 값을 출력해준다.
    for(int i = 0; i< N; i++){
        cout << P[i].num << " ";
        
    }
    
    
    
    return 0;
}
