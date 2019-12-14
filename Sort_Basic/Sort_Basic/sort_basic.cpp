//
//  main.cpp
//  Sort_Basic
//
//  Created by yoon tae soo on 2019/12/14.
//  Copyright © 2019 yoon tae soo. All rights reserved.
//

// 방학 첫쨋날, 새로운 마음 가집으로 정렬 알고리즘 (버블과 삽입)을 공부해서 정리하는 시간을 가져보는 시간을 가졌다.

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// 버블정렬 : 버블정렬은 자신 바로 뒤에 있는 것과 비교하는 방식이다. 이때, 점점 뒷 부분은 정렬 되는식이다. 따라서
// 계속 9 - i 씩 줄어가는 식으로 된다.

void Bubble_Sort(int arr[]){
    

    for(int i = 0 ; i < 9; i++){
        
        for(int j = 0 ; j< 9 - i; j++){
            int temp;
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }

        
    }
    
   for(int i =0; i<10; i++){
        cout << arr[i] << " ";
             }
    cout << endl;
    
    
}

// 삽입정렬 : 삽입 부분은 뒷 부분이 정렬되는 것을 가정하는 버블정렬과는 반대로 앞 부분이 정렬 되는 식으로 된다.
// 따라서 arr[j] > arr[j + 1] 이라면 계속 반복문을 돌려주는 것이다. 왜냐하면 앞 부분은 이미 정렬이 되어있다고 가정하기 때문이다.

void Insert_Sort(int arr[]){
    
    for(int i = 1; i< 10 ; i++){
        
        int temp = arr[i];
        
        for(int j = i - 1; j>=0 && arr[j] > arr[j+1] ; j--){
            arr[j+1] = arr[j];
            arr[j] = temp;
        }
        
    }
    
    for(int i =0; i<10; i++){
          cout << arr[i] << " ";
               }
      
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    int Bubble[10];
    int Insert[10];
    srand((unsigned)time(NULL));
    
    for(int i =0; i< 10; i++){
        Bubble[i] = (rand()%100) +1;
        Insert[i] = (rand()%100) + 1;
    }
    
    Bubble_Sort(Bubble);
    Insert_Sort(Insert);
  
    return 0;
}
