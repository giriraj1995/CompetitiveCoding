//
//  main.cpp
//  Longest Increasing Subsequence
//
//  Created by Giriraj Saigal on 24/06/21.
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

int lis(const vector<int> &A) {
    vector<int> dp(A.size(), 1);
    int n = A.size();
    if(n == 0)
        return 0;
        
    int ans = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if((A[j] < A[i]) && (dp[j]+1 > dp[i])){
                dp[i] = dp[j]+1;
                ans = max(ans, dp[i]);
            }
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
