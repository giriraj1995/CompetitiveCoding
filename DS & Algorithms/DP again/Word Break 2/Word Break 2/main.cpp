//
//  main.cpp
//  Word Break 2
//
//  Created by Giriraj Saigal on 22/11/20.
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

//vector<string> solve(string A, int i, int j, unordered_map<string, int> mp, unordered_map<string, vector<string>> dp){
//
//    string u = A.substr(i, j - i + 1);
//
//    if(dp.find(u) != dp.end()){
//        return dp.find(u)->second;
//    }
//
//    int n = j - i + 1;
//    vector<string> ans;
//
//    if(i > j)
//        return ans;
//
//    for(int k = i; k <= j; k++) {
//
//        string left = A.substr(i, k - i + 1);
//        string right = A.substr(k+1, j - k);
//
//        if(mp.find(left) != mp.end()){
//
//            if(mp.find(right) != mp.end()){
//                ans.push_back(left + " " + right);
//            }
//
//            vector<string> f = solve(A, k+1, j, mp, dp);
//
//            for(string o : f) {
//                ans.push_back(left + " " + o);
//            }
//
//        }else{
//            continue;
//        }
//    }
//
//    dp[A.substr(i, j - i + 1)] = ans;
//    return ans;
//
//}
//
//
//
//vector<string> wordBreak(string A, vector<string> B) {
//
//    unordered_map<string, int> mp;
//
//    for(string x : B) {
//        mp[x]++;
//    }
//
//    unordered_map<string, vector<string>> dp;
//
//    vector<string > ans;
//    return solve(A, 0, A.size()-1, mp, dp);
//    }


void word(string A, vector<string> &B, string prev, vector<string> &out){

if(A==""){
    out.push_back(prev);
    return;
}

for(int i=0;i<A.size();i++){
    
    string sub = A.substr(0,i+1);
    if(find(B.begin(), B.end(), sub)!=B.end()){
        string next = A.substr(i+1);
        string prev_new;
        if(prev=="")
            prev_new = sub;
        else
            prev_new = prev + " " + sub;
        word(next,B,prev_new,out);
    }
}
}

vector<string> wordBreak(string a, vector<string> b) {
    
    // unordered_map<string, int> mp;
    
    // for(string x : B) {
    //     mp[x]++;
    // }
    
    // unordered_map<string, vector<string>> dp;
    
    // vector<string > ans;
    // return solve(A, 0, A.size()-1, mp, dp);
    
    vector<string> output;
word(a,b,"",output);
return output;
    
}



int main(int argc, const char * argv[]) {
    vector<string> y = wordBreak("catsanddog", {"cat", "cats", "and", "sand", "dog"});
    return 0;
}
