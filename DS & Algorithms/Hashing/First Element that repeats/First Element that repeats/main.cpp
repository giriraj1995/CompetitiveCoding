//
//  main.cpp
//  First Element that repeats
//
//  Created by Giriraj Saigal on 01/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int solve(vector<int> &A) {
    unordered_map<int,int>mp;
    int n=A.size();
    for(int i=0;i<n;i++){
        mp[A[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[A[i]]>1)
            return A[i];
    }
    return -1;
}


int main(int argc, const char * argv[]) {

    return 0;
}
