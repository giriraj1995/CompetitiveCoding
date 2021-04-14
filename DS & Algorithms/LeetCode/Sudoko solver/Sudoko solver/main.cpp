//
//  main.cpp
//  Sudoko solver
//
//  Created by Giriraj Saigal on 11/04/21.
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

    bool check(vector<vector<char>>& board, int &x, int &y) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.'){
                    x = i;
                    y = j;
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isSafe(vector<vector<char>>& board, int ele, int x, int y) {
        for(int i = 0; i < 9; i++) {
            if(board[i][y] == ele+'0') {
                return false;
            }
        }
        
        for(int j = 0; j < 9; j++) {
            if(board[x][j] == ele+'0') {
                return false;
            }
        }
        
        int i = x/3;
        int j = y/3;
        
        for(int p = i*3; p < i*3+3; p++) {
            for(int q = j*3; q < j*3+3; q++) {
                if(board[p][q] == ele+'0') {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        int x;
        int y;
        
        if(check(board, x, y)) {
            return true;
        }
        

        for(int k = 1; k <= 9; k++) {
            if(isSafe(board, k, x, y)) {
                board[x][y] = k+'0';
                if(solve(board)) {
                    return true;
                }else{
                    board[x][y] = '.';
                }
            }
        }

        
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','3','.','.','7','9'}};
    
    solveSudoku(board);
    cout<<"Wait";
    return 0;
}
