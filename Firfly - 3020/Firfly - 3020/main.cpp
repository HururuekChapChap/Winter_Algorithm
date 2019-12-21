//
//  main.cpp
//  Firfly - 3020
//
//  Created by yoon tae soo on 2019/12/21.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    int height;
    int cnt;
};

int section[500002] = {0};
int section2[500002] = {0};

int main(int argc, const char * argv[]) {
    
    // 가로, 높이, 입력값
    int N, H, item;
    
    // 아래 부분 석수
    vector<int> v1;
    // 윗 부분 종류석
    vector<int> v2;
    
    // 높이와 갯수를 저장 해줄 Data 클래스
    // 아래 부분 석수의 정보를 담아주는 temp1
    vector<Data> temp1;
    // 윗 부분 종류석의 정보를 담아주는 temp2
    vector<Data> temp2;
    
    cin >> N >> H;
    
    //홀수면 석수 v1에 넣어주고 짝수면 종료수 v2에 넣어준다.
    for(int i = 1; i<=N; i++){
        cin >> item;
        if(i % 2 == 0){
            v2.push_back(item);
        }
        else{
            v1.push_back(item);
        }
    }
    
    // 정렬을 해준다. 정렬을 해주는 이유는 같은 길이는 모여 있을 것이고
    // 낮은 쪽은 아래 쪽에 높은 쪽은 윗 쪽에 모여 있을 것이기 때문이다.
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    // 정렬을 된 것에 높이 별로 정보를 temp1에 담아준다.
    // 어차피 정렬된 상태이기 때문에 loc의 위치는 하나씩 올려주면 된다.
    int current = v1[0];
    int loc = 0;
    temp1.push_back({current, 1});
    
    for(int i=1; i<v1.size(); i++){
        
        //달라지면 바꿔주고
        if(v1[i] > current){
            loc++;
            current = v1[i];
            temp1.push_back({current,1});
        }
        //같다면 cnt 갯수를 증가시켜준다.
        else if(v1[i] == current){
            temp1[loc].cnt++;
        }
        
    }
    
    // temp2도 마찮가지이다.
    current = v2[0];
    loc=0;
    temp2.push_back({current,1});
    
    for(int i=1; i<v2.size(); i++){
           
           if(v2[i] > current){
               loc++;
               current = v2[i];
               temp2.push_back({current,1});
           }
           else if(v2[i] == current){
               temp2[loc].cnt++;
           }
           
       }
    
    // 이제 구역 별로 정보를 넣어준다.
    // 여기에 DP 방식이 사용 됐는데, 높이가 더 높다면 결국 아래쪽도 영향을 받게 된다.
    // 따라서 낮은 곳은 높은 곳의 갯수를 이어서 받는다.
    int total = 0;
    for(int i = temp1.size() - 1; i >= 0; i--){
       // cout << temp1[i].height << " " << temp1[i].cnt << " ";
        
        total += temp1[i].cnt;
        
        section[temp1[i].height] = total;
    }
    
    //cout << endl;
    
    total = 0;
    
    // 이것도 마찮가지 인데,,,, 종료석은 좀더 생각을 필요로 했다,
    // 일단 위에서 아래로 내려 오기 때문에 전체 높이에서 종료석이 내려 온 곳에서 -1을 해준다.
    // 이 친구도 마찮가지로 낮은 쪽은 높은 쪽의 갯수를 이어서 받는다.
     for(int i = temp2.size() - 1; i >= 0; i--){
          //cout << temp2[i].height << " " << temp2[i].cnt << " ";
          
          total += temp2[i].cnt;
          
          section2[ H - (temp2[i].height - 1) ] = total;
      }
    
    // cout << endl;
    
    // 본격적으로 구간 별로 계산을 해준다.
    // 여기가 가장 까다로웠다 ㅠㅠ.
    // 일단 저 위에 처럼 종료석의 높이 별로 나눠주면 높이가 있는 구간에만 넣어주게 됀다.
    // 즉, 높이 3과 5가 입력 받아졌을 때, 높이 3, 높이 5 종료석에는 갯수가 넣어지지만 높이 1은 넣어지지 않는다.
    // 그래서 없는 구간에도 넣어줘야한다. 이때 방법은 높이 3의 갯수는 높이 5의 갯수의 합이니깐, 5개라고 하면 높이 1, 2도 5개가 된다.
    int one = 0;
    int two = temp2.size() -1;
    
    for(int i =1; i<=H; i++){
        
        // 현재 높이가 one의 높이 보다 작다면 one의 높이를 현재 i 높이 구간에 넣어준다.
        if(i < temp1[one].height){
            section[i] = section[temp1[one].height];
        }
        // 현재 높이가 i 높이랑 같아지면 one을 증가시켜 준다. 이때, one이 OutOfBound가 발생 하지 않기 위해서
        // temp1.size() -1을 해줬다.
        else if( i == temp1[one].height && one < temp1.size() - 1){
            one++;
        }
        
        // 거꾸로 생각해야하니깐, 여기가 가장 헬 (내 머리를 탓하자 ㅎㅎ)
       // 여기서 section2[i] ==0 일때로 한 것은 이미 입력된 값을 변경 해주지 않기 위해서다.
        if(i > H - (temp2[two].height -1) && section2[i] == 0){
            section2[i] = section2[ H - (temp2[two].height - 1) ];
        }
         // 현재 i 값이 two의 다음 값의 높이랑 같다면 줄여준다.
        else if( i == H - (temp2[two - 1].height -1) && two>0){
            two--;
        }
        
        section[i] += section2[i];
        
    }
    
    
    //가장 최소 값을 구해준다.
    int anw = section[1];
    int anw_cnt = 1;
    for(int i = 2; i<=H; i++){
        
        if(section[i] < anw){
            anw = section[i];
            anw_cnt = 1;
        }
        else if(section[i] == anw){
            anw_cnt++;
        }
        
    }
    
    cout << anw << " " << anw_cnt;
    
    
    
    return 0;
}
