//
//  main.cpp
//  Valid Path
//
//  Created by Giriraj Saigal on 16/09/21.
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

map<pair<int,int>, bool> mp;

void create(int x, int y, int n, double r, vector<int> xs, vector<int> ys) {
    
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            for(int k = 0; k < n; k++) {
                double d = sqrt(pow(i-xs[k],2) + pow(j-ys[k],2));
                if(d <= r) {
                    mp[{i,j}] = false;
                    break;
                }else{
                    mp[{i,j}] = true;
                }
            }
        }
    }
    
}

bool isSafe2(int x, int y, int n, double r, vector<int> xs, vector<int> ys) {

    for(int k = 0; k < n; k++) {
        double d = sqrt(pow(x-xs[k],2) + pow(y-ys[k],2));
        if(d <= r) {
            return false;
        }
    }
    
    return true;
}

bool isSafe(int x, int y) {
    return mp[{x,y}];
}

string solve(int A, int B, int C, int D, vector<int> E, vector<int> F) {
    mp.clear();
    create(A,B,C,D,E,F);
    
    if(!isSafe(0,0))
        return "NO";
        
    queue<pair<int,int>> qu;
    qu.push({0,0});
    
    vector<int> Xs = { 1,-1, 0, 0, 1,-1, 1,-1};
    vector<int> Ys = { 0, 0, 1,-1, 1,-1,-1, 1};
    vector<vector<int>> visited(A+1, vector<int>(B+1, 0));
    visited[0][0] = 1;
    while(qu.size() > 0) {
        int x = qu.front().first;
        int y = qu.front().second;
        // visited[x][y] = 1;
        qu.pop();
        
        if(x == A && y == B){
            return "YES";
        }
        
        for(int g = 0; g < 8; g++) {
            int p = x+Xs[g];
            int q = y+Ys[g];
            
            if(p >= 0 && q >= 0 && p <= A && q <= B && visited[p][q] == 0 && isSafe(p,q)){
                visited[p][q] = 1;
                qu.push({p,q});
            }
        }
    }
    
    return "NO";
}


int main(int argc, const char * argv[]) {
    cout << solve(41,67,5,0,{ 17, 16, 12, 0, 40 },{ 52, 61, 61, 25, 31 }) << endl;
    return 0;
}
