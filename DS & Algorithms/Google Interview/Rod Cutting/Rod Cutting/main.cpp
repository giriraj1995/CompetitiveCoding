//
//  main.cpp
//  Rod Cutting
//
//  Created by Giriraj Saigal on 23/10/21.
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
int count = 0;
unordered_map<string, int> dp;
unordered_map<string, long long> dpCost;

long long solve(int st, int en, vector<int> B) {
    string key = to_string(st) + "|" + to_string(en);
    
    if(abs(en-st) <= 1)
        return 0;
    
    if(dpCost.count(key)){
        return dpCost[key];
    }
    
    long long cost = LONG_MAX;
        
    for(int k = st+1; k < en; k++) {
        long long temp = B[en] - B[st] + solve(st, k, B) + solve(k, en, B);
        if(temp < cost) {
            dp[key] = k;
            cost = temp;
        }
    }
    
    return dpCost[key] = cost == LONG_MAX ? 0 : cost;
}

void fill(vector<int> &ans, int st, int en, vector<int> B) {
    string key = to_string(st) + "|" + to_string(en);
    if(abs(st-en) <= 1)
        return;
    ans.push_back(B[dp[key]]);
    fill(ans, st, dp[key], B);
    fill(ans, dp[key], en, B);
}

vector<int> rodCut(int A, vector<int> B) {
    B.push_back(0);
    B.push_back(A);
    sort(B.begin(), B.end());
    dpCost.clear();
    dp.clear();
    cout << solve(0, (int)B.size()-1, B);
    vector<int> ans;
    fill(ans, 0, B.size()-1, B);
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> t = rodCut(6, {1,2,5});
    return 0;
}
