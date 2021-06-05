//
//  main.cpp
//  89. Gray Code
//
//  Created by Giriraj Saigal on 05/06/21.
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

    void solve(set<int> &s, vector<int> &ans, int t, int n) {
        
        for(int i = 0; i < n; i++) {
            int x = (1<<i) ^ t;
            if(s.find(x) == s.end())
            {
                s.insert(x);
                ans.push_back(x);
                solve(s,ans,x,n);
            }
        }
        
    }
    vector<int> grayCode(int n) {
        set<int> s;
        vector<int> out;
        s.insert(0);
        out.push_back(0);
        int t = 0;
        solve(s,out,t,n);
        return out;
    }

int main(int argc, const char * argv[]) {
    grayCode(2);
    return 0;
}
