//
//  main.cpp
//  Roll_Dice-14499
//
//  Created by yoon tae soo on 2020/02/04.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 주사위 문제,,, 이거 X 와 Y의 위치가 이상해서 틀렸다.
 물론 처음 틀렸을 때는 틀린 이유가 있었다.
 
 일단 처음에 현재 바닥의 숫자를 수정해주고 돌려주는 식으로 했었다.
 그럴경우 잘 못 된 숫자가 바닥에 붙은 상태에서 돌려지기 때문에 잘 못 된 결과 값이 나올 수 있다.
 
 따라서 일단 돌려주고 붙여 주는 형식으로 해주야한다. 신박한 문제라서 많이 당황했다.
 정육면체에 대한 표현을 어떻게 해줘야 하나 고민 했었는데, 그냥 북쪽면, 남쪽면, 동쪽면, 서쪽면, 윗면, 바닥면
 이렇게 나눠져서 표현 해주면 된다.
 */

int main(int argc, const char * argv[]) {
    
    int N, M, X, Y, K;
    //지도
    int Arr[22][22] = {0};
    //정육면체의 면
    int up = 0, down = 0, right = 0, left = 0, ceil = 0, floor = 0;
    //이동방법
    int UD[4] = {0,0,-1,1};
    int LR[4] = {1,-1,0,0};
    
    cin >> N >> M >> Y >> X >> K;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> Arr[i][j];
        }
    }
    
    int move = 0;
    //임시변수-> 이동할 때는 4면만 이동 하게 된다.
    int temp_ceil;
    int temp_right;
    int temp_left;
    int temp_floor;
    
    for(int i=0; i<K; i++){
        
        cin >> move;
        
        //이동이 지도를 넘어가지 않게 해준다.
        if(X+LR[move-1] >=0 && X+LR[move-1] <M && Y +UD[move-1] >=0 && Y +UD[move-1] <N){
            
            //cout << " location " << X << " " << Y << endl;
            
            //동쪽으로 이동 (윗면,바닥면,동쪽면, 서쪽면)만 이동
        if(move == 1){
            
            temp_ceil = ceil;
            temp_right = right;
            temp_left = left;
            temp_floor = floor;
            
            ceil = temp_left;
            right = temp_ceil;
            floor = temp_right;
            left = temp_floor;
            
        }
             //서쪽으로 이동 (윗면,바닥면,동쪽면, 서쪽면)만 이동
        else if(move ==2){
            
            temp_ceil = ceil;
            temp_right = right;
            temp_left = left;
            temp_floor = floor;
            
            ceil = temp_right;
            right = temp_floor;
            floor = temp_left;
            left = temp_ceil;
            
        }
             //북쪽으로 이동 (윗면,바닥면,북쪽면, 남쪽면)만 이동
        else if(move == 3){
            
            temp_ceil = ceil;
            temp_right = down;
            temp_left = up;
            temp_floor = floor;
                       
            ceil = temp_right;
            up = temp_ceil;
            floor = temp_left;
            down = temp_floor;
            
        }
             //남쪽으로 이동 (윗면,바닥면,북쪽면, 남쪽면)만 이동
        else{
            
            temp_ceil = ceil;
            temp_right = down;
            temp_left = up;
            temp_floor = floor;
            
            ceil = temp_left;
            down = temp_ceil;
            floor = temp_right;
            up = temp_floor;
            
        }
            //돌려주고 이제 이동해준다.
            X = X+ LR[move-1];
            Y = Y + UD[move-1];
                   
            //바닥면에 붙여준다.
            if(Arr[Y][X] == 0){
                       Arr[Y][X] = floor;
                   }
            else{
                floor = Arr[Y][X];
                Arr[Y][X] = 0;
                   }
            
            
           // cout << ceil << " " << floor << " " << left << " " << right << " " << up << " " << down << endl;
            cout << ceil << endl;
        
        
        }
        
        
        
    }
    
    
    
    return 0;
}
