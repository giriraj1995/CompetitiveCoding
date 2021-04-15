//
//  main.cpp
//  Simplify Directory Path
//
//  Created by Giriraj Saigal on 15/04/21.
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

vector<string> solve(string A, int i, int j) {
    string v = "";
    vector<string> ans;
    for(int k = i; k <= j; k++)
    {
        if(A[k] != '/') {
            v = v + A[k];
        }else{
            if(v.compare("") != 0)
                ans.push_back(v);
            v = "";
        }
    }
    
    if(v.compare("") != 0)
        ans.push_back(v);
        
    vector<string> ans2;
    
    for(int h = 0; h < ans.size(); h++) {
        if(ans[h].compare(".") == 0) {
            continue;
        }else if(ans[h].compare("..") == 0) {
            if(ans2.size() > 0) {
                ans2.pop_back();
            }
        }else{
            ans2.push_back(ans[h]);
        }
    }
    
    return ans2;
}

string simplifyPath(string A) {
    int i = 0;
    int j = A.size()-1;
    
    while(A[i] == ' ') {
        i++;
    }
    
    while(j >= i && A[j] == ' ') {
        j--;
    }
    
    if(j < i) {
        return "";
    }
    
    vector<string> x = solve(A, i, j);
    
    string ans3 = "/";
    
    for(string j : x) {
        ans3 = ans3 + j + "/";
    }
    
    return ans3.compare("/") == 0 ? ans3 : ans3.substr(0, ans3.length()-1);
}


int main(int argc, const char * argv[]) {
    cout<<simplifyPath("/a/./b/../../c/");
    return 0;
}
