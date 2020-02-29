//
//  main.cpp
//  Move-11048
//
//  Created by yoon tae soo on 2020/01/18.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

/*
 오랜만에 쉬운 DP문제를 풀었다. 행복~~ DP는 쉬운게 최고다 ㅎㅎㅎ
 간단한 DP 문제이다. 그냥 왼쪽 아래 대각선 방향으로 움직이면서
 전체를 다 탐색해주는 것이다.
 
 예를 들어
 
 1 2 3
 4 5 6
 
 이렇게 있을 때, Sum 배열에 [1][1]에 Arr[1][1]로 초기화 해준다.
 
 1,1 에서는 1,2 와 2,1 그리고 2,2 로 이동이 가능하다.
 
 그때, Sum[1][2]에는 현재 위치의 Sum값과 다음 위치 Arr[1][2]의 값을 저장해준다.
 
 즉,
 
 1 3 x
 5 6 x
 이런 식으로 된다. 그 다음 1,2에서 Sum 값을 구하는데,
 1 3 6
 4 8 9
 이렇게 된다. 이때, 2,2 의 위치는 5와 8을 비교하게 되는데, 8이 더 크니깐 2,2의 위치를 바꿔 준다.
 
*/

using namespace std;
int main(int argc, const char * argv[]) {
    
    int Arr[1002][1002];
    int Sum[1002][1002] = {0};
    int UD[3]={0,1,1};
    int LR[3]={1,0,1};
    
    int N,M;
    cin >> N >> M;
    
    for(int i =1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> Arr[i][j];
        }
    }
    
    //초기화 해준다.
    Sum[1][1] = Arr[1][1];
    
    for(int i=1; i<=N; i++){
        
        for(int j=1; j<=M; j++){
            
            for(int m=0; m<3; m++){
                
                //이동 시켜준다.
                int temp_x = j + LR[m];
                int temp_y = i + UD[m];
                
                if(temp_x>=1 && temp_x<=M && temp_y>=1 && temp_y<=N){
                        
                    //현재 위치의 Sum값과 이동할 Arr 값을 더해준다.
                   int temp = Sum[i][j] + Arr[temp_y][temp_x];
                    
                    //최소 값을 찾아준다.
                    if(temp >  Sum[temp_y][temp_x] ){
                        Sum[temp_y][temp_x] = temp;
                    }
                    
                }
                
            }
            
        }
    }
    
    cout << Sum[N][M];
    return 0;
}
