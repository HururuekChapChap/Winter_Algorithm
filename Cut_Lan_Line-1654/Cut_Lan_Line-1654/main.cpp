//
//  main.cpp
//  Cut_Lan_Line-1654
//
//  Created by yoon tae soo on 2020/02/07.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 이분 탐색 문제였다. 오늘은 정말 아무 생각도 하기 싫어서 잘 풀지 못했는데,
 아이디어에서 다소 차이가 있었고 별로 문제 풀고 싶은 마음이 없었다.
 오늘은 좀 슬럼프가 심한 날이다 ㅎㅎㅎ
 
 방법은 간단하다.
 
 1 부터 가장 높은 숫자에서 쭉 탐색해주는 방식인데,
 내가 이분탐색에 대해서 연습을 많이 하지 않아, 다소 체감이 어려웠고, 깊게 생각하고 싶은 마음이 별로 없었다.
 다시 이분 탐색에 대해서 공부해 보면서 지식을 늘려가야 겠다.
 */

vector<int> v;

long long int Bineary_Search(long long int start , long long int end, int K){
    
    long long int mid = 0;
    long long int total = 0;
    long long int anw = 0;
    
    while(start <= end){
        
        //cout << start << " start " << end << endl;
        mid = (start + end)/2;
        total = 0;
        
        for(int i =0; i<v.size(); i++){
            total += v[i]/mid;
        }
        
        if(total >= K){
            start = mid +1;
            if(anw < mid){
                anw = mid;
            }
        }
        else if(total <K){
            end = mid-1;
        }
        
    }
    
    return anw;
}

int main(int argc, const char * argv[]) {
    
    int N, K;
    cin >> N >> K;

    for(int i = 0; i<N; i++){
        int item;
        cin >> item;
        v.push_back(item);
    }
    
    sort(v.begin(), v.end());
    
    long long int low = 1;
    long long int hight = v[N-1];
    
    cout << Bineary_Search(low,hight,K);
    
    
    
    return 0;
}
