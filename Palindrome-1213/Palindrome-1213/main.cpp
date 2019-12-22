//
//  main.cpp
//  Palindrome-1213
//
//  Created by yoon tae soo on 2019/12/22.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //입력 받을 문자열
    string input;
    //하나씩 뽑아줄 백터
    vector<char> v;
    //정답 벡터
    vector<char> anw;
    
    cin >> input;
    
    //하나씩 하나씩 뽑아주는 벡터에 저장해준다.
    for(int i =0; i<input.length(); i++){
        v.push_back(input[i]);
    }
    
    //정렬을 해준다. 정렬을 해주는 이유는 비슷한 것 끼리 모여 있게 된다.
    //그리고 펜드롬은 짝수개씩 필요하기 때문에 짝수 인지 홀수 인지 구분을 해줄 수 있다.
    sort(v.begin(), v.end());
    
    char current = v[0];
    int cnt = 1;
    //홀수가 하나까지는 가능한데 두개 이상 부터는 만들 수 없기 때문에, total 변수를 만들어준다.
    int total = 0;
    
    // 쭉 검사하면서 홀수 인지 아닌지 구분 해준다.
    for(int i =1; i<input.length(); i++){
        //cout << v[i] << " ";
        
        if(current != v[i]){
            current = v[i];
            
            //모여있는게 짝수인지 홀수인지 판별!
            if(cnt % 2 != 0){
                total++;
            }
            
            cnt = 1;
        }
        else if(current == v[i]){
            cnt++;
        }
        
    }
    
    if(cnt % 2 != 0){
        total++;
        
    }
    
    //홀수 갯수가 하나 이상이라면 못 만든다.
    if(total >1){
        cout << "I'm Sorry Hansoo";
    }
    else{
        //마지막 위치를 나타낸다.
        int loc = v.size();
        
        char temp;
        bool flag = false;
        //벡터의 크기를 지정해준다.
        anw.assign(loc, ' ');
        
        for(int i=0; i<v.size(); i++){
          
            //이미 펜드롬을 만들 수 있기 때문에, 홀수는 하나 일 것이고 나머지는 짝수 일 것이다.
            //따라서 현재 것과 앞에 것과 비교를 해준다.
            //그리고 앞 위치에 하나 넣고 마지막 위치에 넣어준다.
            //그리고 loc의 길이를 줄여주고 두칸 이동해준다.
            if(v[i] == v[i+1]){
                anw[v.size() - loc] = v[i];
                anw[loc-1] = v[i];
                loc--;
                i++;
            }
            //다르다면 홀수가 등장했다는 것이다. 그래서 임시 변수 temp에 저장해주고 홀수 발견 표시를 해준다.
            else if(v[i] != v[i+1]){
                temp = v[i];
                flag = true;
            }
            
        }
        
        //홀수가 있다면 temp를 답에 넣어준다.
        if(flag == true){
            anw[v.size()/2] = temp;
        }
        
        //출력
        for(int i = 0; i<v.size(); i++){
            cout << anw[i];
        }
        
    }
    
    /*
     다른 사람의 코드를 봤는데, 나랑 알고리즘이 비슷한 사람들이 많았다.
     가장 놀라왔던 건, 이 문제를 스택으로 풀었다는 것이다.
     스택으로 풀이 방법은 정렬을 해주고, 스택을 두개 만들어 준다.
     두개가 짝으로 구성 되니깐, 앞에 것은 스택1에 뒤에것은 스택2에 넣어주고
     나중에 출력해줄 때, 스택1의 것을 스택2에 넣어주고 한번에 출력해주는 방식으로 한 코드를 봤다.
     */
    
    return 0;
}
