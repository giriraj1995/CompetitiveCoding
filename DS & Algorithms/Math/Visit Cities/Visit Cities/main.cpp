//
//  main.cpp
//  Visit Cities
//
//  Created by Giriraj Saigal on 10/10/20.
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

void solveAgain(int n, int nv, vector<int> visted, int &ans){
    
    if(nv == 0){
        ans++;
        return;
    }
    
    for(int i = 0; i < visted.size(); i++){
        
        int flag = 0;
        
        if(visted[i] == 0){
            if(i+1 < visted.size() && visted[i+1] == 1){
                    flag = 1;
            }
            if(i-1 >= 0 && visted[i-1] == 1){
                    flag = 1;
            }
        }else{
            continue;
        }
        
        if(flag == 1){
            visted[i] = 1;
            solveAgain(n, nv-1, visted, ans);
            visted[i] = 0;
        }
    }
    
}

void update(int A ,map<int, bool> &v, map<int, bool> &nve){
    for(auto h : v){
        if(h.second){
            if(h.first-1 >= 0 && v.find(h.first-1) == v.end())
                nve[h.first-1] = true;
            if(h.first+1 < A && v.find(h.first+1) == v.end())
                nve[h.first+1] = true;
        }
    }
}

void solveMap(int A, map<int, bool> v, map<int, bool> nve, int &ans){
    
    if(nve.size() == 0){
        ans++;
        return;
    }
    
    map<int, bool> nve2 = nve;
    
    for(auto i : nve2){
        int x = i.first;
        v[i.first] = true;
        nve.erase(x);
        update(A, v, nve);
        solveMap(A, v, nve, ans);
        nve[x] = true;
        v.erase(x);
        update(A, v, nve);
    }
    
}

int solve(int A, vector<int> B) {
    
    map<int, bool> v;
    map<int, bool> nve;
    
    for(int i = 0; i < B.size(); i++){
        v[B[i]-1] = true;
    }
    
    update(A, v, nve);
    int ans = 0;
    solveMap(A, v, nve, ans);
    return ans;
}


int main(int argc, const char * argv[]) {
    solve(5, {2,4});
    return 0;
}
