//
//  main.cpp
//  Map_&_Set_Practice
//
//  Created by yoon tae soo on 2019/12/24.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <time.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand((unsigned)time(NULL));
    
    //set을 여러개의 데이터로 하는건 아직 못하겠다 ㅎㅎ
    set<int> s;
    //map은 앞 부분이 key 값 뒤에가 데이터 값이다. 따라서 모든게 key값 순으로 정렬이 된다.
    map<int,char> m;
    
    int N,num;
    char ch ='a';
    cin >> N;
    
    for(int i =0; i<N; i++){
        num = rand()%100;
        
        //입력해주는 명령어 insert
        s.insert(num);
        m.insert(make_pair(num, ch));
        cout << num << " " << ch << " ";
        ch = ch + 1;
    }
    
    cout <<"\nset에 저장된 내용" << endl;
    
    // map과 set 모두 이진탐색트리라서 배열로 이뤄진 힙과 달리 포인터로 이뤄져 있기 때문에
    //auto를 사용해서 변수를 알아서 지정하게 해주고 출력할때는 포인터 변수 처럼 출력해줘야한다.
    for(auto loc = s.begin(); loc != s.end(); loc++){
        //요렇게 포인터로
        cout << *loc << " ";
    }
     cout << "\nmap에 저장된 내용" <<endl;
    for(auto it = m.begin(); it != m.end(); it++ ){
        //map은 변수가 두개 이기 때문에 이렇게 포인터로
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
    
    num = rand()%100;
    
    
    //그 값이 존재하는지 찾아주는 find 변수
    //find는 명령은 값이 존재하면 set: 값을 반환 / map: 가리키는 값 반환 없다면 set : 0 / map : 공백
    //find명령어도 마찬가지로 포인터 값으로 반환이 되어서 *로 붙여줘야한다.
    //map도 포인터이기 때문에 ->로 표현해준다.
    cout << num <<" "<<*s.find(num) << " " << m.find(num)->second <<endl;
    
    //map 같은 경우는 set과 달리 없을 경우 반환값이 다르기 때문에, 이렇게 카운트로 먼저 존재하는지 않하는지 확인해주는게 좋을 것 같다.
    if( m.count(num) == 0){
        cout << "empty";
    }
    
    return 0;
}
