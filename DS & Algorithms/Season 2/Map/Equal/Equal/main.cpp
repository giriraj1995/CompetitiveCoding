//
//  main.cpp
//  Equal
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

vector<int> equal(vector<int> A) {
    
    map<int, int> mp;
    set<vector<int>> ans;
    
    for(int i = 0; i < A.size()-3; i++) {
        for(int j = i+1; j < A.size()-2; j++) {
            long long sum = A[i] + A[j];
            mp.clear();
            for(int k = i+1; k < A.size(); k++) {
                
                if(k == j)
                    continue;
                
                if(mp.find(sum - A[k]) != mp.end()) {
                    ans.insert({i,j,mp[sum-A[k]],k});
                }
                
                if(mp.find(A[k]) == mp.end())
                    mp[A[k]] = k;
            }
        }
    }
    vector<int> x;
    return (ans.size() == 0) ? x : *(ans.begin());
}


int main(int argc, const char * argv[]) {
    vector<int> x = equal({9, 5, 4, 9, 3, 6, 8, 7, 1, 2, 8, 7, 2, 9, 7, 1, 3, 9, 7, 8, 1, 0, 5, 5 });
    return 0;
}
