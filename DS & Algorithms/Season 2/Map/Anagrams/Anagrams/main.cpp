//
//  main.cpp
//  Anagrams
//
//  Created by Giriraj Saigal on 02/05/21.
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

vector<vector<int> > anagrams(const vector<string> &A) {
    vector<vector<int>> ans;
    int n = A.size();
    
    if(n == 0)
        return {};
    
    map<string, vector<int>> mp;
    
    for(int i = 0; i < n; i++) {
        string k = A[i];
        sort(k.begin(), k.end());
        mp[k].push_back(i+1);
    }
    
    for(auto i : mp)
        ans.push_back(i.second);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
