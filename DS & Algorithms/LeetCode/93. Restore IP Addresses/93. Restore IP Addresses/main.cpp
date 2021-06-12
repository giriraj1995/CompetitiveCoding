//
//  main.cpp
//  93. Restore IP Addresses
//
//  Created by Giriraj Saigal on 09/06/21.
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

vector<string> ans;
void solve(int i, int part, string out, string s) {
    
    if(i == s.size() && part == 4){
        ans.push_back(out.substr(0,out.size()-1));
        return;
    }
    
    if(i >= s.size())
        return;
    
    if(part >= 4)
        return;
    
    int ele = 0;
    for(int k = i; k < s.size(); k++) {
        ele = ele*10 + s[k]-'0';
        
        if(ele > 255)
            break;
        
        if(ele == 0) {
            solve(k+1,part+1,out+s[k]+".", s);
            break;
        }else{
            solve(k+1,part+1,out+to_string(ele)+".",s);
        }
    }
    
}

vector<string> restoreIpAddresses(string s) {
    solve(0,0,"",s);
    return ans;
}

int main(int argc, const char * argv[]) {
    restoreIpAddresses("25525511135");
    return 0;
}
