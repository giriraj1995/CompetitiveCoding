//
//  main.cpp
//  ways to fill 3Xa board with colors
//
//  Created by Giriraj Saigal on 03/07/21.
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

int solve(int A) {
    if(A <= 0)
        return -1;
        
    int mod = 1e9+7;
    vector<long long> dp2(A+1);
    vector<long long> dp3(A+1);
    
    dp2[1] = 12;
    dp3[1] = 24;
    
    for(int i = 2; i <= A; i++) {
        dp2[i] = (7*dp2[i-1] + 5*dp3[i-1]) % mod;
        dp3[i] = (10*dp2[i-1] + 11*dp3[i-1]) % mod;
    }
    
    return (dp2[A] + dp3[A]) % mod;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
