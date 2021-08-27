//
//  main.cpp
//  Water Flow
//
//  Created by Giriraj Saigal on 27/08/21.
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

int ans;
void flow(int i, int j, vector<vector<int> > &A, vector<vector<int>> &visited, vector<vector<int>> &matrix) {
    
    if(visited[i][j] == 1)
        return;
    
    vector<int> Xs = {1, 0, 0, -1};
    vector<int> Ys = {0, -1, 1, 0};
    
    matrix[i][j] += 1;
    visited[i][j] = 1;
    
    if(matrix[i][j] == 2)
        ans++;
    
    for(int k = 0; k < 4; k++) {
        int x = i+Xs[k];
        int y = j+Ys[k];
        
        if(x >= 0 && x < A.size() && y >= 0 && y < A[0].size() && visited[x][y] == 0 && A[x][y] >= A[i][j]) {
            flow(x, y, A, visited, matrix);
        }
    }
    
}

int solve(vector<vector<int> > A) {
    int n = (int)A.size();
    int m = (int)A[0].size();
    ans = 0;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    for(int i = 0; i < A.size(); i++) {
        flow(i, 0, A, visited, matrix);
    }
    
    for(int j = 0; j < A[0].size(); j++){
        flow(0, j, A, visited, matrix);
    }
    
    visited = vector<vector<int>>(n, vector<int>(m, 0));

    for(int i = (int)A.size()-1; i >= 0; i--) {
        flow(i, (int)A[0].size()-1, A, visited, matrix);
    }
    
    for(int j = 0; j < A[0].size(); j++){
        flow((int)A.size()-1, j, A, visited, matrix);
    }
     
    return ans;
}


int main(int argc, const char * argv[]) {
    cout << solve({
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
                        }) << endl;
    return 0;
}
