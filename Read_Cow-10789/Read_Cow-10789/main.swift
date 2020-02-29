//
//  main.swift
//  Read_Cow-10789
//
//  Created by yoon tae soo on 2020/02/27.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

import Foundation

var words : Array<String> = Array<String>();

for _ in 0..<5{
    //입력 받는다. 하지만 옵션널 타입이기 때문에 if let 구문으로 풀어준다.
    let read = readLine()
    
    //만약에 read가 ? 이 아니라면 Input에 값을 넣어준다.
    if let input = read{
        words.append(input)
    }
    
}


var MAX_len : Int = 0

//가장 길이가 긴 값을 구해 온다.
for i in 0..<5{
    
    let temp = words[i].count
    
    if(MAX_len < temp){
        MAX_len = temp
    }
    
}

var Anw : String;

for i in 0..<MAX_len{
    
    for j in 0..<5{
        
        if(words[j].count - 1 >= i){
            //첫번째 문자를 확인해준다. 정말 길다 ㅎㅎㅎㅎ.
            let chr = words[j][words[j].index(words[j].startIndex, offsetBy: i)]
            print(chr , terminator : "")
        }
        
    }
    
}
