//
//  main.cpp
//  Valid IP address
//
//  Created by Giriraj Saigal on 31/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

void solve(string A, int i, int part, vector<string> &ans, string curr) {
    int n = A.size();
    
    if(i == n)
        return;
    
    if(n - i > (4 - part) * 3) {
        return;
    }
    
    if(A[i] == '0' && part == 3) {
        if(i == A.size()-1) {
            ans.push_back(curr + "0");
        }
        
        return;
    }else if(A[i] == '0' && part < 3) {
        solve(A, i+1, part+1, ans, curr + "0.");
        return;
    }
    
    if(part == 3) {
        string g = A.substr(i);
        if(stoi(g) >= 0 && stoi(g) <= 255){
            curr += g;
            ans.push_back(curr);
        }
        return;
    }
    
    if(part >= 4)
        return;
    
    string k = "";
    
    for(int h = i; h < i+3 && h < n; h++) {
        k.push_back(A[h]);
        if(stoi(k) >= 0 && stoi(k) <= 255) {
            solve(A, h+1, part+1, ans, curr + k + ".");
        }
    }
}

vector<string> restoreIpAddresses(string A) {
    int n = A.size();
    
    if(n > 12) {
        return {};
    }
    
    vector<string> ans;
    string curr = "";
    
    solve(A,0,0,ans,curr);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    restoreIpAddresses("010010");
    return 0;
}
