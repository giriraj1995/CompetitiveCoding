//
//  main.cpp
//  Divisible Sum Pairs
//
//  Created by Giriraj Saigal on 04/03/21.
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

int divisibleSumPairs(int n, int k, vector<int> ar) {
    map<int,int> m;
    
    int ans = 0;
    for(int i = 0; i < ar.size(); i++) {
        for(int t = 100; t >= 0; t--) {
            
            if(((t * k) - ar[i]) < 1) {
                break;
            }
            
            if(m.find((t * k) - ar[i]) == m.end()){
                continue;
            }else{
                ans++;
                break;
            }
        }
        
        m[ar[i]] = i;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    divisibleSumPairs(6,3,{1,3,2,6,1,2});
    return 0;
}
