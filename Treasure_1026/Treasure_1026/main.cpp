//
//  main.cpp
//  Treasure_1026
//
//  Created by yoon tae soo on 2019/12/15.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Data{
public:
    int data;
    int seq;
};


bool compare (int a, int b){
    return a >b;
}

int main(int argc, const char * argv[]) {
    
    vector<int> B;
    vector<int> A;
    
    int N;
    int item;
    int sum = 0;
    cin >> N;
    
    for(int i =0; i< N; i++){
        
        cin >> item;
        
        A.push_back(item);
    }
    
    for(int i=0; i< N; i++){
        cin >> item;
        B.push_back(item);
    }
    
    
    sort(A.begin(),A.end(), compare);
    sort(B.begin(),B.end());
    
    for(int i = 0; i< N; i++){
        //cout << A[i] << " " << B[i] << " ";
        sum += A[i] * B[i];
    }
    
    cout << sum;
    

    return 0;
}
