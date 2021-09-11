//
//  main.cpp
//  Kingdom war
//
//  Created by Giriraj Saigal on 11/09/21.
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

int solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    if(n == 1 && m == 1)
        return A[0][0];
        
    vector<vector<int>> B = A;
    int ans = A[0][0];
    
    for(int i = 0; i < n; i++) {
        ans = max(ans, A[i][m-1]);
    }
    
    for(int j = 0; j < m; j++) {
        ans = max(ans, A[n-1][j]);
    }
    
    for(int i = n-2; i >= 0 ; i--) {
        for(int j = 0; j < m; j++) {
            B[i][j] = B[i][j] + B[i+1][j];
            ans = max(ans, B[i][j]);
        }
    }
    
    B = A;
    
    for(int j = m-2; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            B[i][j] = B[i][j] + B[i][j+1];
            ans = max(ans, B[i][j]);
        }
    }
    
    for(int i = n-2; i >= 0 ; i--) {
        for(int j = 0; j < m; j++) {
            B[i][j] = B[i][j] + B[i+1][j];
            ans = max(ans, B[i][j]);
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
