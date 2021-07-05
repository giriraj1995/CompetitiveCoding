//
//  main.cpp
//  Coins in a Line
//
//  Created by Giriraj Saigal on 05/07/21.
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

long long ans;

int solve(int i, int j, vector<int>& A, bool now) {
    if(i > j){
        return 0;
    }
    
    int a = A[i] + solve(i+1,j,A,!now);
    int b = A[j] + solve(i,j-1,A,!now);
    return max(a,b);
    
}

int maxcoin(vector<int> A) {
    int i = 0;
    ans = 0;
    int j = A.size()-1;
    bool now = true;
    return ans;
}


int main(int argc, const char * argv[]) {
    maxcoin({1,2,3,4});
    return 0;
}
