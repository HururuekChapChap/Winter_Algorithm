//
//  main.cpp
//  Number_Card-10815
//
//  Created by yoon tae soo on 2020/01/30.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <map>

/*
 이분 탐색 문제였다. 다만 다는 이진탐색을 사용하는 방법을 사용하였다.
 이진 탐색도 logN이라는 시간 복잡도를 가지기 때문에, map에 넣어주고
 존재한다면 1을 출력해준다.
 */

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N,item;
    map<int, int> card;
    cin >> N;
    for(int i = 0; i<N; i++){
        //cin >> item;
        scanf("%d", &item);
        card.insert(make_pair(item, 1));
    }
    
    int M;
    cin >> M;
    
    for(int i=0; i<M;i++){
        //cin >> item;
        scanf("%d", &item);
        printf("%d ",card.count(item));
    }
    return 0;
}
