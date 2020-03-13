//
//  main.cpp
//  JoyStick-Level2
//
//  Created by yoon tae soo on 2020/03/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int not_A = 0;
    
    for(int i = 0; i<name.length(); i++){
        
        if(name[i] != 'A'){
            not_A++;
        }
        
    }
    
    int current_loc = 0;
    
    while(not_A >0){
    
        
        int loc_one = 0 ;
        int loc_two = 0;
        
        //현재 위치에서 올라가는거
        int temp_loc_one = current_loc;
        
        while(name[temp_loc_one] == 'A'){
            
            temp_loc_one++;
            loc_one++;
            
            if(temp_loc_one == name.length() ){
                temp_loc_one = 0;
            }
            
        }
        
        
        //현재 위치에서 내려가는거
        int temp_loc_two = current_loc;
        
        while(name[temp_loc_two] == 'A'){
                   
            temp_loc_two--;
            loc_two++;
            if(temp_loc_two == -1){
                temp_loc_two = name.length() -1;
                }
                   
        }
        
        if(loc_one < loc_two){
            current_loc = temp_loc_one;
            answer += loc_one;
            
        }
        else{
            current_loc = temp_loc_two;
            answer += loc_two;
        }
        
        cout << name[current_loc] << " ";
        char current_word = name[current_loc];
        name[current_loc] = 'A';
        
        int one = current_word - 'A';
        int two = 'Z' - current_word + 1;
        answer += min(one, two);
        
        cout << answer << " " <<min(one, two) << endl;
        
        not_A--;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    string name;
    cin >> name;
    
    cout << solution(name);
    
    return 0;
}
