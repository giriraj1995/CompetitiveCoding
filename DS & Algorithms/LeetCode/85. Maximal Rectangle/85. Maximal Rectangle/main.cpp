//
//  main.cpp
//  85. Maximal Rectangle
//
//  Created by Giriraj Saigal on 29/05/21.
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

vector<int> left(vector<int> x) {
    stack<int> s;
    vector<int> ans;
    for(int i = 0; i < x.size(); i++) {
        if(s.size() == 0) {
            ans.push_back(-1);
        }else if(x[s.top()] < x[i]){
            ans.push_back(s.top());
        }else{
            while(s.size() > 0 && x[s.top()] >= x[i]) {
                s.pop();
            }
            
            if(s.size() == 0)
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        
        s.push(i);
    }
    
    return ans;
}

vector<int> right(vector<int> x) {
    stack<int> s;
    vector<int> ans;
    for(int i = x.size()-1; i >= 0; i--) {
        if(s.size() == 0) {
            ans.push_back(x.size());
        }else if(x[s.top()] < x[i]){
            ans.push_back(s.top());
        }else{
            while(s.size() > 0 && x[s.top()] >= x[i]) {
                s.pop();
            }
            
            if(s.size() == 0)
                ans.push_back(x.size());
            else
                ans.push_back(s.top());
        }
        
        s.push(i);
    }
    
reverse(ans.begin(), ans.end());
    return ans;
}

int maximalRectangle(vector<vector<char>> M) {
    vector<vector<int>> x(M.size(), vector<int>(M[0].size()));
    
    for(int j =0; j < (int)M[0].size(); j++) {
        x[0][j] = M[0][j] - '0';
    }
    
    for(int i=1; i < (int)M.size(); i++) {
        for(int j =0; j < (int)M[0].size(); j++) {
            if((M[i][j] - '0') == 0)
                x[i][j] = 0;
            else
                x[i][j] = (M[i][j] - '0') + x[i-1][j];
        }
    }
    
    long long ans = 0;
    
    for(int i = 0; i < (int)M.size(); i++) {
        vector<int> l = left(x[i]);
        vector<int> r = right(x[i]);
    
        for(int j = 0; j < M[0].size(); j++) {
            ans = max(ans, (long long)((r[j] - l[j] - 1) * x[i][j]));
        }
     }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    maximalRectangle({
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    });
    return 0;
}
