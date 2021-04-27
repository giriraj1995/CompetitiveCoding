//
//  main.cpp
//  NQueensProblem
//
//  Created by Giriraj Saigal on 27/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;
bool isSafe(vector<string> vec, int i, int j, int A) {
    for(int x = 0; x < A; x++) {
        if(vec[x][j] == 'Q')
            return false;
    }
    
    for(int y = 0; y < A; y++) {
        if(vec[i][y] == 'Q')
            return false;
    }
    
    int x = i;
    int y = j;
    
    while(x >= 0 && y >= 0) {
        if(vec[x][y] == 'Q')
            return false;
        x--;
        y--;
    }
    
    x = i;
    y = j;
    
    while(x < A && y >= 0) {
        if(vec[x][y] == 'Q')
            return false;
        x++;
        y--;
    }
    
    x = i;
    y = j;
    
    while(x >= 0 && y < A) {
        if(vec[x][y] == 'Q')
            return false;
        x--;
        y++;
    }
    
    x = i;
    y = j;
    
    while(x < A && y < A) {
        if(vec[x][y] == 'Q')
            return false;
        x++;
        y++;
    }
    
    return true;
}

void solve(int A, vector<string> vec, vector<vector<string>> &ans, int row) {
    if(row == A) {
        ans.push_back(vec);
        return;
    }
    
    
    for(int j = 0; j < A; j++) {
        if(isSafe(vec, row, j, A)){
            vec[row][j] = 'Q';
            solve(A, vec, ans, row+1);
            vec[row][j] = '.';
        }
    }
    
    return;
}

vector<vector<string> > solveNQueens(int A) {
    string x = "";
    for(int i = 0; i < A; i++) {
        x = x + '.';
    }
    vector<vector<string>> ans;
    vector<string> vec(A, x);
    
    solve(A, vec, ans, 0);
    return ans;
}


int main(int argc, const char * argv[]) {
    solveNQueens(9);
    return 0;
}
