//
//  main.swift
//  Resistence-1076
//
//  Created by yoon tae soo on 2020/03/05.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

func ValueReturn(name : String) -> Int{
    
    switch name {
    case "black":
        return 0
    case "brown":
        return 1
    case "red":
        return 2
    case "orange":
        return 3
    case "yellow":
        return 4
    case "green":
        return 5
    case "blue":
        return 6
    case "violet":
        return 7
    case "grey":
        return 8
    case "white":
        return 9
    default:
        return -1
    }
    
}

func MultiReturn(name : String) -> Int{
    
    switch name {
    case "black":
        return 1
    case "brown":
        return 10
    case "red":
        return 100
    case "orange":
        return 1000
    case "yellow":
        return 10000
    case "green":
        return 100000
    case "blue":
        return 1000000
    case "violet":
        return 10000000
    case "grey":
        return 100000000
    case "white":
        return 1000000000
    default:
        return -1
    }
    
}
  var list = Array<String>()

    for _ in 0..<3{
       let command = readLine()!
        list.append(command)
    }

    let inputList = list.map{String($0)}
    
    let number : Int64 = Int64((ValueReturn(name: inputList[0])*10 + ValueReturn(name: inputList[1])) * MultiReturn(name: inputList[2]))
    
    print(number)
    




