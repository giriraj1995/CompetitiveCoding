//
//  main.cpp
//  Largest Distance between nodes of a Tree
//
//  Created by Giriraj Saigal on 20/09/21.
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

int height(int u, unordered_map<int, vector<int>> &mp, int &ans) {
    //leaf
    if(mp[u].size() == 0)
        return 0;
        
    int first_max = 0;
    int second_max = 0;
    
    for(int v : mp[u]) {
        int x = height(v, mp, ans);
        x++;
        if(x > first_max) {
            second_max = first_max;
            first_max = x;
        }else if(x > second_max){
            second_max = x;
        }
    }
    
    ans = max(abs(first_max+second_max), ans);
    return max(first_max, second_max);
}

int solve(vector<int> A) {
    int root = -1;
    int n = A.size();
    if(n == 0)
        return 0;
    unordered_map<int, vector<int>> mp;
    
    for(int i = 0; i < n; i++) {
        if(A[i] == -1){
            root = i;
            break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i] == -1)
            continue;
        
        mp[A[i]].push_back(i);
    }
    
    int ans = 0;
    
    height(root, mp, ans);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({-1, 0, 0, 0, 3});
    return 0;
}
