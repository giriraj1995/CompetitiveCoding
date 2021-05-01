//
//  main.cpp
//  Diffk II
//
//  Created by Giriraj Saigal on 01/05/21.
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

int diffPossible(const vector<int> &A, int T) {
    map<int, int> mp;
    for(int i = 0; i < A.size(); i++) {
        if(mp.find(A[i] - T) != mp.end())
            return 1;
        
        if(mp.find(T + A[i]) != mp.end())
            return 1;
        
        mp[A[i]] = i;
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
