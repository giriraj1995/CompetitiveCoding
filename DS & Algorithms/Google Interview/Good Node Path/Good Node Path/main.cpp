//
//  main.cpp
//  Good Node Path
//
//  Created by Giriraj Saigal on 20/09/21.
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

const int maxNod = 10;
int limit;
int adj[maxNod];
int N;
vector<int> good;
int ans;

void find(int cur, int mask) {
    int Cs = 0;
    int next = 0;
    
    for(int i = 0; i < N; i++) {
        if((1<<i) & mask){
            if(good[i])
                Cs++;
        }
    }
    
    if(Cs > limit)
        return;
    
    next |= adj[cur];
    next = next ^ (next & mask);
    
    if(next == 0) {
        if(Cs <= limit)
            ans++;
            
        return;
    }
    
    for(int i = 0 ;i < N; i++) {
        if((1 << i) & next) {
            find(i, mask | (1<<i));
        }
    }
}

int solve(vector<int> A, vector<vector<int> > B, int C) {
    N = (int)A.size();
    ans = 0;
    int mask = 0;
    good = A;
    limit = C;
    memset(adj, 0, sizeof(adj));
    
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]-1] |= (1<<(B[i][1]-1));
        adj[B[i][1]-1] |= (1<<(B[i][0]-1));
    }
    
    find(0, 1);
    
    return ans;
}



int main(int argc, const char * argv[]) {
    cout << solve({0, 1, 0, 1, 1, 1},{{1, 2},{1, 5},{1, 6},{2, 3},{2, 4}},1) << endl;
    return 0;
}
