//
//  main.cpp
//  Command_Prompt-1032
//
//  Created by yoon tae soo on 2020/01/17.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    char command[51];
    int N;
    string name[51];
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> name[i];
    }
    
    for(int i=0; i<name[0].length(); i++){
        char item = name[0][i];
        int flag = 0;
        
        for(int j=1; j<N; j++){
            char temp = name[j][i];
            
            if(temp != item){
                command[i] = '?';
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            command[i] = item;
        }
        
    }
    
    cout << command;
    
    return 0;
}
