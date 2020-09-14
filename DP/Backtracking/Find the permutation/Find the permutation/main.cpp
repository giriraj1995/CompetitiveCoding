//
//  main.cpp
//  Find the permutation
//
//  Created by Giriraj Saigal on 14/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

bool allOnes(vector<int> k){
    for(int i : k)
    {
        if(i != 1)
            return false;
    }
    return true;
}

void solve1(vector<int> input, vector<int> &k,vector<int> &out, map<vector<int>, int> &u){

    if(allOnes(k)){
        int ans = INT_MAX;

        for(int i = 0; i < out.size()-1; i++){
            ans = min(ans, abs(out[i] - out[i+1]));
        }

        u.insert(make_pair(out, ans));
        return;
    }
    
    for(int i = 0; i < input.size(); i++){
        if(k[i] == 0){
            k[i] = 1;
            out.push_back(input[i]);
            solve1(input, k, out, u);
            out.pop_back();
            k[i] = 0;
        }
    }

}

// Complete the solve function below.
vector<int> solve(int n, long k) {
    vector<int> input;

    for(int i = 1; i <= n; i++){
        input.push_back(i);
    }
    vector<int> out;
    vector<int> k1(n,0);
    map<vector<int>, int> u;
    solve1(input, k1, out, u);
    
    map<vector<int>, int>::iterator itr;
    int m = INT_MIN;
    vector<int> ans;
    
    for(itr = u.begin(); itr != u.end(); ++itr){
        m = max(m, itr->second);
    }
    
    itr=u.begin();
    
    while(k && itr != u.end()){
        
        if(itr->second == m){
            ans = itr->first;
            k--;
        }
        ++itr;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve(4,2);
    return 0;
}
