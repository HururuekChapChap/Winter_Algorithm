//
//  main.cpp
//  Marble_Escape-13460
//
//  Created by yoon tae soo on 2020/01/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

char map[11][11];
int visited[11][11] = {0};
int UD[4]={1,-1,0,0};
int LR[4]={0,0,1,-1};
int anw =0;

class Data{
public:
    int Rx;
    int Ry;
    int Bx;
    int By;
    int seq;
};

void BFS(int rx, int ry, int bx, int by){
    queue<Data> q;
    
    q.push({rx,ry,bx,by,0});
    
    while(!q.empty()){
        
       int Rx,Ry,Bx,By;
        
        Rx = q.front().Rx;
        Ry = q.front().Ry;
        Bx = q.front().Bx;
        By = q.front().By;
        
        int seq = q.front().seq;
        
        
        //cout << Rx << " " << Ry << " " << Bx << " " << By << " " << seq << endl;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int temp_Rx = Rx;
            int temp_Ry = Ry;
            int temp_Bx = Bx;
            int temp_By = By;
            int flag = 0;
            
            
            while(true){
                
              // cout << i << " " << temp_Rx << " " << temp_Ry << endl;
                
                if( map[temp_Ry + UD[i] ][ temp_Rx + LR[i] ] == '#'){
                    
                    if(visited[temp_Ry][temp_Rx] == 0){
                        visited[temp_Ry][temp_Rx] = 1;
                        
                        //블루도 계산
                        
                        while(true){
                                
                            if( map[temp_By + UD[i] ][temp_Bx + LR[i] ] == '#' ){
                                break;
                            }
                            else if( (temp_By + UD[i] == temp_Ry) && (temp_Bx + LR[i] == temp_Rx) ){
                                
                                
                                
                                break;
                            }
                            
                            temp_Bx = temp_Bx + LR[i];
                            temp_By = temp_By + UD[i];
                        }
                        
                       // cout << "push" << temp_Rx << " " << temp_Ry << endl;
                        q.push({temp_Rx,temp_Ry,temp_Bx,temp_By,seq+1});
                    }
                    
                    break;
                }
                else if( map[temp_Ry + UD[i] ][ temp_Rx + LR[i] ] == 'O'){
                    flag = 1;
                    
                    while(true){
                                                   
                        if( map[temp_By + UD[i] ][temp_Bx + LR[i] ] == 'O' ){
                            flag = 0;
                           break;
                        }
                        else if( map[temp_By + UD[i] ][temp_Bx + LR[i] ] == '#' ){
                           break;
                        }
                                               
                         temp_Bx = temp_Bx + LR[i];
                         temp_By = temp_By + UD[i];
                    }
                    
                   // cout << "yes" << " " << i << " " << temp_Rx << " " << temp_Ry << " "   << flag <<endl;
                    
                    if(flag == 1 && anw == 0){
                       // cout << seq << endl;
                                   anw = seq + 1;
                               }
                    
                    break;
                    
                }
         
                
                temp_Rx = temp_Rx + LR[i];
                temp_Ry = temp_Ry + UD[i];
                
            }
            
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    int Rx,Ry,Bx,By;
    
    for(int i = 0; i< N; i++){
        for(int j = 0; j< M; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 'R'){
                visited[i][j] = 1;
                Rx = j;
                Ry = i;
            }
            
            if(map[i][j] == 'B'){
                Bx = j;
                By = i;
            }
        }
    }
    
    BFS(Rx,Ry,Bx,By);
    
    if(anw == 0){
        cout <<-1 << endl;
    }
    else{
        cout << anw;
    }
    
    return 0;
}
