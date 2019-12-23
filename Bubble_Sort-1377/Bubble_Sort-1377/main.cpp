//
//  main.cpp
//  Bubble_Sort-1377
//
//  Created by yoon tae soo on 2019/12/23.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//숫자와 순서를 저장해주는 Data 클래스
class Data{
    public:
    int num;
    int seq;
};

//정렬 함수
bool compare(Data v1, Data v2){
    
    //숫자가 같다면 늦게 입력된 놈을 뒤로 정렬해준다.
    if(v1.num == v2.num){
        return v1.seq < v2.seq;
    }
    
    return v1.num < v2.num;
}

int main() {
    int N,item;
    vector<Data> v;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> item;
        v.push_back({item,i});
    }
    
    sort(v.begin(), v.end(),compare);
    
    int MAX = 0;
    //정렬이 되어 있다면, 가장 값이 작은 것이 앞 쪽으로 있을 것이다.
    //그리고 현재 i 위치와 seq와 비교 해준다. 그것이 가장 큰 놈이 결국 최대로 옮겨야할 값이다.
    //10 1 2 5 9라고 할때, 정렬을 하면 1 2 5 9 10 이 된다. 1에서 정렬 1로 갈려면 1칸, 2도 한칸, 5는 1칸 9도 한칸 이다.
    //따라서 답이 2칸이 된다.
    //여기서 틀렸었는데, 처음에는 N/2로 했다.
    for(int i =0; i< N; i++){
      
        
        int temp = v[i].seq - i;
        
        if(MAX < temp){
            MAX = temp;
        }
        
    }
    
    cout << MAX + 1;
    
    return 0;
}
