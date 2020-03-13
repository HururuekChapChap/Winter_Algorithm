//
//  main.swift
//  FBI
//
//  Created by yoon tae soo on 2020/03/11.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

func Check(_ name: String) -> Bool{
    
    if(name == "FBI"){
        return true
    }
    
    return false
}

var list = [Int]()

for i in 0..<5{
    
    let name = readLine()
    
    if let name = name{
        
        var loc = 0
        while(loc+2 < name.count){
            
            let temp = String(name[name.index(name.startIndex, offsetBy: loc)])+String(name[name.index(name.startIndex, offsetBy: loc+1)])+String(name[name.index(name.startIndex, offsetBy: loc+2)])
            
            if(Check(temp)){
                list.append(i+1)
                break;
            }
            
            loc += 1
        }
        
    }
    
}

list.sort()

if(list.isEmpty){
    print("HE GOT AWAY!")
}
else{
    for name in list{
        print(name , terminator : " ")
    }
}

