//
//  main.cpp
//  Phone_Number_List-5052
//
//  Created by yoon tae soo on 2019/12/19.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Data{
public:
    string item;
    int len;
};

bool compare(Data  v1, Data v2){
    
    if(v1.len == v2.len){
        return v1.item < v2.item;
    }
    
    return v1.len < v2.len;
}

int main(int argc, const char * argv[]) {
    
    
    // 사실상 좋은 코드는 아니다. 어떻게든 아이디어를 생각해서 우거지로 통과한 것이기 때문이다.
    // 좋은 코드는 (2)에 적어놨고, 이건 다른 사람의 코드를 통해서 배운 것이다.
    // 이 문제는 트라이 알고리즘을 통해서 푸는 것도 가능하다는데, 트라이 알고리즘도 공부해봐야겠다.
    
    int t;
    cin >> t;
    
    while(t >0){
    
    int N;
    // 참, 거짓 판별 변수
    int flag = 0;
    // 입력받을 숫자
    string item;
    vector<Data> v;
    cin >> N;
    
    for(int i =0; i<N; i++){
        cin >> item;
        int len = item.size();
        v.push_back({item, len});
    }
    
    //길이에 따라서 정렬을 해준다.
    sort(v.begin(), v.end(), compare);
    
    //그리고 모든 부분에서 탐색을 해준다 - _ - ( 복잡도가 N^2이라서 시간초과 날 줄 알았는데, 이 부분에서 시간초과 한번 발생했다.)
    for(int i=0; i<N-1; i++){
        
        for(int j=i+1; j<N; j++){
            
            int temp_len = v[i].item.length() -1;
            
            // 이렇게 길이가 같다면 아랫부분을 탐색하지 않고 넘긴다. ( 이것으로 간신히 시간초과를 넘길 수 있었다.)
            if(temp_len == v[j].item.length()-1){
                continue;
            }
            
            // 중간에 다른 부분이 있다면 while 문을 나가주고 만약에 끝까지 동일 한 것이 있다면
            // 같은 것이기 때문에 flag 값을 변경해준다.
            while(temp_len >= 0){
                
                if(v[i].item[temp_len] != v[j].item[temp_len]){
                    break;
                }
                
                temp_len--;
            }
            
            if(temp_len < 0){
                flag = 1;
                break;
            }
            
        }
        
        //flag가 1 이라면 중복된 것이 있음을 알려주기 때문에 NO라고 출력한다.
        if(flag == 1){
            printf("NO \n");
            //cout << "NO" << endl;
            break;
        }
        
    }
    
        //그게 아니라면 YES 출력
    if(flag == 0){
        printf("YES \n");
        //cout << "YES" << endl;
    }
    
        t--;
    }
    
    return 0;
}
