//
//  main.cpp
//  First non repeating element
//
//  Created by Giriraj Saigal on 13/04/21.
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

string solve(string A) {
    int n = A.size();
    
    if(n == 0)
        return "";
    
    string ans = "";
    map<char, int> mp;
    queue<int> q;
    char c;
    for(int i = 0; i < n; i++) {
        mp[A[i]]++;
        
        if(mp[A[i]] == 1)
            q.push(A[i]);
        
        c = '#';
        while(q.size() > 0) {
            c = q.front();
            if(mp[c] == 1) {
                break;
            }else{
                c = '#';
                q.pop();
            }
        }
        
        ans.push_back(c);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve("abadbc");
    return 0;
}
