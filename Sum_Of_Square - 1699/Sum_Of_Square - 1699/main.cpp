//
//  main.cpp
//  Sum_Of_Square - 1699
//
//  Created by yoon tae soo on 2020/01/13.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 이 문제는 DP 문제인데,,, 역시 난 DP의 규칙찾기가 너무 어렵다.
 나는 간신히 통과하는 알고리즘으로 통과했다.
 
 다른 사람들은 훨씬 효율적인 알고리즘으로 풀었다. 값이 100000 이기 때문에 속도를 빠르게 하기 위해서는 제곱의 방식이 필요하다.
 현재 값이 11 이라고 했을 때, 임의의 수 x*x <= 11 일 때 까지 반복을 해준다.
 이런 상태에서
 
 현재 값 - x*x 의 값에 + 1 한 값과 현재 값과 비교해서 더 작은 값을 넣어준다.
 
 이런 방식은 너무 참신했다... 정말로 ㅎㅎㅎ
 ㅠㅠ DP는 어렵다 ㅠㅠ.
 
 내방식은 아래에 담았다.
 */

int main(int argc, const char * argv[]) {
    
    int Arr[100001] ={0};
    
    int N;
    cin >> N;
    
    int cnt = 1;
    int temp = 1;
    
    for(int i = 0; i<= 100001; i++){
        Arr[i] = 987654321;
    }
    
    //현재 값이 N 보다 같을 때 까지 반복을 돌려준다.
    while(temp <= N){
        
        //만약 1,2,3,4,5,6 이런 수의 제곱이라고 할때, 무조건 하나이다.
        if(temp == cnt*cnt){
            Arr[temp] = 1;
            cnt++;
            continue;
        }
        
        int last = 0;
        int temp_temp = temp-1;
        
        //짝수일 때와 홀수 일때로 나눠준다.
        if(temp%2 == 0){
            //절반 까지만 계산해준다. 1 2 3 4 5 라 할때, 현재 값은 6이라 하면 (1,5), (2,4), (3,3) 까지 절반만 하면 된다.
            last = temp/2;
            //절반까지만 돌려준다.
            while(temp_temp >=last){
                
                int num = Arr[temp_temp] + Arr[temp - temp_temp];
                
                //더 작다면 바꿔준다.
                if(Arr[temp] > num){
                    Arr[temp] = num;
                }
                
                temp_temp--;
            }
        }
        else{
            last = temp/2 + 1;
            while(temp_temp >=last){
                
                int num = Arr[temp_temp] + Arr[temp - temp_temp];
                
                if(Arr[temp] > num){
                    Arr[temp] = num;
                }
                
                temp_temp--;
            }
        }
        
        temp++;
    }
    
    cout << Arr[N];
    return 0;
}
