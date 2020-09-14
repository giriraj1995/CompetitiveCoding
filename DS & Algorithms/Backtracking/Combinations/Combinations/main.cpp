//
//  main.cpp
//  Combinations
//
//  Created by Giriraj Saigal on 11/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(vector<int> i, vector<int> j, map<vector<int>, int> &u, int n){
    
    if(j.size() == n){
        u.insert(make_pair(j, 0));
    }
    
    if(i.size() == 0)
        return;
    
    int x = i[0];
    
    i.erase(i.begin());
    
    vector<int> o = j;
    o.push_back(x);
    
    solve(i,j,u,n);
    solve(i,o,u,n);
    
}

vector<vector<int> > combine(int A, int B) {
    
    vector<int > input;
    vector<vector<int> > ans;
    for(int i = 1; i <= A; i++)
        input.push_back(i);
        
    vector<int> output;
    
    map<vector<int>, int> u;
    
    solve(input, output, u, B);
    
    map<vector<int>, int>::iterator itr;
    
    for(itr = u.begin(); itr != u.end() ; itr++){
        ans.push_back(itr->first);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    vector<vector<int> > x =combine(2,1);
    return 0;
}
