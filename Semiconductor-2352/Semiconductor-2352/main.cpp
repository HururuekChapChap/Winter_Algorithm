//
//  main.cpp
//  Semiconductor-2352
//
//  Created by yoon tae soo on 2020/01/20.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 이 문제,,, LIS 증가하는 부분 수열
 여러가지 방법으로 Lower_Bound를 구현 시도 해봤다.
 Lower_Bound는 탐색 했을 때, 찾고자 하는 값 보다 처음으로 이상이거나 큰 숫자를 반환해주는 것이다.
 아직 구체적으로 LIS 알고리즘을 익힌 것은 아니다.
 LIS 알고리즘은 증가하는 부분 수열의 길이를 구하는 것인데, DP로 풀 수도 있다. 하지만 DP는 N^2이라는 시간 복잡도를 가지게 되므로
 효율적이지는 못하다.
 근데, DP 방식도 쉽지는 않다.ㅎㅎㅎㅎㅎ
 
 LIS 알고리즘에서 Lower_Bound를 사용하면 현재 찾고자 하는 값과 비교를 한다. 맨 앞에 있는 값이 찾고자 하는 값 보다 더 크다면
 넣어주고 작다면, 현재 LIS를 구하는 배열에서 찾아본다. 그 중 찾고자 하는 값 보다 처음으로 큰 값을 찾아주고 바꿔준다.
 이런면 최장길이를 구하는데, 안에 요소랑은 관계가 없는데 최장 길이를 보장해주는게 아직 잘 이해는 안된다. 질문 게시판에 올렸으니
 나중에 올라오면 봐야것다.
 
 
 */

int Find_Low(vector<int> v, int start, int end ,int item){
    
    /*
    int mid = (start + end) / 2;
    
      if( start <= end ){
          
      if(v[mid] > item){
          return Find_Low(v, start, mid-1, item);
      }
      else if (v[mid] <= item){
          return Find_Low(v, mid+1, end, item);
      }
      
      }
      
      return start-1;
       */
    
    int mid = (start + end) / 2;
     
    
      if(start < end ){
      
      
      if(v[mid] >= item){
          return Find_Low(v, start, mid, item);
      }
      else if (v[mid] < item){
          return Find_Low(v, mid+1, end, item);
      }
      
      }
      
      return start;

    /*
    int m;
    while(end-start > 0)      {
        m = (start+end)/2;
        if(v[m] < item) start=m+1;
        else end = m;
        
    }
    return end;
*/
}

int main(int argc, const char * argv[]) {
    
    vector<int> v;
    vector<int> LIS;
    int N,item;
    cin>> N;
        
    for(int i = 0; i<N; i++){
        cin >> item;
        v.push_back(item);
    }
    
    LIS.push_back(v[0]);
    
    for(int i=1; i<N; i++){
        
        if(v[i] > LIS.back()){
            LIS.push_back(v[i]);
        }
        else{
            //직접 구현 한 걸로 하면 시간 초과
            int location = Find_Low(LIS, 0, LIS.size()-1, v[i]);
            
            //int location =  lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
            LIS[location] = v[i];
        }
        
    }
    
    cout << LIS.size();

   
    return 0;
}


