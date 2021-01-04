//
//  main.cpp
//  Sorted Permutation rank with duplicate
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
#define MOD 1000003

using namespace std;

long findRank(string A) {
    
        
        int n = A.size();
        
        vector<long long> fact(n+1, 1);
        
        for(int i = 2;i <= n; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        
        map<char, int> mp;
        
        for(char c : A){
            mp[c] = 1;
        }
        
        map<char, int> mp2;
        
        int rank = 1;
        
        for(auto i : mp) {
            mp2[i.first] = rank++;
        }
        
        mp.clear();
        
        long long ans = 1;
        
        for(int i = A.size()-1; i >= 0; i--) {
            long long count = 0;
            for(int j = i + 1; j < A.size(); j++) {
                if(A[j] < A[i])
                    count++;
            }
            
            double curr = 1;
            
            mp[A[i]]++;
            
            for(auto m : mp) {
                if(m.second > 1) {
                    curr = (curr / fact[m.second]);
                }
            }
            
            ans += (long long)((fact[A.size() - i - 1] * count) % MOD * curr) % MOD;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    cout<<findRank("asasdsdsadasdadsadasdsa")<<endl;
    return 0;
}
