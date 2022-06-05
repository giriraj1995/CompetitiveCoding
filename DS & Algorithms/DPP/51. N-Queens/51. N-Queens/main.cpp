//
//  main.cpp
//  51. N-Queens
//
//  Created by Giriraj Saigal on 04/06/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<vector<string>> ans;
bool check(int i, vector<vector<string>> board) {
    if(i == board.size()){
        ans = board;
        return true;
    }
    
    for(int j = 0; j < board[0].size(); j++) {
        int x = 0;
        
        for(x = 0; x < board.size(); x++) {
            if(board[x][j].compare("Q") == 0) {
                break;
            }
        }
        
        if(x != board.size()) {
            continue;
        }
        
        vector<int> Xs = {-1,-1, 1, 1};
        vector<int> Ys = {-1, 1,-1, 1};
        
        bool foundQ = false;
        for(int k = 0; k < 4; k++) {
            int nx = i + Xs[k];
            int ny = j + Ys[k];
            while(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if(board[nx][ny] == "Q") {
                    foundQ = true;
                    break;
                }
                nx += Xs[k];
                ny += Ys[k];
            }
            
            if(foundQ) {
                break;
            }
        }
        
        if(foundQ) {
            continue;
        }
        
        board[i][j] = "Q";
        if (check(i+1,board)) {
            return true;
        } else {
            board[i][j] = ".";
        }
    }
    
    return false;
}

vector<vector<string>> initBoard(int n) {
    vector<vector<string>> board(n, vector<string>(n, "."));
    if (check(0, board))
        return ans;
    
    return board;
}

vector<vector<string>> solveNQueens(int n) {
    return initBoard(n);
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> ans = solveNQueens(9);
    
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout <<ans[i][j] + " ";
        }
        cout << endl;
    }
    return 0;
}
