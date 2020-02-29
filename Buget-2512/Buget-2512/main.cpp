//
//  main.cpp
//  Buget-2512
//
//  Created by yoon tae soo on 2020/02/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 
 이분 탐색 문제를 풀어봤다.
 상한성을 찾는 문제이다.
 
 일단 정렬을 해줘서 가장 큰 값을 찾는다. 이 값 보다 큰 숫자는 나올 수 없기 때문이다.
 
 찾아주고 이분 탐색을 해준다,
 
 이분 탐색을 해줄 때, 증가는 mid +1을 해주고 감소는 mid-1을 해준다,
 
 아래와 같이 해준다.
 */

vector<int> v;
int total;
int anw = 0;

void Bineary_Search(int start, int end, int N){
    
    
    while(start <= end){
        
        //중간 값을 찾는다.
        int mid = (start + end)/2;
        int temp = 0;
       // cout << temp << mid << endl;
        
        //최종값을 찾는다.
        for(int i = 0; i<N; i++){
            //현재 미드 값이 지역예산 값 보다 크다면 예산값을 temp에 넣어주고
            if(mid >= v[i]){
                temp += v[i];
            }
            //아니라면 mid 값을 temp에 넣어준다.
            else{
                temp += mid;
            }
            
        }
        
        //이렇게 하고 나서 total 값이 temp보다 크거나 같다면 상한 예산값을 증가시켜줄 수 있다는 것이므로 증가시켜준다.
        if(temp <= total){
            start = mid +1;
            // anw를 mid 값으로 갱신시켜준다.
            if(anw < mid){
                anw = mid;
            }
            
        }
        //작다면 end 값을 줄여준다.
        else if(temp > total){
            end = mid - 1;
        }
        
    }
    
    
}

int main(int argc, const char * argv[]) {
        
    int N, sum = 0;
    cin >> N;
    
    for(int i = 0; i<N; i++){
        int item;
        cin >> item;
        sum += item;
        v.push_back(item);
    }
    
    cin >> total;
    
    
        sort(v.begin(), v.end());
        Bineary_Search(0, v[N-1], N);
        cout << anw << endl;
    
    
    
    
    return 0;
}
