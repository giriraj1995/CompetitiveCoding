//
//  main.cpp
//  Max Rectabgle
//
//  Created by Giriraj Saigal on 01/12/21.
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
    vector<int> findleft(vector<int> x) {
        stack<int> s;
        int n = x.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(s.size() == 0)
                ans.push_back(-1);
            else if(x[s.top()] < x[i]) {
                ans.push_back(s.top());
            }else{
                while(s.size() > 0 && x[s.top()] >= x[i])
                    s.pop();
                
                if(s.size() == 0)
                    ans.push_back(-1);
                else{
                    ans.push_back(s.top());
                }
            }
            
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> findright(vector<int> x) {
        stack<int> s;
        int n = x.size();
        vector<int> ans;
        
        for(int i = n-1; i >= 0; i--) {
            if(s.size() == 0)
                ans.push_back(n);
            else if(x[s.top()] < x[i]) {
                ans.push_back(s.top());
            }else{
                while(s.size() > 0 && x[s.top()] >= x[i])
                    s.pop();
                
                if(s.size() == 0)
                    ans.push_back(n);
                else{
                    ans.push_back(s.top());
                }
            }
            
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int maxArea(vector<int> x) {
        vector<int> left = findleft(x);
        vector<int> right = findright(x);
        int n = x.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * x[i]);
        }
        
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        
        if(n == 0)
            return 0;
        
        
        int m = matrix[0].size();
        
        if(m == 0)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = matrix[i][j] - '0';
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(dp[i][j] == 1) {
                    dp[i][j] = dp[i][j-1] + dp[i][j];
                }
            }
        }
        
        
    //dp: {
        //{1, 0, 1, 0, 0},
        //{1, 0, 1, 2, 3},
        //{1, 2, 3, 4, 5},
        //{1, 0, 0, 1, 0}}
    
        int ans = 0;
        for(int c1 = 0; c1 < m; c1++) {
            vector<int> x;
            for(int i = 0; i < n; i++) {
                x.push_back(dp[i][c1]);
            }
            ans = max(ans, maxArea(x));
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
