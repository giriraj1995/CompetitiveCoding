//
//  main.cpp
//  Deterministic Finite Automaton
//
//  Created by Giriraj Saigal on 17/01/21.
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
#include <unordered_set>
using namespace std;

int automata(vector<int> &A, vector<int> &B, vector<int> &C, int D, int E) {
    
    long mod = 1000000007;
    if(C.size() == 0)
        return 0;
        
    if(E == 0)
        return 0;
        
    vector<long> fact(E+1);
    fact[0] = fact[1] = 1;
    
    for(int i = 2; i <= E; i++)
        fact[i] = (fact[i-1] * i) % mod;
        
    unordered_set<int> acceptedStates;
    for(int i : C) {
        acceptedStates.insert(i);
    }
    
    queue<pair<int, int>> q;
    q.push({D,0});
    long ans = 0;
    
    while(q.size() > 0) {
        pair<int, int> p = q.front();
        q.pop();
        
        int state = p.first;
        int length = p.second;
        
        if(length == E) {
            if(acceptedStates.find(state) != acceptedStates.end())
                ans = (ans + 1) % mod;
            continue;
        }
        
        if(state == A[state] && state == B[state] && acceptedStates.find(state) != acceptedStates.end()) {
            int left = E - length;
            ans = (ans + fact[left]) % mod;
            for(int i = left; i >= 0; i--) {
                ans = (ans + (ans / ((fact[i] * fact[left - i]) % mod)) % mod) % mod;
            }
            continue;
        }
        else if(state == A[state] && acceptedStates.find(state) != acceptedStates.end()) {
            ans = (ans + 1) % mod;
            q.push({B[state], length+1});
        }else if(state == B[state] && acceptedStates.find(state) != acceptedStates.end()) {
            ans = (ans + 1) % mod;
            q.push({A[state], length+1});
        }else if(state == A[state] && acceptedStates.find(state) == acceptedStates.end()) {
            q.push({B[state], length+1});
        }else if(state == B[state] && acceptedStates.find(state) == acceptedStates.end()) {
            q.push({A[state], length+1});
        }else if(state != B[state] && state != A[state]){
            q.push({A[state], length+1});
            q.push({B[state], length+1});
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {

    return 0;
}
