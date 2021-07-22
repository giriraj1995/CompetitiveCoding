//
//  main.cpp
//  Merge elements
//
//  Created by Giriraj Saigal on 22/07/21.
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

map<string, pair<int,int>> mp;
int save(vector<int> &A, int i, int j, int &ans) {
    string key = to_string(i) + "_" + to_string(j);
    
    if(mp.find(key) != mp.end()){
        ans = mp[key].first;
        return mp[key].second;
    }
    
    if(i == j){
        mp[key] = {0, A[i]};
        ans = 0;
        return A[i];
    }
    
    if(j == i+1) {
        ans = A[i] + A[j];
        mp[key] = {ans, A[i]+A[j]};
        return A[i] + A[j];
    }
    
    int t = INT_MAX;
    
    for(int k = i; k < j; k++) {
        int costa = INT_MAX;
        int costb = INT_MAX;
        
        int a = save(A, i, k, costa);
        int b = save(A, k+1, j, costb);
        
        if(a+b+costa+costb < ans){
            ans = a+b+costa+costb;
            t = a+b;
        }
    }
    
    mp[key] = {ans, t};
    return t;
}
int solve(vector<int> A) {
    mp.clear();
    int ans = INT_MAX;
    save(A, 0, A.size()-1, ans);
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({1, 3, 7});
    return 0;
}
