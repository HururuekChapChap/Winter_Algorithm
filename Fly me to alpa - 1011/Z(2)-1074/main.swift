//
//  main.swift
//  Z(2)-1074
//
//  Created by yoon tae soo on 2020/03/06.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

var total = Int(readLine()!)!

/*
 
 규칙적으로 증가한다.
 
 1 (1) - 1
 2 (1 1) - 2
 
 ===================
 
 3 (1 1 1) - 3
 4 (1 2 1) - 3
 5 (1 2 2 1) - 4
 6 (1 2 2 1) - 4
 7 (1 2 2 1 1) - 5
 8 (1 2 2 2 1) - 5
 9 (1 2 3 2 1) - 5
        .
        .
        .
 
 이렇게
 */

while(total > 0){

let inputs = readLine()!.components(separatedBy: " ")

let list = inputs.map{Int64($0)!}

let dis = list[1] - list[0]

//현재 거리 차이
var sum : Int64 = 0
//횟수
var flycnt : Int64 = 0
//증가분
var plus : Int64 = 0
//두번째에 plus를 증가 할 수 있다.
var upgrade = true

while(sum < dis){
    
    if(sum < 2){
        sum += 1
        plus += 1
    }
    else{
        sum += plus
        
        if(upgrade == false){
            upgrade = true
            plus += 1
        }
        else{
            upgrade = false
        }
        
    }
    
    flycnt += 1
    
}
print(flycnt)

    total -= 1
}
