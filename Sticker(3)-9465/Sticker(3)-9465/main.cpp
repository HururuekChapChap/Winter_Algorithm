//
//  main.cpp
//  Sticker(3)-9465
//
//  Created by yoon tae soo on 2020/01/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*
     
     흠, DP 애먹었다....
     원래 DP가 약하긴 하지만,, 뭐 배워가는 느낌으로 했다.
     
     평소에 DP 문제를 아래에서 위로 탐색하는 방식으로 만 풀었는데,
     이 방식은 위에서 아래를 바라 보는 형식의 문제였다.
     
     그래서 처음에 아래에서 위로 탐색해가는 방식을 고려했었는데, 계속 틀렸다고
     나오는 것이다,, 아직 왜 틀렸는지 잘 모르겠다... 그래서 질문 게시판에 올렸으니 나중에 올라오면 봐야겠다.
    
     */
    
    int N;
    int T;
    cin >> T;
    while(T>0){
        
    int item;
    cin >> N;
    
    int v[2][100002] = {0};
    int DP[2][100002] = {0};
    
    for(int i=0; i<2; i++){
           for(int j=1; j<=N; j++){
               cin >> item;
               v[i][j] = item;
           }
       }
    
    DP[0][1] = v[0][1];
    DP[1][1] = v[1][1];
    DP[0][2] = DP[1][1] + v[0][2];
    DP[1][2] = DP[0][1] + v[1][2];
    
    for(int i = 3; i<= N; i++){
        /*
         위에서 아래를 봤을 때,
         001
         100
         
         이것도 있을 것이고
         
         101
         010
         
         이렇게 두가지 경우가 있을 것이다. 따라서 아래와 같이 해주었다.
         
         */
        DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + v[0][i];
        DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + v[1][i];
        
    }
    
    if(DP[0][N] < DP[1][N] ){
        printf("%d\n",DP[1][N]);
    }
    else{
         printf("%d\n",DP[0][N]);
    }
     
        T--;
    }
    
    return 0;
}
