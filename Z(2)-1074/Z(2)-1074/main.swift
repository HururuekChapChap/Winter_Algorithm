//
//  main.swift
//  Z(2)-1074
//
//  Created by yoon tae soo on 2020/03/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 흠 이런 방식으로 푸는 문제는 처음이라서 많이 어려웠다....
 다시 마음 가짐을 가지고 열심히 풀어야 겠다.
 
 방법은 재귀 형식으로 풀어가는 것이다
 첨에 나도 이걸 어떻게 풀지???? 모든 사각형에 채워줘야하나?? 싶었는데,, 채워주는 방법을 생각하지 못했다.
 그런데 재귀 방식으로 푸는 거여서 많이 놀랐다.
 
 쉽게 설명하면 사분면을 게속 쪼개 나가는 방식이다. 그리고 그 위치를 찾아가는데, 모든 곳에 값을 반환하면
 재귀가 많이 돌기 때문에 시간 초과가 발생 할 수 있으므로, 사격형의 넓이를 계산해준다.
 
 */

let inputs = readLine()!.components(separatedBy: " ").map{Int($0)!}

var number = 1

for _ in 1...inputs[0]{
    number *= 2
}

//꼭지점 x y, 찾고자하는 위치 x y, 한변의 길이, 총합을 매개변수로 보낸다.
func Check(current_x: Int, current_y : Int ,x : Int , y : Int, number : Int, sum : Int) -> Int{
    
    let half = number / 2
    
    //print(" 탐색 시작 X : \(current_x) 탐색 시작 Y : \(current_y) 변의 길이 : \(number) 총합 : \(sum)")
    if(current_x == x && current_y == y){
        return sum
    }
    
    //1사분면
    if(x < current_x + half && y < current_y + half){
       return Check(current_x: current_x ,current_y: current_y ,x: x, y: y, number: half, sum: sum)
    }
    //2사분면
    else if(x >= current_x + half && y < current_y + half){
      return  Check(current_x: current_x + half,current_y: current_y,x: x, y: y, number: half, sum: sum + (half*half))
    }
    //3사분면
    else if(x < current_x + half && y >= current_y + half){
      return  Check(current_x: current_x,current_y: current_y + half, x: x, y: y, number: half, sum: sum + (half*half)*2)
    }
    //4사분면
    else if(x >= current_x + half && y >= current_y + half){
       return Check(current_x: current_x + half,current_y: current_y + half,x: x, y: y, number: half, sum: sum + (half*half)*3)
    }
    
    return -1
}

print(Check(current_x: 0, current_y: 0, x: inputs[2], y: inputs[1], number: number, sum: 0))
