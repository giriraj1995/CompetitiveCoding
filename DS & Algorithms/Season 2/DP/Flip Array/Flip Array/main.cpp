//
//  main.cpp
//  Flip Array
//
//  Created by Giriraj Saigal on 05/08/21.
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

int ans;
int f;

int solve1(const vector<int> &A, int i, int sum, int flips) {
    if(i == A.size()){
        if(abs(sum) < abs(ans)){
            ans = sum;
            if(flips < f)
                f = flips;
            return f;
        }
        return INT_MAX;
    }
    
    int ele = A[i];
    int p = ele + sum;
    int n = -ele + sum;
    
    int po = solve1(A, i+1, p, flips);
    int ne = solve1(A, i+1, n, flips+1);
    
    return min(po, ne);
}

int solve(const vector<int> A) {
    ans = INT_MAX;
    f = INT_MAX;
    solve1(A, 0, 0, 0);
    return f;
}


int main(int argc, const char * argv[]) {
    cout << solve({14, 10, 4}) << endl;
    return 0;
}
