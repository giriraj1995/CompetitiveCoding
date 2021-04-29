//
//  main.cpp
//  2-Sum
//
//  Created by Giriraj Saigal on 29/04/21.
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

vector<int> twoSum(const vector<int> &A, int B) {
    map<int, int> mp;
    for(int i = 0; i < A.size(); i++) {
        if(mp.find(B-A[i]) != mp.end()) {
            return {mp[B-A[i]]+1, i+1};
        }
        mp[A[i]] = i;
    }
    
    return {};
}


int main(int argc, const char * argv[]) {

    return 0;
}
