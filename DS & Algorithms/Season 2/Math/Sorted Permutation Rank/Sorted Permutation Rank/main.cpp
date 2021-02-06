//
//  main.cpp
//  Sorted Permutation Rank
//
//  Created by Giriraj Saigal on 05/02/21.
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

int findRank(string A) {
    int mod = 1000003;
    int n = (int)A.size();
    vector<long> fact(n+1,1);
    
    for(int i = 2;i <= n; i++) {
        fact[i] = i*fact[i-1];
    }
    
    map<char, int> mp;
    
    int k = 0;
    for(int i = 0; i < n; i++)
        mp[A[i]]++;
    
    for(auto l : mp){
        mp[l.first] = k;
        k++;
    }
    
    int rank = 0;
    for(int i = 0; i < n-1; i++) {
            int f = fact[n - i - 1];
            string g = A.substr(i);
            sort(g.begin(), g.end());
            
            int s;
            
            for(int h = 0; h < g.size(); h++)
                if(g[h] == A[i])
                {
                    s = h;
                    break;
                }
            
            rank = ((rank + s * f) % mod) % mod;
    }
    
    return rank+1;
}


int main(int argc, const char * argv[]) {
    cout<<findRank("ZCSFLVHXRYJQKWABGT");
    return 0;
}
