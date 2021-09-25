//
//  main.cpp
//  Knight On Chess Board
//
//  Created by Giriraj Saigal on 25/09/21.
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

vector<int> Xs;
vector<int> Ys;
int knight(int A, int B, int C, int D, int E, int F) {
    Xs = {1,  1, 2,  2, -1, -1, -2, -2};
    Ys = {2, -2, 1, -1,  2, -2,  1, -1};
    vector<vector<int>> dp(A+1, vector<int>(B+1, INT_MAX));
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
    q.push({0, {C,D}});
    dp[C][D] = 0;
    
    while(q.size() > 0) {
        int d = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        
        for(int g = 0 ; g < 8; g++) {
            int nx = x + Xs[g];
            int ny = y + Ys[g];
            if(nx >= 1 && nx <= A && ny >= 1 && ny <= B && d+1 < dp[nx][ny]) {
                dp[nx][ny] = d+1;
                q.push({d+1, {nx,ny}});
            }
        }
    }
    
    if(dp[E][F] == INT_MAX)
        return -1;
    
    return dp[E][F];
}


int main(int argc, const char * argv[]) {
    cout << knight(8,8,1,1,8,8) << endl;
    return 0;
}
