//
//  main.cpp
//  interset cords
//
//  Created by Giriraj Saigal on 27/06/21.
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

//int mod = 1e9 + 7;
//
//long long solve(int a, vector<long long> &dp) {
//    if(a == 0 || a == 1)
//        return 1;
//
//    if(dp[a] != -1)
//        return dp[a];
//
//    long long ans = 0;
//
//    for(int i = 0; i < a; i++) {
//        long long left = solve(i, dp);
//        long long right = solve(a-1-i,dp);
//
//        ans = (ans + (left * right) % mod) % mod;
//    }
//
//    return ans;
//}
//
//int chordCnt(int A) {
//    vector<long long> dp(A+1, -1);
//    return solve(A, dp);
//}
//
//
//    string removeDuplicates(string s) {
//        int i = 0;
//        int n = s.size();
//        while(i < (n-1)) {
//            if(i == -1)
//                i++;
//
//            if(i >= s.size()-1)
//                break;
//
//            if(s[i] == s[i+1])
//            {
//                s.erase(i,2);
//                i--;
//            }else{
//                i++;
//            }
//
//            n = s.size();
//        }
//
//        return s;
//    }


set<vector<int>> s;
void solve(int i, int l, vector<int> inp, vector<int> B) {
    if(i == B.size()){
        if(s.size() == 0)
            s.insert(inp);
        else{
            if((*s.begin()).size() < inp.size()) {
                s.clear();
                s.insert(inp);
            }else if((*s.begin()).size() == inp.size()){
                s.insert(inp);
            }
        }
        return;
    }

    if(B[i] <= l) {
        inp.push_back(i);
        solve(i,l-B[i],inp,B);
        inp.pop_back();
        
        solve(i+1,l,inp,B);
    }else{
        solve(i+1,l,inp,B);
    }
}
vector<int> solve(int A, vector<int> &B) {
    s.clear();
    solve(0, A, {}, B);
    return (*s.begin());
}

int main(int argc, const char * argv[]) {
    return 0;
}
