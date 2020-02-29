//
//  main.cpp
//  Sick_Knight-1783
//
//  Created by yoon tae soo on 2020/01/28.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 
 병든 나이트 문제,,,
 흠 정말로 문제 이해를 할 수 없었다. 그리고 문제 자체가 너무 너무 애매하게 적어놨다.
 문제에서는 나이트가 방문한 모든 칸에 대해서 카우트 하라고 했지만, 나는 방문한 모든 칸을
 카운트하니깐, 답이 다르게 나왔다.
 결국 이동한 횟수로 생각하면 되는 문제였다.
 
 그렇지만 경우가 많이 나눠져 있었기 때문에, 쫌 생각 해야했다.
 높이에 따라 나눠진다. 높이가 1일 때, 2일 때, 그리고 3 이상일 때,
 이동 횟수가 4 이상일 때는, 모든 방법을 다 사용한다고 하였는데, 높이가 2일때는 두가지 방법 밖에 사용하지 못한다.
 그리고 2칸씩 이동하기 때문에, 2로 나눠준다.
 
 이상하게 오랫동안 생각한 문제였다. ㅠㅠ
 */

int main(int argc, const char * argv[]) {
    
    long long int N,M;
    cin >> N >> M;
    
    if(N == 1){
        cout << 1;
    }
    else if(N == 2){
        M = M-1;
        if(M/2 >=4){
            cout << 4;
        }
        else{
            cout << M/2 + 1;
        }
    }
    else{
        if(M==1){
            cout << 1;
        }
        else if(M == 2){
            cout << 2;
        }
        else if (M==3){
            cout << 3;
        }
        else if(M>=4 && M<7){
            cout << 4;
        }
        else{
            cout << M-7 +5;
        }
    }
    return 0;
}
