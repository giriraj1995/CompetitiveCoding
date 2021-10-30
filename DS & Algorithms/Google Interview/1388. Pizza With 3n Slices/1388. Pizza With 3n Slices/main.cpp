//
//  main.cpp
//  1388. Pizza With 3n Slices
//
//  Created by Giriraj Saigal on 30/10/21.
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

vector<vector<int>> dp2;
int solve2(vector<int> &slices, int n, int size, int p) {
        if(n >= size && p != 0)
            return INT_MIN;
        
        if(n >= size && p == 0)
            return 0;
        
        if(dp2[n][p] != -1)
            return dp2[n][p];
        
        //take
        int x = solve2(slices, n+2, size, p-1);
        
        //skip
        int y = solve2(slices, n+1, size, p);
        
        if(x == INT_MIN && y == INT_MIN)
            return INT_MIN;
        
        if(y == INT_MIN)
            return slices[n] + x;
        
        if(x == INT_MIN)
            return y;
        
        return dp2[n][p] = max(slices[n] + x,y);
    }
    
    int maxSizeSlices(vector<int> slices) {
        int n = slices.size();
        dp2 = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        int x = solve2(slices, 0, n-1, n/3);
        dp2 = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        int y = solve2(slices, 1, n, n/3);
        return max(x,y);
    }


int main(int argc, const char * argv[]) {
    cout << maxSizeSlices({3,5,4,4,6,6,3,4,4,7,10,5,7,2,2});
    return 0;
}
