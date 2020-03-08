//
//  main.swift
//  Sangeun_Trip-9372
//
//  Created by yoon tae soo on 2020/03/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 
 흠,, 먼가 어렵게 적었는데, 단순한 문제다, 성공률 60%이면 말 다했다. 그런데, 신기한건
 이 문제를 유니온 파인드로 풀 수 있었다는거에 더 놀랐다.
 나는 그냥 방문 표시를 하고 거기서 뻗어 갈 수 있는 가지 수에 대해서 계산 해줬는데,,,,
 
 유니온 파인드로 푼다면, 순환을 하는 쪽이라는 것은 결국 루트가 같기 때문에 더해주지 않고
 다르다면 서로 결속 시켜주고 횟수를 하나 증가해준다.
 
 */
var Total = Int(readLine()!)!

while(Total > 0){

let input_one = readLine()!.components(separatedBy: " ").map {Int($0)!}

let N = input_one[0]
let M = input_one[1]

    //이차원 연결리스트 배열에서의 초기화 방법은 []이렇게 해주고 N+1로 해주면 resize해준 것과 같다.
var list = Array<Array<Int>>(repeating: [], count: N+1)
    //나라의 방문 표시
var country = Array<Bool>(repeating: false, count: N+1)

for _ in 0..<M{
    let input_two = readLine()!.components(separatedBy: " ").map {Int($0)!}
        
    let from = input_two[0]
    let to = input_two[1]
    
    list[from].append(to)
    list[to].append(from)
    
}

func BFS() -> Int{
    
    country[1] = true
    var queue = [Int]()
    var cnt = 0
    queue.append(1)
    
    
    //queue.empty의 다른 말로 표현 할 수 있다.
    while(queue.count > 0){
        
        let current = queue[0]
        
        //선입선출 queue 방식으로 앞에 있는 것을 먼저 제거해주는 방법이다.
        //스택이라면 at에 count-1을 넣어주면 된다.
        queue.remove(at: 0)
        
        for i in 0..<list[current].count{
            
            let next_current = list[current][i]
            
            if(country[next_current] == false){
                country[next_current] = true
                cnt += 1
                //뒷부분에 추가해주는 방법
                //앞 부분에 추가하는 방법은 insert를 해주면 된다.
                queue.append(next_current)
            }
            
        }
    
    }
    
    return cnt
    
}


print(BFS())

    Total -= 1
}
