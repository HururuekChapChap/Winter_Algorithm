//
//  main.cpp
//  Bipartite_Graph-1707
//
//  Created by yoon tae soo on 2020/01/10.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E;
//vector<int> v[20001];
int visited[20001][20001] = {0};

int search(){
    
    for(int i=1; i<=V; i++){
        
        int Check[20001] = {0};
        queue<int> q;
           
        for(int j=1; j<=V; j++){
            
            if(visited[i][j] == 1){
                Check[j] = 1;
                q.push(j);
            }
            
        }
        
        while(!q.empty()){
            
            int temp = q.front();
            
            q.pop();
            for(int j =1; j<=V; j++){
                
                if(j == temp){
                    continue;
                }
                
                if(Check[j] == 1 && (visited[temp][j] == 1 || visited[j][temp] == 1) ){
                    return -1;
                }
                
            }
            
        }
        
       }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T>0){
        
        for(int i = 0; i<20001; i++){
            //v[i].clear();
            for(int j =0; j<20001; j++){
                visited[i][j] = 0;
            }
        }
    
    int Vertex, Edge;
    cin >> V >> E;
    
    for(int i = 0; i<E; i++){
        cin >> Vertex >> Edge;
        
        //v[Vertex].push_back(Edge);
        //v[Edge].push_back(Vertex);
        
        visited[Vertex][Edge] = 1;
        //visited[Edge][Vertex] = 1;
        
    }
    
    int ANW = search();
    
    if(ANW == -1){
        cout <<"NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
        T--;
    }
    return 0;
}
