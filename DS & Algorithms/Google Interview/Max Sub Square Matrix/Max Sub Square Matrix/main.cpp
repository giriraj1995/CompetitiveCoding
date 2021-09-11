//
//  main.cpp
//  Max Sub Square Matrix
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

int solve(vector<vector<int> > A) {
    int n = (int)A.size();
    int m = (int)A[0].size();
    vector<vector<int> > B = A;
    
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(B[i][j] == 0){
                B[i][j] = 0;
                continue;
            }
            B[i][j] = B[i][j] + B[i+1][j];
        }
    }
    
    vector<vector<int> > C = A;
    for(int j = m-2; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            if(C[i][j] == 0){
                C[i][j] = 0;
                continue;
            }
            C[i][j] = C[i][j] + C[i][j+1];
        }
    }
    
    int ans = 0;
    for(int i = n-2; i >= 0; i--) {
        for(int j = m-2; j >= 0; j--) {
            int x = B[i][j];
            int y = C[i][j];
            int ele = min(x, y);
            
            if(ele == 0)
                continue;
            
            if(A[i+1][j+1] >= ele-1) {
                A[i][j] = ele;
                ans = max(ans, A[i][j]);
            }
        }
    }
    
    return ans*ans;
}


int main(int argc, const char * argv[]) {
    solve({
        {0,1,1,0,1},{1,1,0,1,0},{0,1,1,1,0},{1,1,1,1,0},{1,1,1,1,1},{0,0,0,0,0}
      });
    return 0;
}
