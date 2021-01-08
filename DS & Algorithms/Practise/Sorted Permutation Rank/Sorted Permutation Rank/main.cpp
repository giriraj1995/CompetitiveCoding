//
//  main.cpp
//  Sorted Permutation Rank
//
//  Created by Giriraj Saigal on 04/01/21.
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
#define MOD 1000003

int fact[100];
int solve(string A, int rank, set<char> &s, int i) {
    
    auto k = NULL;
    
    set<char> :: iterator itr;
    itr = s.begin();
    
    while(s.size() > 0) {
        auto k  = s.begin();
        
        if(*k != A[i]) {
            
            int j = -1;
            for(auto f : s) {
                j++;
                if(A[i] == f) {
                    s.erase(f);
                    return solve(A, rank + j * fact[s.size()],s, i+1);
                }
                //i++;
            }
        }
        
        s.erase(s.begin());
        i++;
    }
    
    return rank;
}

int findRank(string A) {
    
    set<char> s;
    for(char c : A) {
        s.insert(c);
    }
    
    int rank = 1;
    
    memset(fact, 0, sizeof(fact));
    fact[0] = fact[1] = 1;
    
    for(int i = 2; i <= A.size(); i++)
        fact[i] = (fact[i-1] * i) % MOD;
    
    return solve(A, rank, s, 0);
    
}

int main(int argc, const char * argv[]) {
    cout<<findRank("cabd")<<endl;
    return 0;
}
