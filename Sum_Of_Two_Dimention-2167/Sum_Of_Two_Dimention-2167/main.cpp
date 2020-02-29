//
//  main.cpp
//  Sum_Of_Two_Dimention-2167
//
//  Created by yoon tae soo on 2020/01/14.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;
/*
 
 이 문제 어렵다...
 나는 그냥 완전탐색 방식으로 풀었는데,,, 이걸 DP로 푼다고??? 생각을 했다.
 아 쉽지 않다.. 겨우겨우 이해 했다.
 
 https://lmcoa15.tistory.com/14
 
 위 링크가 문제에 대한 해설이다.
 
 위의 문제를 본다면 일단 문제를 이해하면 무조건 사각형의 합을 구하게 된다.
 따라서 구간의 합을 일단 구해줘야한다.
 
 a-b
 | |
 c-d
 
 라고 했을 때, d의 넓이를 구할 때, c와 b가 무조건 들어가야한다. 이때, a는 겹치니 빼준다.
 이렇게 하면 각 구간의 합이 나오게 되고
 
 이거 부분의 합을 구하기 위해서는 뭔가 처음 보는 이론을 알아야한다.
 
 ㅋㅁㅁㅅ
 ㅁㄷㅇㅇ
 ㅁㅇㅇㅇ
 ㅊㅇㅇㅈ
 
 만약 2,2(ㄷ) 에서 4,4(ㅈ) 위치 까지의 합을 구하기 위해서는
 1,4(ㅅ)의 위치값과 4,1(ㅊ)의 위치 값을 빼주고 1,1(ㄷ)의 값을 두번 빼주게 되니 더해준다.
 
 즉, DP[i][j]에서 DP[i][x-1]의 값과 DP[y-1][j]을 빼주고 DP[y-1][x-1]를 더해준다.
 
 */

int main(int argc, const char * argv[]) {
    
    int N ,M;
    int Arr[302][320] = {0};
    cin >> N >> M;
    
    for(int i = 1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> Arr[i][j];
        }
    }
    
    int T;
    int i,j,x,y;
    cin >> T;
    while(T>0){
        //cin >> i>> j >> x >> y;
        scanf("%d %d %d %d",&i,&j,&x,&y);
        int total = 0;
        for(int a = i; a <= x; a++){
            for(int b = j; b<=y; b++){
                total += Arr[a][b];
            }
        }
        printf("%d\n",total);
        //cout << total << endl;
        T--;
    }
    
    return 0;
}
