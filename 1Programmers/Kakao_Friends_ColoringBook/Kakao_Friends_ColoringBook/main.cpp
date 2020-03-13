//
//  main.cpp
//  Kakao_Friends_ColoringBook
//
//  Created by yoon tae soo on 2020/03/05.
//  Copyright © 2020 yoon tae soo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Data{
    public:

    int x;
    int y;

};

int visited[100][100] = {0};
int UD[4] = {0,0,1,-1};
int LR[4] = {1,-1,0,0};

int BFS(int x, int y, int m, int n, vector<vector<int>> picture){

    queue<Data> q;
    visited[y][x] = 1;
    int current_number = picture[y][x];
    int cnt = 1;
    q.push({x,y});

    while(!q.empty()){

        int x = q.front().x;
        int y = q.front().y;

        q.pop();

        for(int i=0; i<4; i++){

            int next_x = x + LR[i];
            int next_y = y + UD[i];

            if(next_x>=0 && next_x<n && next_y>=0 && next_y < m){

                if(visited[next_y][next_x] == 0 && picture[next_y][next_x] == current_number ){
                    visited[next_y][next_x] = 1;
                    cnt++;
                    q.push({next_x,next_y});
                }
            }

        }


    }

    return cnt;

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i =0; i<m; i++){
        for(int j = 0; j< n; j++){

            if(picture[i][j] != 0 && visited[i][j] == 0){
                number_of_area++;
                int temp = BFS(j,i,m,n,picture);

                if(temp > max_size_of_one_area ){
                    max_size_of_one_area = temp;
                }

            }

        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    //cout << answer[0] << " " << answer[1];

    return answer;
}

int main(){

    int m,n;
    vector<vector<int>> picture;
    vector<int> answer;
    cin >> m >> n;
    
    picture.resize(m);

    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            int item;
            cin >> item;
            picture[i].push_back(item);
        }
    }

    answer = solution(m,n,picture);

}
