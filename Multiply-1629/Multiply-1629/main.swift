//
//  main.swift
//  Multiply-1629
//
//  Created by yoon tae soo on 2020/03/12.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 
 와 오랜만에 엄청나게 틀려봤다... ㅋㅋㅋㅋㅋ
 일단 굉장히 간단한 문제 인줄 알았는데,,, 쉽지 않았다.
 
 일단 거듭 제곱을 a^N을 N 번 하지 않고 lonN 번으로 할 수 있는 방법을 공부하는 좋은 계기였다.
 예전에 이론 공부 할 때, 해본적이 있는데, 이 이후로 해본 적이 없어서 재귀형식으로 푸는 방법을 잊고 있었다.
 
 방법은
 2^0 = 1
 2^1 = 2 * (2^0 * 2^0)
 2^2 = (2^1 * 2^1)
 2^3 = 2 * (2^1 * 2^1)
 2^4 = (2^2 * 2^2)
 2^5 = 2 * (2^2 * 2^2)
 ...
 
 이런 규칙을 가지고 있다. 즉,, 짝수라면 절반의 값을 두번 곱하여 반환하고 홀수라면 2에다가 절반의 값을 두번 곱하여 반환하면 된다.
 그런데 이럴 때, 문제가 발생한다...
 이 문제가 뭘지 정말 몰랐다.
 
 2147483646 3 2147483647
 
 이렇게 하니 오버플로우가 발생하는 것이였다.
 
 왜냐하면
 N : 3(2147483646 * (2147483646 * 2147483646)) -> N:1(2147483646) -> N:0(1)
 이렇게 가게 되니, 오버 플로우가 발생 할 수 밖에 없는 것이였다.
 
 그래서 어떻게 해야하지 라고 생각을 했는데,
 2^0 = 1
 2^1 = 2 * 2^0
 2^2 = (2^1 * 2^1)
 2^3 = 2 * 2^2
 2^4 = (2^2 * 2^2)
 2^5 = 2 * 2^4
 
 이렇게가 된다. 물론 값은 같게 나오지만, 전달 되는 방식이 다르다.
 N:6(1) -> N : 3(2147483646) - >N :2(1) -> N : 1(2147483646) -> N:0(1)
 
 이렇게 값이 작아진다. 그래서 이렇게 홀수 일때는 getMultiple(a, N-1) 짝수일 때는 getMultiple(a, N/2) 이렇게 해줘야한다.
 
 또한 어떻게 나눈다고 값이 같을 까 생각했는데,, 나누니깐 게속 같은 값이 나왔다.
 
 그래서 계속 C로 나눠 줬다.
 */

let list = readLine()!.components(separatedBy:" ").map { Int64($0)! }

let A = list[0];
let B = list[1];
let C = list[2];

func getMultiple(_ a : Int64, _ N: Int64) -> Int64 {
    
    
    if(N == 0){
        return 1
    }
    else{
        
        if(N % 2 == 0){
            let tempnum = getMultiple(a, N/2)
            return (tempnum * tempnum)%C
        }
        else{
        let tempnum = getMultiple(a, N-1)
        return (a * tempnum )%C
            
        }
    }
    
}


let temp = getMultiple(A, B)
print("\(temp)")
