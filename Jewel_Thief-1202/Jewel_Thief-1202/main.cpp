//
//  main.cpp
//  Jewel_Thief-1202
//
//  Created by yoon tae soo on 2020/02/14.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 
 흠,, 이문제,,, 그리디 알고리즘 이였다.
 근본적인 문제 해결은 생각했지만, 시간 초과가 나올 것 같아서,, 해결책을
 생각해봐도 떠오르는 것이 없었다.
 결국 해답을 봤고,, 이해까지 완료하였다.
 
 해결 방법은 간단하다. 항상 그리디 알고리즘은 해결 방법은 간단하였지만
 그 간단한 것을 생각해내는 것이 어렵다 ㅎㅎㅎ
 
 일단 무게순으로 정렬을 가방과 보석 둘다 해준다.
 이렇게 정렬을 해주고 나면
 가방1에서의 무게는 가방2에서도 넣을 수 있다. 당연히!
 
 그런 다음 가방 1에서 담을 수 있는 모든 보석들을 담는다.
 그런데 이때, 가장 높은 보석을 끄내기 위해서는
 우선순위 큐의 가장 위에 있는 것을 찾아내면 된다.
 
 
 */

class Data{
public:
   int weight;
   int value;
};

bool compare(Data a, Data b){
    return a.weight < b.weight;
}

int main(int argc, const char * argv[]) {
    
    int N, K;
    cin >> N >> K;
    
    int weight, value;
    long long int anw = 0;
    vector<Data> jewel;
    vector<int> bag;
    
    for(int i =0; i<N; i++){
        cin >> weight >> value;
        jewel.push_back({weight, value});
    }
    
    for(int i = 0; i<K; i++){
        cin >> weight;
        bag.push_back(weight);
    }
    
    sort(jewel.begin(), jewel.end(), compare);
    sort(bag.begin(), bag.end());
    
    priority_queue<int> pq;
    int j = 0;
    
    for(int i =0; i<bag.size(); i++){
        
        while(j<jewel.size() && jewel[j].weight <= bag[i]){
            pq.push(jewel[j].value);
            j++;
        }
        
        if(!pq.empty()){
            anw += pq.top();
            pq.pop();
        }
        
    }

    cout << anw;
    
    return 0;
}
