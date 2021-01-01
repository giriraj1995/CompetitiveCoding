//
//  main.cpp
//  Sudoko
//
//  Created by Giriraj Saigal on 31/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#define N 9
using namespace std;

bool isSafe(vector<vector<int>> x, int i, int j, int ele) {
    
    for(int t = 0; t < N; t++) {
        if(x[t][j] == ele)
            return false;
        
        if(x[i][t] == ele)
            return false;
    }
    
    int p = i;
    int q = j;
    
    p = i - i%3;
    q = j - j%3;
    
    for(int a = p; a < p+3; a++) {
        for(int b = q; b < q+3; b++) {
            if(x[a][b] == ele)
                return false;
        }
    }
    
    return true;
}

void print(vector<vector<int>> x) {
    cout<<"-------------------------------------"<<endl;
    for(int i = 1; i <= N; i++) {
        cout<<"| ";
        
        for(int j = 1; j <= N; j++) {
            if(j % 3 == 0 && j != N){
                cout<<x[i-1][j-1]<<" | ";
            }else
            if(j == N)
                cout<<x[i-1][j-1];
            else
                cout<<x[i-1][j-1]<<"   ";
        }
        
        cout<<" |";
        cout<<endl;
        
        if(i % 3 == 0 && i != N) {
            cout<<"|-----------------------------------|"<<endl;

        }
    }
    cout<<"-------------------------------------"<<endl;

    cout<<endl;
}

bool check(vector<vector<int>> x ) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(x[i-1][j-1] == 0)
                return false;
        }
    }
    return true;
}

bool solveSudokoUtil(vector<vector<int>> &x) {
    
    if(check(x))
        return true;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            
            if(x[i][j] != 0){
                continue;
            }else{
                for(int k = 1; k <= N; k++) {
                    if(isSafe(x, i, j, k)) {
                        x[i][j] = k;
                        //print(x);
                        if(solveSudokoUtil(x)) {
                            return true;
                        }
                        x[i][j] = 0;
                    }
                }
                return false;
            }
            
            
        }
    }
    
    return false;
}

void solveSudoko(vector<vector<int>> x) {
    
    if(solveSudokoUtil(x)) {
        print(x);
    }else{
        return;
    }
    
}

bool validSudoko(vector<vector<int>> x) {
    vector<vector<int>> row(N+1, vector<int>(N+1, 0));
    vector<vector<int>> col(N+1, vector<int>(N+1, 0));
    vector<vector<int>> box(N+1, vector<int>(N+1, 0));
    
    for(int i = 1; i < N-1; i++) {
        for(int j = 1; j < N-1; j++) {
            
            int ele = x[i-1][j-1];
            
            int BoxNo = (((i-1)%3 + 1) * ((j-1)%3 + 1));
            
            if(row[i+1][ele] == 0 && col[j+1][ele] == 0 && box[BoxNo][ele] == 0) {
                row[i][ele] = 1;
                col[j][ele] = 1;
                box[BoxNo][ele] = 1;
            }else{
                return false;
            }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> x =
        {
            {3, 1, 6, 5, 7, 8, 4, 9, 2},
            {5, 2, 9, 1, 3, 4, 7, 6, 8},
            {4, 8, 7, 6, 2, 9, 5, 3, 1},
            {2, 6, 3, 4, 1, 5, 9, 8, 7},
            {9, 7, 4, 8, 6, 3, 1, 2, 5},
            {8, 5, 1, 7, 9, 2, 6, 4, 3},
            {1, 3, 8, 9, 4, 7, 2, 5, 6},
            {6, 9, 2, 3, 5, 1, 0, 7, 4},
            {7, 4, 5, 2, 8, 6, 3, 1, 1}
        };
    
    //print(x);
    validSudoko(x);
    return 0;
}
