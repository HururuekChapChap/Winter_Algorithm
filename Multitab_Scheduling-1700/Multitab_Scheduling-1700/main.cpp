//
//  main.cpp
//  Multitab_Scheduling-1700
//
//  Created by yoon tae soo on 2020/02/01.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/*
 그리디 문제는 내가 진짜 약한 문제이다. 그리디랑 다이나믹 프로그래밍 ㅠㅠ
 많이 해도 실력이 많이 느는 것은 아닌 것 같고, 오히려 컨디션에 따라 다른 것 같다.
 그날 컨디션이 좋으면 굉장히 잘 풀리고 아닌 날은 쉬운 것도 잘 안되는 것같다.
 
 그리디 문제는 진짜 해답을 생각하지 못하면 절대 못 푸는 문제고 아래 문제가 그랬다 ㅎㅎㅎ.
 
 */

int main(int argc, const char * argv[]) {
    
    //존재 여부를 확인하기 위해서 Multitab을 만든어 준다.
    int Multitab[100] = {0};
    //언제 등장하는지 담아두기 위해서 사용하였다.
    int Check[100] = {0};
    //입력받는 수열이다.
    vector<int> seq;
    int N, M, item;
    int anw = 0;
    cin >> N >> M;
    
    for(int i = 0; i<M; i++){
        cin >> item;
        seq.push_back(item);
    }
    
    int size = 0;
    
    for(int i = 0; i<M; i++){
        
        item = seq[i];
        //현재 이미 들어가 있으면 패스
        if(Multitab[item] == 1){
            continue;
        }
        
        //현재 꽉 찬 상태가 아니라면 넣어주고 size를 증가시켜준다.
        if(size < N){
            Multitab[item] = 1;
            size++;
            
        }
        else{
            anw++;
            int MAX = 0;
            int change = 0;
            
            //현재 멀티탭에 꽃아있는 기기 중에 가장 나중에 나오는 것을 찾기 위해 현재 언제 처음 나오는지 체크해준다.
            for(int j = i; j<M; j++){
                
                if(Multitab[seq[j]] == 1 && Check[seq[j]] == 0){
                    Check[seq[j]] = j;
                }
                    
            }
            
            //가장 나중에 나오는 것을 찾아준다.
            for(int j = 0; j<100; j++){
                
                // 그런데 마지막 까지 나오지 않는 경우가 있다. 그것을 먼저 빼줘야한다.
                // ex) 2 3 2 3 1 2 4
                if(Multitab[j] == 1 && Check[j] == 0){
                    change = j;
                    break;
                }
                
                if(Check[j] > MAX){
                    MAX = Check[j];
                    change = j;
                }
                
                Check[j] = 0;
            }
            
            //멀티탭에 꽂혀 있는 것을 수정해준다.
            Multitab[change] = 0;
            Multitab[item] = 1;
            
        }
        
        
        
    }
    
    cout << anw;
    
    
    
    
    return 0;
}
