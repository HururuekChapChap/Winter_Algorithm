//
//  main.swift
//  Noise-2935
//
//  Created by yoon tae soo on 2020/03/08.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

/*
 이 문제 ㅋㅋㅋㅋ
 일단 문제를 풀다가 잘못 생각해서
 숫자를 더하는 방식을 String으로 풀려고 하니
 많이 이상해 졌다.
 그래도 많은 것을 배울 수 있는 문제였다.
 */

let A = String(readLine()!)
let oper = String(readLine()!)
let B = String(readLine()!)

if(oper == "*"){
    
    var new = "1"
    
    for _ in 0..<( (A.count - 1) + (B.count - 1) ) {
        new += "0"
    }
    
    print(new)
    
}
else{
    
    var list = [Character]()
   
    var temp_A = A.count - 1;
    var temp_B = B.count - 1;
    var Plus = 0
    
    while (temp_A >= 0 || temp_B >= 0 || Plus == 1) {
        
        var a = 0
        var b = 0
        
        if(temp_A >= 0){
            //index로 뽑은 것은 Character 형태 이기 때문에 이것을 Int로 바꿔 주기 위해서는 String해주고 Int로 바꿔줘야한다.
            a = Int(String(A[A.index(A.startIndex, offsetBy: temp_A)]))!
        }
        
        if(temp_B >= 0){
            b = Int(String(B[B.index(B.startIndex, offsetBy: temp_B)]))!
        }
            
        let num = String(a+b+Plus)
        
        //print("\(a) : \(b) : \(num) : \(num[num.index(num.startIndex, offsetBy: num.count-1)])")
        
        list.insert(num[num.index(num.startIndex, offsetBy: num.count-1)], at: 0)
        
        if(a + b + Plus > 9){
            Plus = 1
        }
        else{
            Plus = 0
        }
        
        temp_A -= 1
        temp_B -= 1
        
    }
    
    for num in list{
         print(num, terminator: "")
    }
    
    
}
