//
//  main.swift
//  Playing_yut-2490
//
//  Created by yoon tae soo on 2020/02/29.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

for _ in 0..<3{
    
    let yut = readLine()!.components(separatedBy: " ")
    
    var one = 0
    for word in yut{
        
        if(word == "1"){
            one += 1
        }
        
    }
    
    if(one == 4){
        print("E")
    }
    else if(one == 3){
        print("A")
    }
    else if(one == 2){
        print("B")
    }
    else if(one == 1){
        print("C")
    }
    else{
        print("D")
    }
    
}

