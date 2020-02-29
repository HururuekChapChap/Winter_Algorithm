//
//  main.cpp
//  No_Heard_No_See_Person-1764
//
//  Created by yoon tae soo on 2020/01/17.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    map<string,int> hear;
    vector<string> list;
    
    int N, M;
    char name[21];
    cin >> N >> M;
    
    for(int i = 0; i<N; i++){
        scanf("%s", name);
        hear.insert(make_pair(name, 1));
    }
    
    for(int i=0; i<M; i++){
        scanf("%s", name);
        if(hear.count(name) == 1){
            list.push_back(name);
        }
        
    }
    
    cout << list.size() << "\n";
    sort(list.begin(),list.end());
    
    
    for(int i = 0; i<list.size(); i++){
        cout<< list[i] << "\n";
    }
    
    
    return 0;
}
