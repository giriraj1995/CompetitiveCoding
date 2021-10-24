//
//  main.cpp
//  1923. Longest Common Subpath
//
//  Created by Giriraj Saigal on 24/10/21.
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

int power(long long x, unsigned int y, int p)
    {
        int res = 1;     // Initialize result

        x = x % p; // Update x if it is more than or
                    // equal to p

        if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;

            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
    
    bool helper(int len, vector<vector<int>>& paths) {
        long long base = pow(10,5)+1;
        int mod = pow(2,30);
        set<int> ans;
        for(int i = 0; i < paths.size(); i++) {
            set<int> temp;
            long long currHash = 0;
            for(int j = 0; j < paths[i].size(); j++) {
                currHash = (currHash*base+paths[i][j]);
                if(j >= len){
                    currHash -= paths[i][j-len]*power(base,len,mod);
                }
                currHash = currHash%mod;
                if(j >= len-1)
                    temp.insert(currHash);
            }
            if(i == 0)
                ans = temp;
            else{
                set<int> x;
            set_intersection(temp.begin(), temp.end(), ans.begin(), ans.end(),
         inserter(x, x.begin()));
                ans = x;
            }
        }
        
        return ans.size() > 0;
    }
    
    int longestCommonSubpath(int n, vector<vector<int>> paths) {
        int r = INT_MAX;
        for(int i = 0; i < paths.size(); i++) {
            r = min(r, (int)paths[i].size());
        }
        
        int l = 0;
        
        while(l < r) {
            int m = l + (r-l+1)/2;
            if(helper(m, paths)) {
                l = m;
            }else{
                r = m-1;
            }
        }
        
        return l;
    }


int main(int argc, const char * argv[]) {
    longestCommonSubpath(5,
                         {{0,1,2,3,4},{2,3,4},{4,0,1,2,3}});
    return 0;
}
