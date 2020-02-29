//
//  main.cpp
//  Install_Router-2110
//
//  Created by yoon tae soo on 2020/02/26.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int anw;

/*
  공유기 설치 문제,,,, 요즘에 너무 머리 쓰는 일을 하기 싫어진다... 예를들어 알고리즘이라든지...
  흠 처음에 문제를 이해 할 수가 없었다.. 그래서 문제 이해 하는데 많은 시간을 사용 했고,,,
  질문 게시판을 이용했다.... 그런데,,,, 먼가 생각하는게 힘들었다.. 아이디어를 어떻게 생각해야할지,,,
  또 너무 복잡하고 하기 싫어서 생각하기도 싫었다.
  질문 게시판의 약간의 힌트를 받았지만, 깊게 생각하기 힘들어서 깊게 생각하지 못했지만, 이러한 문제도 있다는 것을 알았다.
 
  예전에 이런 비슷한 문제를 풀어본 적이 있다. 그런데, 이러한 생각을 하지 못 했다.
 
 */

void Bineary_Search(int start, int end ,int C){
    
    while(start <= end){
        
        //mid는 여기서 간격을 의미한다.
        int mid = (start + end)/2;
        
        int cnt = 1;
        int before = v[0];
        
        for(int i=1; i<v.size(); i++){
            
            int distance = v[i] - before;
            
            //간격 보다 클 경우에만 공유기를 설치해준다.
            if(distance >= mid){
                cnt++;
                before = v[i];
            }
            
        }
        
        //가장 인접한 간격 중 가장 작은 것을 찾아야하기때문에, 간격을 늘려줘야지
        if(cnt >= C){
            start = mid + 1;
            anw = mid;
        }
        //그게 아니라면 간격을 줄여준다.
        else{
            end = mid - 1;
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    int N, C;
    cin >> N >> C;
    
    for(int i = 0; i<N; i++){
        int item;
        cin >> item;
        
        v.push_back(item);
    }
    
    sort(v.begin(), v.end());
    
    int MAX = v[v.size()-1];
    
    Bineary_Search(1,MAX,C);
    
    cout << anw;

    return 0;
}
