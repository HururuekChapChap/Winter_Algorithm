//
//  main.cpp
//  DNA-1969
//
//  Created by yoon tae soo on 2020/02/04.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

/*
 DNA 문제는 간단한 문제였다.
 단순한 구현 문제겸 그리디 문제였다.
 
 방법은 DNA의 글자의 길이가 동일 하기 때문에, 한 줄의 글자 하나씩 확인 해주는 것이다.
 
 예를들어,
 
 TATGATAC
 TAAGCTAC
 AAAGATCC
 TGAGATAC
 TAAGATGT
 
 이렇다고 할때, 첫번째 줄에는 T T A T T 이렇게 되어있다.
 알바벳 A-Z까지를 담는 배열 alpa에는 A는 한개 T는 4개 이렇게 되어 있다.
 그리고 갯수가 가장 많은 것을 anw에 담는다.
 
 이런 방법으로 글자의 길이 까지 반복을 해주면 된다.
 
 */

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    string DNA[1000];
    int alpa[26] ={0};
    string anw ="";
    int HD = 0;
    
    for(int i = 0; i<N; i++){
        cin >> DNA[i];
    }
    
    //글자길이 까지 반복 해준다.
    for(int i = 0; i< M; i++){
        //입력으로 주어진 글자의 갯수까지 탐색을 해준다.
        for(int j =0; j<N; j++){
            alpa[DNA[j][i] - 'A']++;
        }
        
        int MAX = 0;
        char push_alpa = '\0';
        
        //알파벳 갯수까지 확인 해준다.
        for(int j=0; j<26; j++){
            //알파벳이 가장 많이 나온 것을 찾아준다.
            if(alpa[j] > MAX){
                push_alpa = j+'A';
                MAX = alpa[j];
            }
            alpa[j]= 0;
        }
        
        //현재 글의 갯수에서 MAX 갯수를 빼준다.
        HD += N - MAX;
        //anw에 추가해준다.
        anw += push_alpa;
        MAX = 0;
        
    }
    
    cout << anw << endl;
    cout << HD;
    
    
    
    
    return 0;
}
