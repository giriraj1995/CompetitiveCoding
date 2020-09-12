//
//  main.cpp
//  N queens
//
//  Created by Giriraj Saigal on 12/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

bool isSafe(int p, int q, vector<string> x){
    
    int n = (int)x.size();
    int m = (int)x[0].size();
    
    int i = p;
    int j = 0;
    
    while(j < m){
        
        if(x[i][j] == 'Q')
            return false;
        
        j++;
        
    }
    
    i = 0;
    j = q;
    
    while(i < n){
        if(x[i][j] == 'Q')
            return false;
        
        i++;
    }
    
    int t;
    
    i = p;
    j = q;
    t = 0;
    
    while(i-t >= 0 && j-t >= 0){
        
        if(x[i-t][j-t] == 'Q')
            return false;
        
        t++;
    }
    
    i = p;
    j = q;
    t = 0;
    
    while(i+t < n && j+t < m){
        
        if(x[i+t][j+t] == 'Q')
            return false;
        
        t++;
    }
    
    i = p;
    j = q;
    t = 0;
    
    while(i-t >= 0 && j+t < m){
        
        if(x[i-t][j+t] == 'Q')
            return false;
        
        t++;
    }
    
    i = p;
    j = q;
    t = 0;
    
    while(i+t < n && j-t >= 0){
        
        if(x[i+t][j-t] == 'Q')
            return false;
        
        t++;
    }
    
    return true;
    
}

void solve(int r, int n, vector<string> &v,vector<vector<string> > &ans){
    if(r == n)
    {
        ans.push_back(v);
        return;
    }
    for(int j = 0; j < n; j++){
        if(isSafe(r, j, v)){
            v[r][j] = 'Q';
            solve(r+1, n, v, ans);
            v[r][j] = '.';
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    n = 4;
    string x(n, '.');
    vector<string> v(n,x);
    vector<vector<string> > ans;
    solve(0, n, v, ans);
    return 0;
}
