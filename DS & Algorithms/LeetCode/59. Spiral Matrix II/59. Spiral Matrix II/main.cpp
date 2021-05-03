//
//  main.cpp
//  59. Spiral Matrix II
//
//  Created by Giriraj Saigal on 02/05/21.
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

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, -1));
    int i = 0;
    int j = 0;
    int k = 1;
    ans[0][0] = 1;
    if(n == 1)
        return ans;
    while(1) {
        while(j+1 < n && ans[i][j+1] == -1) {
            j++;
            k++;
            ans[i][j] = k;
        }
        while(i+1 < n && ans[i+1][j] == -1) {
            i++;
            k++;
            ans[i][j] = k;
        }
        while(j-1 >= 0 && ans[i][j-1] == -1) {
            j--;
            k++;
            ans[i][j] = k;
        }
        while(i-1 >= 0 && ans[i-1][j] == -1) {
            i--;
            k++;
            ans[i][j] = k;
        }
        
        if(k == n*n)
            break;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    generateMatrix(5);
    return 0;
}
