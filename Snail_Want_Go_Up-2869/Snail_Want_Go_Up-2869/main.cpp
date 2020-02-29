//
//  main.cpp
//  Snail_Want_Go_Up-2869
//
//  Created by yoon tae soo on 2020/01/07.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A,B,V;
    cin >> A >> B >>V;
    
    /*
     허,, 이문제 처음에는 시간 초과가 나왔다. 왜 나왔지 하고 생각하니 10억 까지인데
     나는 10억 까지 반복문을 돌려줬기 때문이다. 시간 초과가 0.15초 까지 인데, 나올 수 밖에 없었다.
     
     방법은 수학적으로 빠른 시간에 푸는 것 밖에 없었다.
     내 방식은 정답이 아니라 약간 부족한 방식인데, 처음에 증가에서 감소 분을 빼준다. 그러면 그것이
     하루마다 변하는 양이 된다. 그리고 그것을 V와 나눠주는데, 그것이 최대 위치일 것이다. 그리고 A를 더해주는 것은
     그 다음날 증가분이다. 그것이 최대치일 것이고 num 보다 작거나 같을 때 까지 반복문을 돌려준다.
     즉, 다시 하루를 줄여가는 것이다.
     
     다른 사람들은 V에서 시작 증가분을 빼준다. 그러면 첫일치가 빠진다. 첫 일치가 빠졌다는 것은 V에서 증가분-감소분을 빼줬을 때,
     나눠 떨어지면 그날에 해결이 되고 나머지가 생기면 하루를 더해주면 된다.
     
     오히려 내가 너무 어렵게 생각했는데, 이렇게 수학적인 사고를 키우는 문제를 많이 풀어보는 것이 중요할 것 같다.
     물론 기술적인 문제도 중요하지만 이런 수학적이고 구현적인 문제를 많이 풀어보는게 더 중요하다고 생각된다.
     */
    
    int temp = A-B;
    
    int time = V/temp;
    
    int num = time*temp + A;
    time++;
    
    int flag = 0;
    
    while(num >V){
        time--;
        num -= temp;
        
        if(num == V){
            flag = 1;
            break;
        }
        else if( num < V){
            flag = 2;
            break;
        }
        
    }
    
    if(flag == 1){
        cout << time;
    }
    else if(flag == 2){
        cout << time + 1;
    }
 
    
    return 0;
}
