//
//  main.cpp
//  Permutation Swap
//
//  Created by Giriraj Saigal on 04/12/20.
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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    
    if(A == B){
        return 1;
    }
    
    queue<pair<vector<int>, int>> q;
    vector<int> level(C.size()+1);
    
    q.push({A,0});
    
    while(q.size() > 0 ) {
        
        vector<int> k = q.front().first;
        int level = q.front().second;
        
        vector<int> kc = k;
        
        q.pop();
        
        if(k == B){
            return 1;
        }
        
        if(level < C.size()){
            swap(&k[C[level][0]-1], &k[C[level][1]-1]);
            q.push({kc, level+1});
            q.push({k, level+1});
        }
    }
    
    return 0;
}

int find2(int x, vector<int> &parent) {
    if(parent[x] < 0)
        return x;
        
    return parent[x] = find2(parent[x], parent);
}

int solve3(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    vector<int> parent(n+1, -1);
    
    for(int i = 0; i < C.size(); i++) {
        int x = A[C[i][0]-1];
        int y = A[C[i][1]-1];
        
        int a = find2(x, parent);
        int b = find2(y, parent);
        
        if(a != b) {
            parent[b] = a;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i]) {
            int x = find2(A[i], parent);
            int y = find2(B[i], parent);
            
            if(x != y)
                return 0;
        }
    }
    
    return 1;
}


int main(int argc, const char * argv[]) {
    vector<int> a= {1,4,3,2};
    vector<int> b= {1,2,4,3};
    vector<vector<int>> c = {{2,3}, {3,2}};
    solve(a,b,c);
    return 0;
}
