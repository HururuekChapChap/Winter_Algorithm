//
//  main.swift
//  MiniFantasy_War-12790
//
//  Created by yoon tae soo on 2020/03/11.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

let total = Int(readLine()!)!

func Check(number : inout Int){
    
    if(number < 1 ){
        number = 1
    }
    
}



for _ in 0..<total{
    
    let Array = readLine()!.components(separatedBy: " ").map { Int($0)!}
    
    var HP = Array[0] + Array[4]
    Check(number: &HP)
    var MP = Array[1] + Array[5]
    Check(number: &MP)
    var 공격 = Array[2] + Array[6]
    
    if(공격 < 0){
        공격 = 0
    }
    
    let 방어 = Array[3] + Array[7]
    
    let anw = HP + (MP * 5) + (공격 * 2) + (2*방어)
    print("\(anw)")
    
}

