//
//  main.swift
//  MinGue_Password-9933
//
//  Created by yoon tae soo on 2020/03/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 
 이 문제는 level과 같은 자기 자신도 거꾸로 형태가 된다!
 */

let total = Int(readLine()!)!

var list = [String]()

for _ in 0..<total{
    
    list.append(String(readLine()!))
    
}

for i in 0..<total{
                //문자열을 거꾸로 해줄 때.
    let reverse = String(list[i].reversed())
    
    for j in i..<total{
        
        if(list[j] == reverse){
            print("\(list[j].count) \(list[j][list[j].index(list[j].startIndex, offsetBy: list[j].count/2)])")
        }
        
    }
    
}


