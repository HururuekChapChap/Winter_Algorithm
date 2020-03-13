//
//  main.swift
//  Right_Angled_Triangle-4153
//
//  Created by yoon tae soo on 2020/03/12.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

while(true){
    
    let list = readLine()!.components(separatedBy: " ").map {Int($0)!}
    
    let A = list[0];
    let B = list[1];
    let C = list[2];
    
    if(A == 0 && B == 0 && C == 0){
        break;
    }
    
    let temp_A = (B*B) + (C*C)
    let temp_B = (A*A) + (C*C)
    let temp_C = (A*A) + (B*B)
    
    if(temp_A == A*A || temp_B == B*B || temp_C == C*C){
        print("right")
    }
    else{
        print("wrong")
    }
}

