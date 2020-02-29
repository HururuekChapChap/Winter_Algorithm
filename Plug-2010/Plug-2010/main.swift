//
//  main.swift
//  Plug-2010
//
//  Created by yoon tae soo on 2020/02/28.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

let N = readLine()!

var list : Array<Int> = Array<Int>()

if let N = Int(N){
    
    for _ in 0..<N{
        let input = readLine()!
        list.append(Int(input)!)
    }
}

list.sort()

var MAX = list[list.count-1]

var len = list.count-2

while(len >= 0){
    
    //print("\(MAX-1) + \(list[len]) ")
    MAX = MAX - 1 + list[len]
    
    len -= 1
 
    
}

print(MAX)
