//
//  main.cpp
//  Reduce Array Size to The Half
//
//  Created by Giriraj Saigal on 06/07/21.
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

vector<vector<long>> dp;
    map<long, long> mp;
    int n;
    vector<long> l;
    long solve(long x, vector<long> inp, long i) {
        if(dp[x][i] != -1)
            return dp[x][i];
        if(x/1.0 >= n/2.0) {
            return dp[x][i] = (int)inp.size();
        }
        
        if(i == l.size())
            return dp[x][i] = INT_MAX;
        
        inp.push_back(l[i]);
        long a = solve(x+mp[l[i]], inp, i+1);
        inp.pop_back();
        
        long b = solve(x, inp, i+1);
        
        return dp[x][i] = min(a,b);
    }
    
    int minSetSize(vector<int> arr) {
        mp.clear();
        for(int i : arr)
            mp[i]++;
                
        for(auto y : mp)
            l.push_back(y.first);
        
        n = (int)arr.size();
        dp = vector<vector<long>>(n+1, vector<long>(n+1, -1));
        return (int)solve(0, {}, 0);
    }

int main(int argc, const char * argv[]) {
    cout << minSetSize({1,2,3,4,5,6,7,8,9,10}) << endl;
    return 0;
}
