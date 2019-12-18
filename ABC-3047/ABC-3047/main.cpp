//
//  main.cpp
//  ABC-3047
//
//  Created by yoon tae soo on 2019/12/18.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int num[3];
    string ABC;
    
    for(int i = 0; i< 3; i++){
        cin >> num[i];
    }
    cin >> ABC;
    
    //세 수를 정렬을 해준다.
    sort(num, num+3);
    
    
    //ABC 순서에 맞게 출력을 해준다. 예를 들어 CBA라고 하면 C를 먼저 출력 B 출력 A 출력
    //위의 정렬과 상관없다 ㅎㅎㅎ.
    for(int i = 0; i< 3; i++){
        
        if(ABC[i] == 'A'){
            cout << num[0] << " ";
        }
        else if( ABC[i] == 'B'){
            cout << num[1] << " ";
        }
        else{
            cout << num[2] << " ";
        }
        
    }
    
    return 0;
}
