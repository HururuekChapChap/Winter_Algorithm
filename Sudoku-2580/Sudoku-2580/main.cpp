//
//  main.cpp
//  Sudoku-2580
//
//  Created by yoon tae soo on 2020/02/11.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 
 백트레킹 문제는 경우의 수를 제거 하고 완전탐색을 하는 방식이다.
 나는 아직 DFS 방식이 약하다. 매우 약하다.
 
 보통은 조합의 방법으로 풀었는데, 단순히 조합을 외웠기 때문에 깊은 생각을 못했던것 같다.
 이 문제를 통해서 나름 반성을 하게 된다.
 
 일단, DFS는 스택이다. 스택은 쌓이는 것이다. 따라서 다시 쌓일 수도 있는 걸 생각해야합낟.
 왜 조합을 할 때는 ,이러한 생각을 못 한건 지 모르겠다 ㅠㅠ. 그냥 했었다니 ㅠㅠ
 
 쌓아주고 반복문으로 정지 시켜주고 반복문 끝나면 뒤로 돌아가고,,, DFS는 이러한 방법이 가능하다.
 
 백트레킹은 DFS이고 DFS는 스택이고 DFS는 과거로 회기 하는 것도 가능하다는 것을 기억해 놓으면 좋을 것 같다.
 
 스도쿠 문제는 DFS를 배우는데 정말 좋은 문제인 것 같다.
 */

int map[9][9] ={0};
int lost[9][9][10] = {0};

class Data{
public:
    int x;
    int y;
};

vector<Data> v;
vector<int> visited;
int anw = 1;

int Possible(int x, int y, int item){
    
    //세로
    for(int i =0; i<9;i++){
        if(map[i][x] == item){
            return -1;
        }
    }
    
    //가로
   
    for(int j=0; j<9; j++){
                
        if(map[y][j] == item){
            return -1;
                }
            }
     
    
    //정사각형
    
    int start_x, end_x, start_y, end_y;
    
    if(y>=0 && y<3){
        start_y = 0;
        end_y = 3;
        if(x>=0 && x<3){
            start_x = 0;
            end_x= 3;
        }
        else if(x>=3 && x<6 ){
            start_x = 3;
            end_x= 6;
        }
        else if(x>=6 && x<9){
            start_x = 6;
            end_x= 9;
        }
        
    }
    else if(y>=3 && y<6){
        
        start_y = 3;
        end_y = 6;
        if(x>=0 && x<3){
            start_x = 0;
            end_x= 3;
        }
        else if(x>=3 && x<6 ){
            start_x = 3;
            end_x= 6;
        }
        else if(x>=6 && x<9){
            start_x = 6;
            end_x= 9;
        }
        
    }
    else if(y>=6 && y<9){
        start_y = 6;
        end_y = 9;
        if(x>=0 && x<3){
            start_x = 0;
            end_x= 3;
        }
        else if(x>=3 && x<6 ){
            start_x = 3;
            end_x= 6;
        }
        else if(x>=6 && x<9){
            start_x = 6;
            end_x= 9;
        }
    }
    
    for(int i = start_y ; i<end_y; i++){
        
        for(int j = start_x ; j<end_x ; j++){
           
            if(map[i][j] == item){
                return -1;
            }
        }
        
    }
    
    return 1;
}

void DFS(int current){
    
    if(current == v.size() && anw == 1){
        
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        
        anw = 0;
    
    }
    else{
        
        int x = v[current].x;
        int y = v[current].y;
        
        //cout << x << " " << y << endl;
        for(int i = 1; i<=9 && anw == 1; i++){
            
            int isPossible = Possible(x, y, i);
            
            if(isPossible == 1){
                map[y][x] = i;
                DFS(current+1);
            }
            
            map[y][x] = 0;
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                // Possible(j,i);
                v.push_back({j,i});
            }
        }
    }
 
    DFS(0);
     
    return 0;
}
