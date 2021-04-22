//
//  main.cpp
//  Kth Permutation Sequence
//
//  Created by Giriraj Saigal on 21/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

string getPermutation(int A, int B) {
    vector<int> x;
    for(int i = 1; i <= A; i++)
        x.push_back(i);
    
    do{
        B--;
    }while(next_permutation(x.begin(), x.end()) && B!=1);
    
    string ans = "";
    
    for(int i : x) {
        ans += to_string(i);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    getPermutation(3,1);
    return 0;
}
