//
//  main.cpp
//  Maximum Edge Removal
//
//  Created by Giriraj Saigal on 01/06/21.
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

int count(int cur, int &ans, map<int, vector<int>> mp, vector<int> vis) {
    vis[cur] = 1;
    vector<int> x = mp[cur];
    int next = 0;
    int k = 0;
    
    for(int i = 0; i < x.size(); i++) {
        int t = x[i];
        if(vis[t] == 1)
            continue;

        next = count(x[i], ans, mp, vis);
        
        if(next % 2 == 0)
            ans++;
        
        k+=next;
    }
    
    return 1 + k;
}

int solve(int A, vector<vector<int> >B) {
    if(A == 2)
        return 0;
        
    map<int, vector<int>> mp;
    
    for(int i = 0; i < B.size(); i++) {
        mp[B[i][0]].push_back(B[i][1]);
        mp[B[i][1]].push_back(B[i][0]);
    }
    
    int ans = 0;
    vector<int> visited(A+1, 0);
    count(1, ans, mp, visited);
    return ans;
}

int main(int argc, const char * argv[]) {
    solve(6,
          {
        {1, 2},
            {1, 3},
                {1, 4},
                    {3, 5},
                        {4, 6}
                        });
    return 0;
}
