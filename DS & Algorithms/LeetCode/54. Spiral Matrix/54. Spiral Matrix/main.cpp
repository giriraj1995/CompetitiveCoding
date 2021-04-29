//
//  main.cpp
//  54. Spiral Matrix
//
//  Created by Giriraj Saigal on 29/04/21.

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
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> ans;
        int n = ma.size();
        int m = ma[0].size();
        
        vector<vector<int>> ref(n, vector<int>(m, -1));
        int i = 0;
        int j = 0;
        int k = 0;
        ans.push_back(ma[0][0]);
        ref[i][j] = 1;
        while(1) {
            while(j+1 < m && ref[i][j+1] == -1) {
                j++;
                ref[i][j] = 1;
                ans.push_back(ma[i][j]);
                k++;
            }
            
            while(i+1 < n && ref[i+1][j] == -1) {
                i++;
                ref[i][j] = 1;
                ans.push_back(ma[i][j]);
                k++;
            }
            
            while(j-1 >= 0 && ref[i][j-1] == -1) {
                j--;
                ref[i][j] = 1;
                ans.push_back(ma[i][j]);
                k++;
            }
            
            while(i-1 >= 0 && ref[i-1][j] == -1) {
                i--;
                ref[i][j] = 1;
                ans.push_back(ma[i][j]);
                k++;
            }
            
            if(k == n*m-1)
                break;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {

    return 0;
}
