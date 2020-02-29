//
//  main.cpp
//  Scale-2437
//
//  Created by yoon tae soo on 2020/01/29.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


/*
 이문제는 생각을 전혀 할 수가 없었다.
 이런 생각을 어떻게 한건지 놀라움을 감출 수가 없었다.
 
 기본적인 틀은 현재 sum 값이 선택한 값 보다 작다면 이 숫자는 모두 만들 수 있는 수가 된다.
 그리고 크다면 만들 수 없게 된다.
 
 이런 생각을 어떻게 한거지 정말 대단하다. 그리디 문제가 쉬우면서 가장 어려운 문제 일 수도 있다 ㅎㅎㅎ.
 연습을 많이 해야한다 그리디 문제는.
 */
using namespace std;

vector<int> v;

int main(int argc, const char * argv[]) {

    int N,item;
    cin >> N;
    
    for(int i = 0; i<N; i++){
        cin >> item;
        v.push_back(item);
    }
    
    int sum = 1;
    //정렬을 해줘야 순차적으로 뽑을 수 있다.
    sort(v.begin(),v.end());
    
    for(int i = 0; i<N; i++){
        //현재 선택한 값이 sum 보다 크다면 만들 수 없기 때문에 반복을 그만한다.
        if(sum < v[i]){
            break;
        }
        //sum이 선택한 값 보다 작다면 sum에 현재 선택한 값을 더해준다.
        sum += v[i];
        
    }
    
    //sum 값을 출력해준다.
    cout << sum;
    
    return 0;
}
