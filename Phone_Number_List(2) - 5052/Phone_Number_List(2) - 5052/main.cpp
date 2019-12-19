//
//  main.cpp
//  Phone_Number_List(2) - 5052
//
//  Created by yoon tae soo on 2019/12/19.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    
    while(t>0){
        
        int N;
         bool flag = false;
        vector<string> v;
        string name;
        cin >> N;
        
        for(int i =0; i< N; i++){
            cin >> name;
            v.push_back(name);
        }
        // 윗 부분은 (1)과 동일하다.
        
        // 정렬을 해준다. 이때, 몰랐던 사실은 1 11 100 110 12 10  정렬을 해준다면,
        // 1 10 100 11 110 12 이런 방식으로 정렬이 된다.
        // 즉, 정렬 방식이 비슷한 놈들 끼리 모아주는 것이다.
        // 이런식으로 정렬이 된다면 그냥 앞에 있는 놈과 뒤에 있는 놈을 비교해주면 된다.
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i< N-1; i++){
            flag = false;
            
            string str = v[i];
            string str2 = v[i+1];
            
            // 이부분이 탐색 부분이다.
            for(int j = 0; j< str.length(); j++){
                
                if(str[j] != str2[j] ){
                    flag = true;
                    break;
                }
                
            }
            
            if(flag == false){
                cout << "NO" << endl;
                break;
            }
            
        }
        
        if(flag == true){
            cout << "YES" << endl;
        }
        
        
        t--;
    }
    return 0;
}
