//
//  main.cpp
//  Pascal's Triangle
//
//  Created by Giriraj Saigal on 22/06/21.
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

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    
    for(int i = 0; i < numRows; i++) {
        vector<int> inp = vector<int>(i+1,1);
        
        for(int j = 1; j < i; j++) {
            inp[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        
        ans[i] = inp;
    }
    
    return ans;
}

vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex+1, 1);
    
    for(int i = 2; i <= rowIndex; i++) {
        for(int j = i-1; j >= 1; j--) {
            ans[j] = ans[j] + ans[j-1];
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
