//
//  main.cpp
//  Word Search 2
//
//  Created by Giriraj Saigal on 08/11/21.
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

vector<int> Xs;
vector<int> Ys;
    

bool dfs(string word, int i, int x, int y, vector<vector<char>> &board, vector<vector<bool>> visited) {
    visited[x][y] = true;
    
    if(board[x][y] == word[i]) {
        
        if(i == word.size()-1)
            return true;
        
        for(int k = 0; k < 4; k++) {
            int nx = x + Xs[k];
            int ny = y + Ys[k];
            
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && visited[nx][ny] == false) {
                if(dfs(word, i+1, nx, ny, board, visited)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool isPresent(string word, vector<vector<char>> &board) {
    static string possibleStrings = "";
    
    if(possibleStrings.find(word) != string::npos) {
        return true;
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
            if(word[0] == board[i][j] && dfs(word, 0, i, j, board, visited)){
                possibleStrings = possibleStrings + "#" + word;
                return true;
            }
        }
    }
    
    return false;
}

vector<string> findWords(vector<vector<char>> board, vector<string> words) {
    Xs = {1,0,-1,0};
    Ys = {0,1,0,-1};
    
    vector<string> ans;
    for(string word : words) {
        if(isPresent(word, board)) {
            ans.push_back(word);
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    findWords({{'a'}},
              {"b", "a"});
    return 0;
}
