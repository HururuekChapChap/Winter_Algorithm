//
//  main.cpp
//  Repaint_Chess_Board-1018
//
//  Created by yoon tae soo on 2020/01/24.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M;
char Board[51][51];
char temp_Box[9][9];

void Check(int x, int y, int final_x, int final_y){
    
    char Start = Board[y][x];
    
    char Change;
    
    if(Start =='W'){
        Change = 'B';
    }
    else{
        Change = 'W';
    }
    
    for(int i =y; i<final_y; i++){
        for(int j =x; j<final_x; j++){
          
            
            
            
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for(int i=0; i< N; i++){
        for(int j = 0; j<M; j++){
            cin >> Board[i][j];
        }
    }
    
    
    
    
    return 0;
}
