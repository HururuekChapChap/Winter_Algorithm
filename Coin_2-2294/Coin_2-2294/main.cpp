//
//  main.cpp
//  Coin_2-2294
//
//  Created by yoon tae soo on 2020/01/17.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 
 언제나 어려우 DP ㅠㅠ
 어제 시도 할려고 했으나,, 어려워서 하지 못했다. 그래서 다른 사람의 알고리즘을 보고 아하 이렇게 푸는 구나
 라고 생각하고 하루 자고 다시 풀었는데, 풀이가 완벽하게 생각 나지는 않아서 기초적인 틀만 가지고 생각을 했다.
 
 결국 풀이가 다르긴 했지만, 만족은 한다,
 
 일단 방식은 비슷하다.
 1 2 3 4 5 6 7
 이 있다고 할때, 1로 1을 만드는 방법은 1 - 1 방법 밖에 존재 하지 않는다.
 다만 3은 1+2이 존재한다. 4는 1+3, 2+2 이런 방법도 존재한다. 5는 1+4, 2+3 이렇게 두 경우가 존재하낟.
 이때, 각 경우에 대해서 모든 최소 값들을 정해주게 된다. 따라서 위와 같은 방법이 가능해지는 것이다.
 
 이러한 방법은 저번에도 한번 풀어본 것 같다.
 다른 사람과 풀이 방식은 살짝 다르지만, 이런 식으로 푸는 것은 비슷핟.
 
 DP에서 최소값은 그 다음의 최소값으로 이루어지는 문제가 많은 것 같다.
 
 */

int main(int argc, const char * argv[]) {
    
    int Point[100001];
    
    int n,k;
    int item;
    cin >> n >> k;
    
    for(int i=1;i<100001; i++){
        Point[i] = 100001;
    }
    
    for(int i =0; i< n; i++){
        cin >> item;
        Point[item] = 1;
    }
    
    
    
    for(int i =1; i<=k; i++){
        for(int j=1; j<=i/2; j++){
            
            int temp = Point[j] + Point[i - j];
            
            if(temp > 100001){
                temp = 100001;
            }
            
            if(temp < Point[i]){
                Point[i] = temp;
            }
            
            
        }
        
    }
    
    /*
    for(int i = 1; i<=k; i++){
        cout << Point[i] << " ";
    }
     */
    
    
    if(Point[k] >= 100001){
        cout << -1;
    }
    else{
        cout << Point[k];
    }
    
    return 0;
}
