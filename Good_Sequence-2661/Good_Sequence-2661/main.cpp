//
//  main.cpp
//  Good_Sequence-2661
//
//  Created by yoon tae soo on 2020/02/25.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>

using namespace std;
/*
 
  이 문제는 나름 생각했는데, 백트레킹 문제인데 54퍼라서 많이 놀랐다.
 쉽다고 생각되지는 않은 문제였다.
 
 처음에는 어떻게 풀어야하나 고민을 많이 했었는데,,,, 백트레킹은 보통 DFS 문제이다.
 따라서 DFS 특징을 살리면 된다. DFS는 일시 정지를 할 수 있다는 특징이 있기 때문에, 정지하고 다음 단계로 넘어갔다.
 
 방법은 계속 탐색하는 것이다.
 예를 들어
 123123
 이 있다고 할때,
 (1개확인)3과 2를 확인
 (두개 확인) 23과 31 확인
 (세개 확인) 123과 123 확인
 
 이렇게 모든 경우를 확인 해주고 모든 경우를 모두 통과 했을 때, 다음 단계로 넘어간다. 그리고 처음 나온 것이 정답이다.
 
 이러한 알고리즘을 생각하는데 나름 고생을 했다 ㅎㅎㅎ 백트레킹은 힘들어하기 때문에 ㅎㅎㅎ
 
 */

int Arr[81];
int anw_flag = 0;
void DFS(int current, int N){
    
    if(current == N+1 && anw_flag == 0){
        
        for(int i = 1; i<=N; i++){
           
            cout << Arr[i];
        }
        anw_flag = 1;
        
    }
    else{
        // 1 2 3 중에 선택
        for(int i = 1; i<4; i++){
            
            int flag = 0;
            //현재 위치에 숫자를 넣어준다.
            Arr[current] = i;
            //절반까지 탐색을 해준다. 1.... 현재의 절반 까지 선택 가능
            for(int j = 1; j<= current/2; j++){
                
                int temp_flag = 1;
                // 인접한 부분 까지
                int temp_end = current - j;
                int E = temp_end;
                //현재 부터 인접한 부분까지 탐색
                for(int S = current; S > temp_end ;){
                    //현재 위치와 끝 위치가 다르다면 패스
                    if(Arr[S] != Arr[E]){
                        temp_flag = 0;
                        break;
                    }
                    
                    S--;
                    E--;
                }
                //하나라도 동일한것이 있다면 종료
                if(temp_flag == 1){
                    flag = 1;
                    break;
                }
                
            }
            //하나라도 동일한 것 없이 조심스럽게 통과 했다면 다음 걸로 넘긴다.
            if(flag == 0 && anw_flag == 0){
                DFS(current+1, N);
                }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    DFS(1,N);
    
    return 0;
}
