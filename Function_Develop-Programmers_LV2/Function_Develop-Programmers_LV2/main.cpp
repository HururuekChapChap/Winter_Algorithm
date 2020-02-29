//
//  main.cpp
//  Function_Develop-Programmers_LV2
//
//  Created by yoon tae soo on 2020/02/02.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 문제: 기능개발 -Lv2
 풀이시간: 12:56 - 1:21
 
 카카오블라인드 채용 Lv1을 풀고나서 이 문제를 풀려는데,,,, 난이도 차이가 너무 났다.
 Lv2가 Lv1 보다 훨씬 쉬웠다.
 방법은 간단하다. (1)100퍼 센트에서 진행 상황을 빼주고 speed로 남은 양을 나눠준다. 그리고 저장해준다.
 
 이 부분이 헷갈렸는데,
 (2)처음에 Max에 temp[0]를 넣어주고 현재 temp[i]가 MAX 보다 크다면 answer에 MAX 보다 작았던 갯수를 넣어준다.
 그리고 MAX를 temp[i]로 바꿔준다.
 */

vector<int> solution(vector<int> progresses, vector<int> speeds){
    
    vector<int> answer;
    
    vector<int> temp;
    //(1)100퍼 센트에서 진행 상황을 빼주고 speed로 남은 양을 나눠준다. 그리고 temp 저장해준다.
    for(int i=0; i<speeds.size(); i++){
        int left = 100 - progresses[i];
        int day = 0;
        
        if(left % speeds[i] == 0){
            day = left/speeds[i];
        }
        else{
            day = left/speeds[i] +1;
        }
        
        temp.push_back(day);
        
    }
    
    //(2)처음에 Max에 temp[0]를 넣어주고 현재 temp[i]가 MAX 보다 크다면 answer에 MAX 보다 작았던 갯수를 넣어준다.
    //그리고 MAX를 temp[i]로 바꿔준다.
    int MAX = temp[0];
    int cnt = 1;
   // cout << temp[0] << " ";
    for(int i = 1; i<temp.size(); i++){
        //cout << temp[i] << " ";
        if(temp[i] > MAX){
            answer.push_back(cnt);
            MAX = temp[i];
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<int> progresses;
    vector<int> speeds;
    vector<int> answer;
    
    int N;
    int item;
    cin >> N;
    for(int i=0; i<N; i++){
        
        cin >> item;
        progresses.push_back(item);
    }
    
    for(int i=0; i<N; i++){
        
        cin >> item;
        speeds.push_back(item);
    }
    
    answer= solution(progresses,speeds);
    
    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    
    
    return 0;
}
