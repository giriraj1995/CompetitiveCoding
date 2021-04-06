//
//  main.cpp
//  36. Valid Sudoko
//
//  Created by Giriraj Saigal on 05/04/21.
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

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> board) {
        vector<vector<int>> row(9, vector<int>(9,0));
        vector<vector<int>> col(9, vector<int>(9,0));
        vector<vector<int>> blk(9, vector<int>(9,0));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.')
                    continue;
                else{
                    if(row[i][board[i][j]-'0'-1] == 1)
                        return false;
                    else
                        row[i][board[i][j]-'0'-1] = 1;
                    
                    if(col[j][board[i][j]-'0'-1] == 1)
                        return false;
                    else
                        col[j][board[i][j]-'0'-1] = 1;
                        
                    int x = i/3;
                    int y = j/3;
                    
                    if(blk[3*x+y][board[i][j]-'0'-1] == 1)
                        return false;
                    else
                        blk[3*x+y][board[i][j]-'0'-1] = 1;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> x = {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
          ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
              ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
                  ,{'.','.','.','.','8','.','.','7','9'}};
                  Solution s;
    cout<<s.isValidSudoku(x);
    return 0;
}
