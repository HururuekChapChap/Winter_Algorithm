//
//  main.swift
//  SuperMario-2851
//
//  Created by yoon tae soo on 2020/03/09.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 
 이 문제 사소한 실수를 했다....
 당연히 거리의 차이가 기존의 거리의 차이 보다 작을 경우에만 total을 추가해주는 건데,
 후에 거리가 더 짧아지는 경우가 생길 수 있다.
 
 예를 들어)
 50
 30
 90
 20
 1
 1
 1
 1
 1
 1
 
 이럴경우 80과 100은 거리가의 차이가 20이다. 여기서 90을 더하면 거리가 더 멀어지기 때문에
 추가 하지 않는데, break를 하지 않으면 후에 20을 더할 때, 길이가 더 짧아져서 갱신하게 된다.
 */
var mushroom = [Int]()

for _ in 0..<10{
    mushroom.append(Int(readLine()!)!)
}

var total = 0
var dis = 200

for i in mushroom{
    
    let temp = total + i
    print(temp , terminator: " ")
    
    if( (temp - 100).magnitude <= dis){
        total = temp
        dis = Int((temp - 100).magnitude)
    }
    else{
        break;
    }
    
    
    
}

print(total)
