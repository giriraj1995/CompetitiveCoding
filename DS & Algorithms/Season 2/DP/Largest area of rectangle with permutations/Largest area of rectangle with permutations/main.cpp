//
//  main.cpp
//  Largest area of rectangle with permutations
//
//  Created by Giriraj Saigal on 23/06/21.
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

int solve(vector<vector<int> > &A) {
    int n = A.size();

    if(n == 0)
        return 0;

    int m = A[0].size();

    if(m == 0)
        return 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] != 0)
                A[i][j] = A[i][j] + A[i-1][j];
        }
    }

    for(int i = 0; i < n; i++) {
        sort(A[i].rbegin(), A[i].rend());
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = max(ans, A[i][j] * (j+1));
        }
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
