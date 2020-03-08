//
//  main.swift
//  Remote_Controller-1107
//
//  Created by yoon tae soo on 2020/03/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 흠 많이 어려운 문제 였다.... 그리고 처음에 방법을 잘못 잡기도 했다. 아직 많이 멀었다.
 아직은 반례를 보지 않고서는 백점 맞기 힘든거 같다... 깊게 생각하는 연습을 해야하는데,, 틀리는건 싫어하고,,,
 아 싫다 ㅠㅠ
 
 일단 잡소리는 그만하고 처음 생각한 알고리즘은 각 숫자마다 가까운 숫자를 찾아서 숫자를 정리해주고 그 숫자와 목표치로 하는 숫자의
 차이를 구해서 풀어주는 방식으로 풀었는데,,,,
 사실 이게 많이 잘 못 된 것이였다.
 
 예를 들어
 
 123
 2
 2 3
 
 이렇게 했을 경우에 하나씩 비교해서 가까운 숫자는 114 이렇게 나온다. 따라서 버튼 3번 누르고 123 - 114 해주면 9 총 12번이 나오는데,
 정답은 119 로 3번에  123 - 119로 4로 총 7이 나와야 답이다. 즉, 숫자끼리 비교해주는 방식이 아니라 가장 가까운 수를 찾아줘야했다.
 
 그래서 잠시 접어두고 엄마 침대가서 잤다.... 그리고 일어나서 다시 생각 했을 때, 최대가 500000 까지 이니 순열으로 풀면 되겠다는 생각을 했다.
 
 순열으로 풀었는데,,, 일단 시간적 여우가 있으니깐, 천천히 풀었다. 버튼이 고장 난 버튼을 제외하고 0 ~ 10까지
 팀색을 해준다. 그리고 목표치의 숫자와 크기가 같을 때 까지 선택(push배열에 담아주는 것)을 해준다. 그리고 push의 값들을 빼서 숫자를 만들어 준다(temp_number)  목표치에서 temp_number를 빼고 절대값을 취해준다. 그리고 새로운 번호이니 번호를 누른수 를 더해줘서 더 누른 횟수가 작다면 갱신해준다.
 
 그런데 다소 문제가 생겼는데,,, 생각하지 못한것이 있었다. 반례를 보니,,, 나는 처음에 목표치의 숫자의 크기가 같을 때 까지 선택을 해주는데 (destination.count),,,, 문제가 있었다.
 
 예를 들어서
 
 10
 2
 0 1
 
 이렇게 됐을 때,
 무조건 선택이 22 23 24 25 ... 이렇게 가게 된다.
 따라서 9 이렇게 하나만 선택 되는 경우도 고려해줘야한다.
 
 따라서 0 버튼이 고장 날때와 고장 나지 않을때, 이렇게 두개의 경우로 나눠주고
 
 고장 안 났다면
 
 그냥 10개를 선택 했을 때 까지 순열을 돌려줬다.
 
 고장 났다면,
 1개를 선택했을 때 부터 10개를 선택을 했을 때 까지 반복을 돌려줬다.
 
 그런데,,, 10개를 해주면 너무 느리게 나온다......
 어디까지 해줘야 하지??? 고민을 많이 하다가,,, 0 ~ 500000이 가장 큰 차이이니 500000 + 500000 까지해주면 1000000 총 6개 까지 선택 했을 때 까지 비교해주면 됐다.

 후우,,,, 쉽자 않다... 알고리즘,, 아무리 해도 실력이 잘 늘지 않는 것 같다.. 완벽해질 때까지,,, 열심히 해야겠다. 꼭 대기업 갈 필요가 있나??? ㅎㅎㅎㅎ 분위기 좋은 곳에서 일하자!! 돈이 뭐가 중요하겠음
 
 */

//목표치 숫자를 입력받는다.
let destination = readLine()!
//고장난 숫자의 개수를 입력받는다.
let broken_cnt = Int(readLine()!)!
//초기화 해준다. repeating을 사용해줘서 초기화!!
var remote = [Bool](repeating: false, count: 10)
//Int형인 배열을 선언해준다.
var push = [Int]()
//눌러진 숫자(필요없다)
var press_Number = 0
//가장 가까운 숫자
var close_number = 100
//처음 100과 목표치의 거리. 즉, + 또는 - 를 눌러서 이동해야하는 거리
var differ = (Int(destination)! - close_number).magnitude

//고장난 버튼을 입력 받는다.
if broken_cnt > 0{
    
    let broken_list = readLine()!.components(separatedBy: " ").map{Int($0)!}
    
    for number in broken_list{
        remote[number] = true
    }
    
}

//순열을 해주는 함수
func FindNum(current : Int, stop : Int ){
    //멈춰야 할 때
    if(current == stop ){
     
        var temp_number = 0
        //숫자를 빼줘서 순열로 만들어진 숫자를 만들어준다.
        for i in push{
            temp_number = (temp_number*10) + i
        }
        
        //print(temp_number)
        
        //현재 거리의 차이에서 버튼을 누른 횟수가 기존의 횟수 보다 작을 때 갱신
        if( Int((Int(destination)! - temp_number).magnitude) + String(temp_number).count < differ) {
            close_number = temp_number
            differ = UInt(Int((Int(destination)! - temp_number).magnitude) + String(temp_number).count)
        }
        
    }
    else{
        
        for i in 0..<10{
         
            if(remote[i] == false){
             
                push.append(i)
                FindNum(current: current + 1, stop: stop)
                push.remove(at: push.count - 1)
                
            }
            
        }
        
    }
    
}

if(remote[0] == false){
FindNum(current: 0, stop: 6)
}
else{
    
    for i in 1...6{
        FindNum(current: 0, stop: i)
    }
    
}

print("차이 : \(differ) 작은 수 : \(close_number)")


/*
var differ = Int(destination)! - current_number

if(differ < 0){
    differ *= -1
}


if(destination.count < differ && broken_cnt < 9){
    
    var last_number = 0
    
    let destination_number = Int(destination)!
    var divid_cnt = 1
    
    while(true){
        
        let temp_number = (destination_number/divid_cnt)  % 10
        
        var min_differ = 10
        var min_number = 10
        
        for j in 0...9{
            
            if( (temp_number - j).magnitude < min_differ && remote[j] == false ){
                
                min_differ = Int((temp_number - j).magnitude)
                min_number = j
            }
            
        }
        
        last_number += min_number * divid_cnt
        
        divid_cnt *= 10
        
        if((destination_number/divid_cnt) <= 0){
            break
        }
        
    }
    
    press_Number = destination.count
    current_number = last_number
    
}

print("\(differ) 와 \(current_number)")

if(differ.magnitude < press_Number + Int((Int(destination)! - current_number).magnitude)){
    print(differ.magnitude)
}
else{

print(press_Number + Int((Int(destination)! - current_number).magnitude))

}

*/

