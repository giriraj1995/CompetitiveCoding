//
//  main.cpp
//  Knights tour
//
//  Created by Giriraj Saigal on 13/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#define N 8
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> sol){
    
    if(i >= 0 && j >= 0 && i < N && j < N && sol[i][j] == -1)
        return true;
    
    return false;
}

void print(vector<vector<int>> sol){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            if(sol[i][j] < 0 || sol[i][j] > 9)
                cout<<sol[i][j]<<" ";
            else
                cout<<" "<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool nextMove(int x, int y, int move,vector<int> moveX, vector<int> moveY, vector<vector<int>> &sol){
    
    int nextX, nextY;
    
    if(move == N*N)
        return 1;
    
    for (int i = 0; i < 8; i++) {
        nextX = x + moveX[i];
        nextY = y + moveY[i];
        if(isSafe(nextX, nextY, sol)){
            sol[nextX][nextY] = move;
            print(sol);
            if(nextMove(nextX, nextY, move+1, moveX, moveY, sol)){
                return 1;
            }else
                sol[nextX][nextY] = -1;
        }
    }
    
    return 0;
}

void solveKT(){
    vector<int> m(N, -1);
    vector<vector<int>> sol(N, m);
    
    vector<int> moveX = { 1,  2,  1,  2, -1, -2, -1, -2};
    vector<int> moveY = { 2,  1, -2, -1,  2,  1, -2, -1};
    
    sol[0][0] = 0;
    
    if(!nextMove(0, 0, 1, moveX, moveY, sol)){
        cout<<"NOT EXIST"<<endl;
    }else
        print(sol);
    
}

int main(int argc, const char * argv[]) {
    solveKT();
    return 0;
}
