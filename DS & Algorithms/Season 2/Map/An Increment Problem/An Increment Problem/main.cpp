//
//  main.cpp
//  An Increment Problem
//
//  Created by Giriraj Saigal on 06/05/21.
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

vector<int> solve(vector<int> A) {
    vector<int> ans;
    map<int,vector<int>> mp;
    int k = 0;
    
    for(int i = 0; i < A.size(); i++) {
        ans.push_back(A[i]);
        if(mp.find(A[i]) == mp.end())
        {
            mp[A[i]].push_back(k);
            k++;
        }
        else{
            mp[A[i]].push_back(k);
            int ind = mp[A[i]][0];
            ans[ind]++;
            mp[A[i]].erase(mp[A[i]].begin());
            
            if(mp[A[i]].size() == 0)
                mp.erase(A[i]);
            
            mp[ans[ind]].push_back(ind);
            sort(mp[ans[ind]].begin(), mp[ans[ind]].end());
            k++;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({1, 2, 3, 2, 3, 1, 4, 2, 1, 3});
    return 0;
}
