//
//  main.cpp
//  Delete Edge!
//
//  Created by Giriraj Saigal on 23/09/21.
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

long long sum = 0;
map<int,vector<int>> mp;
int mod = 1e9+7;
vector<int> val;
long long ans;

long long solve(int u, vector<int> &visited) {
    long long temp = 0;
    long long sum_local = 0;
    visited[u] = 1;
    for(int v : mp[u]) {
        if(visited[v] == 0){
            temp = solve(v,visited);
            sum_local += temp;
            ans = max(ans, ((sum-temp) * temp)% mod);
        }
    }
    return sum_local+val[u];
}

int deleteEdge(vector<int> A, vector<vector<int> > B) {
    long long k = 0;
    for(int i : A) {
        k += i;
    }
    ans = 0;
    val = A;
    sum = k;
    ans = 0;
    
    mp.clear();
    for(int i = 0; i < B.size(); i++) {
        int x = B[i][0]-1;
        int y = B[i][1]-1;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    
    vector<int> visited(A.size(), 0);
    solve(0, visited);
    return ans;
}


int main(int argc, const char * argv[]) {
    cout << deleteEdge({42, 468, 335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282},
               {
                 {10, 6},
                 {3, 2},
                 {12, 7},
                 {9, 5},
                 {2, 1},
                 {8, 3},
                 {7, 1},
                 {4, 2},
                 {6, 3},
                 {11, 4},
                 {5, 3},
                 {13, 11},
    }) << endl;
    return 0;
}
