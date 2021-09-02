//
//  main.cpp
//  Max Sum Triplet
//
//  Created by Giriraj Saigal on 02/09/21.
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

int solve(vector<int> A) {
    int n = A.size();
    if(n < 3)
        return 0;
    int ans = 0;
    vector<int> right(n, -1);
    
    for(int i = n-2; i > 0; i--) {
        if(A[i] < max(A[i+1],right[i+1]))
            right[i] = max(A[i+1],right[i+1]);
    }
    
    set<int> s;
    s.insert(A[0]);
    for(int i = 1; i < n-1; i++) {
        if(right[i] != -1){
            if(s.lower_bound(A[i]) != s.begin()) {
                ans = max(ans, *(--(s.lower_bound(A[i]))) + A[i] + right[i]);
            }
        }
        s.insert(A[i]);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve({2,5,3,1,4,9});
    return 0;
}
