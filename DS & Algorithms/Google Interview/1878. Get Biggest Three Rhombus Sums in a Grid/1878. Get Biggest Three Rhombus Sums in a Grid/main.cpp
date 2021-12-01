//
//  main.cpp
//  1878. Get Biggest Three Rhombus Sums in a Grid
//
//  Created by Giriraj Saigal on 26/11/21.
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

void takecare(priority_queue<int> &q) {
        if(q.size() > 3)
            q.pop();
    }
    
vector<int> getBiggestThree(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        priority_queue<int> q;
    set<int> d;
        int t = 1;
        while(t <= min(n,m)){
            for(int i = 0+t-1; i < n-t+1; i++) {
                for(int j = 0+t-1; j < m-t+1; j++) {
                    int sum = 0;
                    int count = 0;
                    for(int x = 0; x < n; x++) {
                        for(int y = 0; y < m; y++) {
                            if(abs(x-i) + abs(y-j) == (t-1)) {
                                sum += grid[x][y];
                                count++;
                            }
                        }
                    }
                    if(count == t*t && d.count(sum) == 0){
                        q.push(-1*sum);
                        d.insert(sum);
                        takecare(q);
                    }
                }
            }
            t+=1;
        }
        
        vector<int> ans(q.size());
        int f = q.size();
        
        while(f > 0) {
            ans[f-1] = -1*q.top();
            q.pop();
            f--;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    getBiggestThree({
        {7,7,7}});
    return 0;
}
