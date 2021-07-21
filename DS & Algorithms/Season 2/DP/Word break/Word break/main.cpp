//
//  main.cpp
//  Word break
//
//  Created by Giriraj Saigal on 21/07/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include <stack>
#include <queue>
#include <set>
using namespace std;

unordered_set<string> s;
vector<int> dp;

int solve(string A, int n) {
    if(n == A.size())
        return true;
    
    if(dp[n] != -1)
        return dp[n];
        
    bool check = false;
    int c = A.size();
    int p = min(c, n+20);
    
    for(int k = n; k < p; k++) {
        string a = A.substr(n, k-n+1);
        
        if(s.find(a) != s.end())
            check = check || solve(A, k+1);
    }
    
    return dp[n] = check;
}
int wordBreak(string A, vector<string> &B) {
    dp = vector<int>(A.size()+1, -1);
    s.clear();
    for(string b : B)
        s.insert(b);
        
    return solve(A, 0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
