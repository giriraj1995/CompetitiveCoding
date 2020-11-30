//
//  main.cpp
//  Nobal ele
//
//  Created by Giriraj Saigal on 29/11/20.
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

int solve(vector<int> A) {
    
    map<int, int> mp;
    
    int n = A.size();
    for(int i : A){
        mp[i]++;
    }
    
    int prev = 0;
    
    for(auto i : mp) {
        
        int next = n - i.second - prev;
        if(next == i.first)
            return 1;
        
        prev += i.second;
    }
    
    return -1;
}


int main(int argc, const char * argv[]) {
    cout<<solve({1, 2, 7, 0, 9, 3, 6, 0, 6})<<endl;
    return 0;
}
