//
//  main.cpp
//  DFS
//
//  Created by Giriraj Saigal on 26/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

void solve(vector<int> g[], int N, vector<int> &ans, vector<int> &v, int node){
    
    v[node] = 1;
    
    vector<int> d = g[node];
    ans.push_back(node);
    
    for(int y = 0; y < d.size(); y++){
        if(v[d[y]] == 0){
            solve(g,N,ans,v,d[y]);
        }
    }
    
}

vector <int> dfs(vector<int> g[], int N)
{
    
    vector<int> ans;
    vector<int> v(N, 0);
    solve(g, N, ans, v, 0);
    return ans;
    // Your code here

}

int main(int argc, const char * argv[]) {

    return 0;
}
