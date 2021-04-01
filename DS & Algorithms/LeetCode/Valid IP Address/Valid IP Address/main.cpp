//
//  main.cpp
//  Valid IP Address
//
//  Created by Giriraj Saigal on 02/03/21.
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

void solve(string a, string b, int i, int part, vector<string> &ans) {
    
    if(part == 4){
        if(i == a.size()){
            ans.push_back(b);
            return;
        }else{
            return;
        }
    }
    
    int x = 0;
    while(i < a.size()) {
        x = x*10 + (a[i] - '0');
        
        if(x == 0) {
            if(part != 3) {
                solve(a,b+"0.",i+1,part+1,ans);
            }else{
                solve(a,b+"0",i+1,part+1,ans);
            }
            break;
        }
        if(x <= 255){
            if(part != 3) {
                solve(a,b+to_string(x)+".",i+1,part+1,ans);
            }else{
                solve(a,b+to_string(x),i+1,part+1,ans);
            }
        }
            
        else
            break;
            
        i++;
    }
}

vector<string> restoreIpAddresses(string A) {
    vector<string> ans;
    string b = "";
    solve(A,b,0,0,ans);
    return ans;
}


int main(int argc, const char * argv[]) {
    restoreIpAddresses("0100100");
    return 0;
}
