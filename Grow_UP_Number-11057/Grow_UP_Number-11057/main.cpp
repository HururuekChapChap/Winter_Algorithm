//
//  main.cpp
//  Grow_UP_Number-11057
//
//  Created by yoon tae soo on 2020/01/10.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*
     후우 쉽지 않았다 ㅠㅠ. 다른 사람들은 쉽게 생각 했을련지 모르겠지만 난 어려웠다.
     
     겨우겨우 생각을 했다.
     처음에는 막 곱하기 하기 별지랄지랄을 하고 그 결과를 저장해주고 다시 그 결과 값을 사용하는 이런 지랄 같은 것을 생각했지만
     결국 이게 아니였다. 계속 생각을 하고 점화식을 도출하려고 하니
     
     한자리에는 모두 하나씩 있기 때문에 10개가 나온다.
     1 1 1 1 1 1 1 1 1 1
     
     두자리에 때에는 현재 위치로 부터 쭉 위로 더한다.
     처음에 두자리 시작이 0일 때 00 01 02 03 04 05 06 07 08 09 이렇게 10개가 가능하다.
     1일 때는 11 12 13 14 15 16 17 18 19 이렇게 9개가 가능하다.
     즉, 위로 쭉 더해주는 방식으로 하는 DP 였다.
     
     */
    
    long long int Arr[1001][10]={0};
    int N;
    cin >> N;
    
    for(int i=0;i<=9;i++){
        Arr[1][i] = 1;
    }
    
    for(int i = 2; i<=N;i++){
        
        for(int j= 0; j<=9; j++){
           
            for(int k = j; k<=9; k++){
                Arr[i][j] += Arr[i-1][k]%10007;
            }
            
        }
    }
    
    long long int total = 0;
    for(int i = 0; i<=9; i++){
        total += Arr[N][i];
    }
    
    cout << total;
    return 0;
}
