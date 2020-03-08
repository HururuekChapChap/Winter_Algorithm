//
//  main.cpp
//  Press_String-Programmers_Lv1
//
//  Created by yoon tae soo on 2020/02/02.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 인생 첫 카카오블라인드 채용 문제를 풀어봤다.
 풀이시간 : Am 11:48 ~ Pm 12: 51
 
 약 한시간 만에 풀 수 있었던 문제였다.
 Lv1 문제인데,, 난이도가 쫌 높았다... 나름 생각을 필요로 하는 문제였다.
 문자열 파싱 문제인데, 완전 탐색을 해주면 된다.
 
 방법은 (1)하나 뽑았을 때, 두개 뽑 았을 때, 이렇게 증가해줘야한다.
 
 그리고 여기 부분에서 많이 헷갈렸는데, (2)뽑아야하는 문자열의 길이를 하나씩 뽑아줘서 비교를 위해 임시저장소 temp에 저장해줘야한다.

 이때, (3)temp와 그 전에 문자와 동일 할때와 동일 하지 않을 때, 이 두부분으로 나눠줘야한다.
 같다면 same를 하나 증가시켜줘야한다. 그래야 문제에 의도한 것 처럼 길이를 줄일 수 있기 때문이다.
 만약 다르다면 same이 1일 때와 아닐 때로 나눠줘서 1이라면 그냥 temp_s에 before를 넣어주고 아니라면 temp_s에
 정수형 same을 to_string 메소드로 문자열로 바꿔준다. 그리고 before를 넣어준다. 그리고 초기화 해주고
 before에 현재 temp값을 넣어준다.
 
 이런 비교를 하는 과정에서 처음 뽑을 때,before가 ""이기 때문에 시작 부터 다르다고 인식하여, temp_s에 "" 추가해주게 된다.
 따라서, (4)처음이라면 처음 뽑아야하는 개수 만큼 before에 넣어준다. 그리고 탐색을 해준다.
 
 이렇게 탐색을 끝마지고 나면 (5)마지막 문자에 대해서 추가해준다.
 예를 들어 abc라고 할때, a와 b는 해주지만 마지막 c는 temp_s에 추가해주지 않기 때문에,
 반복문을 마치고 나면 추가해준다.
 
 카카오 블라인드 채용 문제,,,, 쉽지 않았다. 이런 문자열 문제는 원래 난이도가 쫌 있는데,,
 구현을 해야할 게 많아서 많이 복잡해진다. 좀더 많이 갈고 닦아야겠다!
 */

int solution(string s) {
       int answer = 0;
       int MAX = 987654321;
        //(1) 뽑는 갯수를 하나 부터 절반 까지 해준다. 절반 이상은 굳이 해줄 필요가 없기 때문이다
       for(int i = 1; i<=s.length()/2; i++){
           int same = 0;
           string temp_s = "";
           string before = "";
           for(int j =0; j<s.length(); j = j+i){
               string temp = "";
               
               //cout << "j " << j << endl;
               
               //(4)처음이라면 처음 뽑아야하는 개수 만큼 before에 넣어준다.
               if(before == ""){
                   for(int k=0; k<i; k++){
                          before += s[k];
                   }
               }
               //(2) 뽑아야하는 문자열의 길이를 하나씩 뽑아줘서 비교를 위해 임시저장소 temp에 저장해줘야한다.
               for(int k=j; k<j+i; k++){
                   if(k == s.length()){
                       break;
                   }
                      temp += s[k];
               }
               
               //(3)temp와 그 전에 문자와 동일 할때와 동일 하지 않을 때, 이 두부분으로 나눠줘야한다.
               if(temp != before ){
                
                   if(same > 1){
                       temp_s += to_string(same)+before;
                   }
                   else{
                       temp_s += before;
                   }
                   same = 1;
                   before = temp;
               }
               else if(temp == before){
                   same++;
               }
               
           }
           
           //(5)마지막 문자를 더해준다.
           if(same > 1){
               temp_s += to_string(same)+before;
           }
           else{
               temp_s += before;
           }
           
          // cout << i <<" " << temp_s << endl;
           //비교해준다. 가장작은 것을 찾아준다.
           if(temp_s.length() < MAX){
               MAX = temp_s.length();
           }
           
       }
    
    answer = MAX;
       
       return answer;
   }

int main(int argc, const char * argv[]) {

    string s;
    cin >> s;
    cout << solution(s);
   
    return 0;
}
