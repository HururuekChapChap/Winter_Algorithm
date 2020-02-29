//
//  main.cpp
//  Friend_Network-4195
//
//  Created by yoon tae soo on 2020/01/16.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

/*
 
 이 문제 흠,,,, 왜 런타임 에러가 나는지와, 왜 시간 초과가 나는지 알아냈다 ㅎㅎㅎ
 일단 처음으로 Union-Find랑 map STL을 사용해서 문제를 풀어서 시간이 쫌 오래걸렸다.
 
 map 알고리즘은 이진탐색 트리의 형태로 두개의 데이터를 저장하여 key값과 value값으로 이루어진다.
 다른 STL과 다르게 포인터를 활용해서 사용하는 것이기 때문에, 사용방법이 조금 달랐다.
 
 일단 존재 여부를 판단할 때, network.count(name1) 이런 식으로 1 또는 0으로 표시해준다.multimap이 아니기 때문에
 다양한 값을를 가질 수 없어서 count로 존재 여부를 판단한다. 탐색 여부는 그냥 배열로 하는게 가능하다.
 이때, 배열 처럼 사용이 가능하다.network[key값]. 힘들게 반복문으로 해줄 필요가 없다.
 
 for(auto item = network.begin(); item != network.end(); item++){
         
         if((*item).first == name1){
             temp_a =(*item).second;
         }
        
 }
 
 이런 식으로 반복문을 돌리 수도 있다.
 
 이 문제에서는 scanf를 사용해야한다 . 따라서 string을 scanf로 입력 받기로 했는데, xcode에서는 잘 돌아갔으나,
 백준에서는 런타임 에러가 나왔다. 왜 나왔는가를 생각해보니, scanf는 string 자료형을 받지 못한다. 따라서 런타임 에러가 계속 나왔다.
 
 시간초과 같은 경우는 For문을 돌려주는데, 이게 시간이 엄청 오래 걸렸다... 그래서 map 탐색방법을 저렇게 배열 형식으로 바꿔주니 괜찮아졌다.
 
 문제는 그렇게 많이 어려운 편은 아니였다.
 
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int> network;
int Arr[200003];
int anw[200003];

int GetParent(int a){
    if(Arr[a] == a) return a;
    return Arr[a] = GetParent(Arr[a]);
}

void Union(int a, int b, int cnt){
    
    int temp_a = GetParent(a);
    int temp_b = GetParent(b);
    
    if(temp_a < temp_b){
        
        for(int i=1; i<cnt; i++){
            
            if(Arr[i] == temp_b){
               
                 Arr[i] = temp_a;
            }
        }
        
    }
    else{
        for(int i=1; i<cnt; i++){
            if(Arr[i] == temp_a){
                
                Arr[i] = temp_b;
                  }
              }
    }
    
}


int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    while(T>0){
    
    
    int N;
    char name1[30], name2[30];
    cin >> N;
    
    for(int i = 0; i<200001; i++){
        Arr[i] = i;
        anw[i] = 1;
    }
    
    network.clear();
 
    int cnt = 1;
    for(int i = 0; i<N; i++){
        //cin >> name1 >> name2;
        scanf("%s",name1);
        scanf("%s",name2);
         int temp_a = 0, temp_b = 0;
        
        if(network.count(name1) == 0 && network.count(name2) == 0){
            temp_a = cnt;
            network.insert(make_pair(name1, temp_a));
            cnt++;
            temp_b = cnt;
            network.insert(make_pair(name2, temp_b));
            
            cnt++;
           
        }
        else if(network.count(name1) == 1 && network.count(name2) == 1){
            
            /*
            for(auto item = network.begin(); item != network.end(); item++){
                
                if((*item).first == name1){
                    temp_a =(*item).second;
                }
                
                if((*item).first == name2){
                    temp_b =(*item).second;
                }
            
        }
             */
            
             
            temp_a = network[name1];
            temp_b = network[name2];
           
        
    }
      else if(network.count(name1) == 1 && network.count(name2) == 0){
          
          /*
          for(auto item = network.begin(); item != network.end(); item++){
                  
                  if((*item).first == name1){
                      temp_a =(*item).second;
                      break;
                  }
                  
          }
           */
          
          temp_a = network[name1];
          
          temp_b = cnt;
          network.insert(make_pair(name2, temp_b));
          cnt++;
         
          
            
        }
      else if(network.count(name1) == 0 && network.count(name2) == 1){
          
          /*
          for(auto item = network.begin(); item != network.end(); item++){
                
                  if((*item).first == name2){
                      temp_b =(*item).second;
                      break;
                  }
              
          }
           */
          
          temp_b = network[name2];
          
          temp_a = cnt;
          network.insert(make_pair(name1, cnt));
          cnt++;
         
      }
        
         Union(temp_a,temp_b,cnt);
        
        int temp = GetParent(temp_a);
        int total = 0;
        for(int i = 1; i<cnt; i++){
            //cout << Arr[i] << " ";
            if(Arr[i] == temp){
                total++;
            }
        }
        
        printf("%d\n",total) ;
        
    
    }
     
        T--;
    }
    return 0;
}
