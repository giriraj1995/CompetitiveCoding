//
//  main.cpp
//  Stepping numbers
//
//  Created by Giriraj Saigal on 16/12/20.
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

//bool isSafe(int i, int A, int B) {
//
//    if(i < A || i > B)
//        return false;
//
//    string s = to_string(i);
//    int n = s.size();
//
//    for(int i = 1; i < n; i++) {
//
//        int x = s[i]-'0';
//        int xp = s[i-1]-'0';
//
//        if(x == xp - 1 || x == xp + 1)
//            continue;
//        else
//            return false;
//    }
//
//    return true;
//}
//
//vector<string> convert(string c, int i) {
//
//    int n = c.size();
//    vector<string> ans;
//    if(n <= 1)
//        return {};
//
//    // handle zero case
//
//    if( i == 0 ){
//        if(c[i] == '0') {
//            c[1] = '1';
//            ans.push_back(c);
//            return ans;
//        }
//
//        if(c[i] == '9') {
//            c[1] = '8';
//            ans.push_back(c);
//            return ans;
//        }
//
//        int h = c[0];
//        c[1] = h+1;
//        ans.push_back(c);
//        c[1] = h-1;
//        ans.push_back(c);
//        return ans;
//    }
//
//    if(i == c.size()-1) {
//        if(c[i] == '0') {
//            int h = c[i];
//            c[i-1] = h-1;
//            ans.push_back(c);
//
//            c.push_back('1');
//            ans.push_back(c);
//            return ans;
//        }
//
//        if(c[i] == '9') {
//            int h = c[i];
//            c[i-1] = h-1;
//            ans.push_back(c);
//
//            c.push_back('8');
//            ans.push_back(c);
//            return ans;
//        }
//
//        int h = c[c.size()-1];
//        c[i-1] = h+1;
//        ans.push_back(c);
//        c[i-1] = h-1;
//        ans.push_back(c);
//
//        c.push_back((char)h+1);
//        ans.push_back(c);
//        c.pop_back();
//        c.push_back((char)h-1);
//        ans.push_back(c);
//
//        return ans;
//    }
//
//    vector<int> left = {1,1,-1,-1};
//    vector<int> right = {1,-1,1,-1};
//
//    int h = c[i];
//
//    if(c[i] == '0' || c[i] == '9') {
//        if(c[i] == '0') {
//            c[i-1] = '1';
//            c[i+1] = '1';
//            ans.push_back(c);
//            return ans;
//        }
//
//        if(c[i] == '9') {
//            c[i-1] = '8';
//            c[i+1] = '8';
//            ans.push_back(c);
//            return ans;
//        }
//    }
//    else{
//        for(int j = 0; j < 4; j++) {
//            c[i-1] = h + left[j];
//            c[i+1] = h + right[j];
//
//            ans.push_back(c);
//        }
//    }
//
//    return ans;
//
//}
//
//void solve(int A, int B, vector<int> &ans) {
//
//    queue<int> q;
//    q.push(A);
//    map<int, bool > mp;
//
//    while(q.size() > 0) {
//
//        int s = q.front();
//        q.pop();
//
//        if(mp.find(s) == mp.end() && isSafe(s, A, B)) {
//            ans.push_back(s);
//        }else
//            continue;
//
//        mp[s] = true;
//
//        string c = to_string(s);
//        reverse(c.begin(), c.end());
//
//        for(int i = 0; i < c.size(); i++) {
//            vector<string> f = convert(c, i);
//
//            for(string k : f) {
//                k = string(k.rbegin(), k.rend());
//                q.push(stoi(k));
//            }
//        }
//    }
//
//}
//
//vector<int> stepnum(int A, int B) {
//    vector<int> ans;
//    solve(A,B,ans);
//    return ans;
//}


bool helper(int A, vector<int> &ans)
{
    if(A/10==0)
        return true;
    int left = A%10;
    int right = (A/10)%10;
    int diff = abs(left-right);
    return diff==1 && helper(A/10, ans);
}

vector<int> stepnum(int A, int B) {
    vector<int> ans;
    for(int i=A;i<=B;i++)
        if(helper(i,ans))
            ans.push_back(i);
    return ans;
}

int main(int argc, const char * argv[]) {
    stepnum(10,100);
    return 0;
}
