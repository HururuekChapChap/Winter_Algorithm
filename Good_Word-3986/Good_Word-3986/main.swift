//
//  main.swift
//  Good_Word-3986
//
//  Created by yoon tae soo on 2020/02/27.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

var stack : Array<Character> = Array<Character>();
var Input_List : Array<String> = Array<String>();

let N = readLine();
var Num : Int = 0;

if let N = N{
    Num = Int(N)!;
    
    for _ in 0..<Num{
        
        let temp = readLine()!
        Input_List.append(temp)
        
    }
    
}

var anw : Int = 0

for i in 0..<Num{
    
    //var flag : Bool = true;
    
    var j : Int = 0;
    
    while ( j < Input_List[i].count) {
        
        
        let chr = Input_List[i][Input_List[i].index(Input_List[i].startIndex, offsetBy: j)]
        
        if(j<Input_List[i].count - 1 && chr == Input_List[i][Input_List[i].index(Input_List[i].startIndex, offsetBy: j+1)]){
            
            j += 2
            
            continue
            
        }
        
        if(stack.count == 0){
            stack.append(chr)
        }
        else{
            
            let pop_chr = stack[stack.count-1]
            
            if(chr == pop_chr){
                stack.remove(at: stack.count-1)
            }
            else{
                
                    stack.append(chr)
        
            }
            
        }
        
        j += 1
    }
    
     //print(stack);
    if(stack.isEmpty == true){
        anw += 1
    }
    
    stack = []
    
}

print(anw)


