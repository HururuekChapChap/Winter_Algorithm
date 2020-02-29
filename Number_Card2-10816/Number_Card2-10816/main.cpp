//
//  main.cpp
//  Number_Card2-10816
//
//  Created by yoon tae soo on 2020/02/16.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
이분탐색 문제였다.
예전에 이분탐색에 대해서 잘 모를 때는 어려웟지만 지금은 그냥그랬다. 40분 정도에 문제 해결을 완료 했다.
*/


vector<int> v;

int Bineary_Search(int start, int end, int find){
    
    int mid;
    int cnt = 0;
    while(start <= end){
        mid = (start + end)/2;
        
        //같은 값일 경우에
        if(v[mid] == find){
            int temp = mid;
            //찾으려는 숫자의 맨 아래쪽 위치를 찾고
            while(v[temp] == find && temp >= 0){
                     //cout << mid << endl;
                temp--;
                cnt++;
            }
            
            temp = mid+1;
            //찾으려는 숫자의 맨 위쪽을 찾는다.
            while(v[temp] == find && temp <v.size()){
                temp++;
                cnt++;
            }
            
            //갯수를 출력해준다.
            return cnt;
            
        }
        else if(v[mid] > find){
            end = mid - 1;
        }
        else if(v[mid] < find){
            start = mid +1;
        }
        
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int N, item;
    //이진트리 구조로 되어 있는 map을 사용해서 중복된 숫자가 존재한다면 빠른 시간에 답이 나오도록 하였다.
    map<int,int> map_tree;
    //cin >> N;
    scanf("%d", &N);
    
    for(int i =0; i< N; i++){
        scanf("%d", &item);
        v.push_back(item);
    }
    
    //숫자를 정렬해준다.
    sort(v.begin(), v.end());
    
    
    int M;
    cin >> M;
    
    for(int i = 0; i<M; i++){
        scanf("%d", &item);
        
        //map에 존재한다면 그 value값을 출력해준다.
        if(map_tree.count(item) == 1){
            printf("%d ", map_tree[item] );
        }
        else{
            //이진 탐색으로 갯수를 출력해주고
            int anw = Bineary_Search(0, v.size()-1, item);
            printf("%d ", anw);
            //map에 저장해준다.
            map_tree.insert(make_pair(item, anw));
  
        }
        
    }

    return 0;
}
