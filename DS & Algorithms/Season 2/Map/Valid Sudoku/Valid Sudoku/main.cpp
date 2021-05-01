//
//  main.cpp
//  Valid Sudoku
//
//  Created by Giriraj Saigal on 01/05/21.
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

int isValidSudoku(const vector<string> A) {
    vector<vector<bool>> bl(9, vector<bool>(9, false));
    vector<vector<bool>> rw(9, vector<bool>(9, false));
    vector<vector<bool>> cl(9, vector<bool>(9, false));
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            
            if(A[i][j] == '.')
                continue;
                
            int p = i/3;
            int q = j/3;
            int x = 3*p + q;
            int ele = (A[i][j] - '0') - 1;
            
            if(bl[x][ele] || rw[i][ele] || cl[j][ele])
                return 0;
            
            bl[x][ele] = true;
            rw[i][ele] = true;
            cl[j][ele] = true;
        }
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    isValidSudoku({
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"});
    return 0;
}
