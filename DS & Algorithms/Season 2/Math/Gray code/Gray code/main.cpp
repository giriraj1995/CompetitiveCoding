//
//  main.cpp
//  Gray code
//
//  Created by Giriraj Saigal on 01/07/21.
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

void solve(int no, int n, vector<int> &ans, set<int> &s) {
        
        s.insert(no);
        ans.push_back(no);
        
        for(int i = 0; i < n; i++) {
            int x = no ^ (1<<i);
            
            if(s.find(x) == s.end())
                solve(x, n, ans, s);
            
        }
    }
    
    vector<int> grayCode(int n) {
        
        if(n == 0)
            return {};
        
        vector<int> ans;
        set<int> s;
        solve(0, n, ans, s);
        return ans;
    }

int main(int argc, const char * argv[]) {
    grayCode(6);
    return 0;
}
