//
//  main.cpp
//  Start_And_Link-14889
//
//  Created by yoon tae soo on 2020/02/10.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 조합 문제였다. 근데 단순하게 일렬로 된 조합 문제가 아니라, 조합을 해서 거기서 좀 더 나아가는 문제였다.
 
( 1,1 ) ( 1,2 ) ( 1,3 )  ( 1,4 )
( 2,1 ) ( 2,2 ) ( 2,3 )  ( 2,4 )
( 3,1 ) ( 3,2 ) ( 3,3 )  ( 3,4 )
( 4,1 ) ( 4,2 ) ( 4,3 )  ( 4,4 )
 
 라고 했을 때, 1,3 이 스타터 라고 하면 2,4는 링크 팀이다.
 
 ( 1,1 ) ( 1,2 ) ( star )  ( 1,4 )
 ( 2,1 ) ( 2,2 ) ( 2,3 )  ( link )
 ( star ) ( 3,2 ) ( 3,3 )  ( 3,4 )
 ( 4,1 ) ( link ) ( 4,3 )  ( 4,4 )
 
 아래와 같이 이중포문으로 다시 검사해주면 된다.
 
 실수 했던 부분이 index를 잘 못 했었다.
 
 */

int map[21][21];
int temp_map[21][21];
int visited[21] = {0};

int anw = 987654321;


void DFS(int current, int index ,int MAX){
    
    if(current == MAX/2){
        
        int Start = 0;
        int Link = 0;
        int temp = 0;
        
        for(int i = 1; i<=MAX; i++){
            for(int j = 1; j<=MAX; j++){
                
                if(visited[i] == 1 && visited[j] == 1){
                    temp_map[i][j] = 1;
                    Start += map[i][j];
                }
                else if(visited[i] == 0 && visited[j] == 0){
                    temp_map[i][j] = 2;
                    Link += map[i][j];
                }
                
            }
        }
        
        if(Start >= Link){
            temp = Start - Link;
        }
        else{
            temp = Link -Start;
        }
        
        if(anw > temp){
            anw = temp;
        }
        
        
        /*
        cout << endl;
        for(int i = 1; i<=MAX; i++){
            cout << visited[i] << " ";
        }
        cout << endl;
        cout << endl;
        
        for(int i = 1; i<=MAX; i++){
            for(int j = 1; j<=MAX; j++){
                       
                cout << temp_map[i][j] << " ";
                temp_map[i][j] = 0;
                   }
            cout << endl;
               }
        cout << endl;
        */
        
    }
    else{
        
        for(int i = index; i<=MAX; i++){
            
            if(visited[i] == 0){
                visited[i] = 1;
                DFS(current+1, i+1 , MAX);
                visited[i] = 0;
            }
            
        }
        
    }
    
}


int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    for(int i = 1; i<=N; i++ ){
        for(int j = 1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    
    DFS(0,1,N);
    
    cout << anw;
    
    return 0;
}
