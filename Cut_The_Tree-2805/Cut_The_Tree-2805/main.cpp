//
//  main.cpp
//  Cut_The_Tree-2805
//
//  Created by yoon tae soo on 2020/01/28.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 이 문제는, 생각을 꽤 많이 했다.
 어떻게 하면 빠른 시간 안에 풀 수 있을지,,,
 
 일단 입력 받고, 그것을 정렬 해준다.
 정렬 해주는 이유는 DP를 만들어 주기 위해서다
 
 예를 들어 10 15 17 20 이라고 할때,
 
 17과 20은 3 차이가 난다. 그것을 DP에 저장해준다.
 15와 17은 2 차이가 난다. 그리고 20도 2를 더 자를게 된다.
 10과 15는 5 차이가 난다. 그러면 17과 20에 5를 더 늘려줘야한다.
 
 이렇게 본다면 뒤에 갯수에 따라서 증가하는 양이 늘어난다.
 17은 뒤에 20이 하나라서 한번만 증가시켜주고
 15는 뒤에 17과 20이 두개라서 두번 증가시켜주고
 이런 식으로 DP에 저장이 된다.
 
 DP에 저장이 완료 된다면, 현재 탐색하고자 하는 가져갈 나무의 값을 처음으로 넘는 위치를 찾는다.
 그리고 처음 넘는 값과 탐색하고자 하는 값을 빼주고, 뒤에 나무 객수로 나눈 몫 만큼 증가시켜주면 답이다.
 
 생각하는데 시간이 꽤 걸렸고, 합하는 과정에서 int 값을 넘기 때문에, long long int로 해줘야한다.
 */

int main(int argc, const char * argv[]) {
    
    //입력 받는다.
   long long int N, M;
    cin >> N >> M;
    
    int item;
    vector<int> v;
    vector<long long int> DP;
    //맨 밑 바닥일때,를 추가해준다.
    DP.push_back(0);
    v.push_back(0);
    //나무의 높이를 입력받는다.
    for(int i=0; i<N; i++){
        cin >> item;
        v.push_back(item);
    }
    
    //정렬해준다.
    sort(v.begin(),v.end());
    //뒤의 나무 갯수를 1로 초기화 해준다.
    int cnt = 1;
    //맨 뒤의 나무는 해줄 필요가 없기 때문에, 뒤에서 두번째 나무 부터 해준다.
    for(int i = v.size()-2; i>=0; i--){
        
        //현재 나무 보다 큰 뒷 나무에서 현재 나무의 높이를 빼준다.
        long long int length = v[i+1] - v[i];
        
        //그 전에 길이에서 나무갯수에 증가하는 길이를 더해준다.
        DP.push_back(DP[cnt-1] + length*cnt);
       
        cnt++;
    }
   
    
    //현재 탐색하고자 하는 가져갈 나무의 값을 처음으로 넘는 위치를 찾는다.
    int D_loc = lower_bound(DP.begin(), DP.end(), M) - DP.begin();
    int loc = v.size() - 1 - (lower_bound(DP.begin(), DP.end(), M) - DP.begin());
    
    //처음 넘는 값과 탐색하고자 하는 값을 빼주고, 뒤에 나무 객수로 나눈 몫 만큼 증가시켜준다.
    long long int upgrade = (DP[D_loc] - M) / (v.size()-1 - loc);
    
    cout << v[loc] + upgrade;
    
    return 0;
}
