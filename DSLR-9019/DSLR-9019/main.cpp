//
//  main.cpp
//  DSLR-9019
//
//  Created by yoon tae soo on 2020/01/18.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*
 이 문제는 예전에 내가 풀었는데, 내가 잘 기억을 못 했다 ㅎㅎㅎ. 첨 보는 문제다 ㅎㅎ.
 
 풀이 방법은 일반적인 BFS문제와 같다. 줄기로 이어지는 방식!
 탐색은 BFS가 최고인 것 같다.
 
 이 풀이 방법을 보니깐 확실히 내가 뭔가 성장은 있나보다 ㅎㅎㅎ.
 풀이 방법은 그냥 시키는데로 하면 된다.
 
 문제가 된 부분은 temp_num을 설정하지 않아서 num이 마지막에 0이 되어 버렸다는 사실과
 string은 굉장한 시간을 먹는 다는 사실 이였다.
 
 아래에 풀이 방법을 주석으로 담았다.
 
 */

class Data{
public:
    int num;
    string command;
};

int visited[10000] = {0};

string BFS(int start, int end){
    queue<Data> q;
    
    visited[start] = 1;
    q.push({start,""});
    
    while(! q.empty()){
        
        int num = q.front().num;
        string command = q.front().command;
        
        //배열에 자리수를 넣어준다.
        int arr[4] = {0};
        //만약 총 4자리라고 한다면 일의 자리 부터 넣어준다.
        int cnt = 3;
        //temp_num을 안해주면 num이 0이 되어버린다.
        int temp_num = num;
        //이렇게 각 자리수를 일의자리 부터 넣어준다.
        while(temp_num>0){
            arr[cnt] = temp_num % 10;
            temp_num = temp_num / 10;
            cnt--;
        }
        
        
        q.pop();
        //결과 값이 나온다면 탐색을 그만한다.
        if(num == end){
            return command;
        }
        
        for(int i = 0; i<4; i++){
            
            int temp = 0;
            //Push를 처음에는 string으로 해줬는데, 이게 엄청난 시간이 걸리 줄은 몰랐다 ㅎ.
            char push =' ';
            
            //2배 하고 나머지를 넣어준다.
            if(i==0){
                temp = (2*num) %10000;
                push = 'D';
            }
            //1을 빼준다.
            else if(i==1){
                temp = num - 1;
                //0 보다 작다면 9999로 돌아간다.
                if(temp < 0){
                    temp = 9999;
                }
                
                push='S';
                
            }
            else if(i>=2){
                
                //왼쪽으로 이동일 경우
                if(i==2){
                    //나는 이렇게 배열에 담았기 때문에, 좀더 배열 형식으로 다루기가 편했다.
                    temp = arr[1]*1000 + arr[2] * 100 + arr[3] * 10 + arr[0];
                    push = 'L';
                }
                //오른쪽으로 이동
                else if(i==3){
                    
                    temp = arr[3]*1000 + arr[0]*100 + arr[1]*10 + arr[2];
                    //cout << " right " <<temp << endl;
                    push='R';
                    
                }
                
                
                
                
            }
          
            // 그 숫자를 방문 안했다면 넣어준다.
            if(visited[temp] == 0){
                visited[temp] = 1;
                q.push({temp,command+push});
            }
            
        }
        
        
    }
    
    return "";
    
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    while(T>0){
    
        for(int i = 0; i<10000; i++){
            visited[i] = 0;
        }
        
    int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
    
    string anw = BFS(A,B);
    
    cout << anw << "\n";
    
        T--;
    }
    return 0;
}
