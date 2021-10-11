//
//  main.cpp
//  1900. The Earliest and Latest Rounds Where Players Compete
//
//  Created by Giriraj Saigal on 10/10/21.
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

void find(vector<int> inp, vector<int> &vec, int st, int end, int fp, int sp, vector<vector<int>> &ans, bool &check) {
        
        if(st > end) {
            ans.push_back(inp);
            return;
        }
        
        if((vec[st] == fp && vec[end] == sp) ||
           (vec[st] == sp && vec[end] == fp)) {
            check = true;
            return;
        }
        
        if(vec[st] == fp || vec[end] == fp) {
            inp.push_back(fp);
            find(inp, vec, st+1, end-1, fp, sp, ans, check);
            inp.pop_back();
            
            if(check)
                return;
            return;
        }
    
        if(vec[st] == sp || vec[end] == sp) {
            inp.push_back(sp);
            find(inp, vec, st+1, end-1, fp, sp, ans, check);
            if(check)
                return;
            inp.pop_back();
            
            return;
        }
    
        
        int left = vec[st];
        int right = vec[end];
        
        if((left < fp && right < fp) || (left > sp && right > sp) ||
            (left > fp && right < sp && left < sp && right > fp)){
            inp.push_back(left);
            find(inp, vec, st+1, end-1, fp, sp, ans, check);
            if(check)
                return;
            inp.pop_back();
        }else{
            inp.push_back(left);
            find(inp, vec, st+1, end-1, fp, sp, ans, check);
            inp.pop_back();
            if(check)
                return;
            inp.push_back(right);
            find(inp, vec, st+1, end-1, fp, sp, ans, check);
            inp.pop_back();
        }
        
    }
    
map<vector<int>, vector<int>> dp;
    vector<int> solve(vector<int> &vec, int fp, int sp, int round) {

        if(dp.find(vec) != dp.end())
            return dp[vec];
        
        int n = vec.size();
        int i = 0;
        int j = n-1;
        bool check = false;
        vector<vector<int>> posiblesArrays;
        
        find({}, vec, i, j, fp, sp, posiblesArrays, check);
        
        if(check){
            return {round,round};
        }
        
        vector<int> ans = {INT_MAX,INT_MIN};
        
        for(auto k : posiblesArrays) {
            sort(k.begin(), k.end());
            vector<int> temp = solve(k, fp,sp, round+1);
            ans[0] = min(ans[0], temp[0]);
            ans[1] = max(ans[1], temp[1]);
        }
        
        return dp[vec] = {ans[0],ans[1]};
    }
    
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        dp.clear();
        vector<int> ans;
        
        vector<int> vec;
        for(int i = 1; i <= n; i++)
            vec.push_back(i);
        
        ans = solve(vec, firstPlayer, secondPlayer, 1);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<int> x = earliestAndLatest(11,2,4);
    return 0;
}
