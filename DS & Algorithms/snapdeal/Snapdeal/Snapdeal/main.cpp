//
//  main.cpp
//  Snapdeal
//
//  Created by Giriraj Saigal on 25/03/21.
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

int solve_min_no_BS(vector<int> A, int n) {
    if(n == 0)
        return -1;
    
    if(n == 1)
        return 0;
    
    int res = -1;
    int i = 0;
    int j = n-1;
    int st = 0;
    int en = n-1;
    while(i <= j) {
        int m = i + (j-i)/2;
        if(m != st && m != en) {
            if(A[m] < A[m+1] && A[m] < A[m-1]) {
                return m;
            }else{
                if(A[m] > A[st]) {
                    i = m+1;
                }else if(A[m] < A[st]){
                    j = m-1;
                }
            }
        }else{
            if(m == st) {
                if(A[m] < A[m+1])
                    return st;
                else
                    break;
            }else{
                if(A[m] < A[m-1]){
                    return en;
                }
                else
                    break;
            }
        }
    }
        
    return res+1;
}

void solve(int i, int n, int Z, int O, vector<int> out,set<vector<int>> s) {
    
    if(i == n) {
        s.insert(out);
        return;
    }
    
    if(O == Z) {
        out.push_back(1);
        solve(i+1, n, Z, O+1, out, s);
        out.pop_back();
    }
    
    if(O > Z) {
        out.push_back(1);
        solve(i+1, n, Z+1, O, out, s);
        out.pop_back();
        
        out.push_back(0);
        solve(i+1, n, Z, O+1, out, s);
        out.pop_back();
    }
}

//void solve(vector<string> arr ) {
//
//    string x = ".ad";
//    int n = x.size();
//
//    for(int j = 0; j < arr.size(); j++) {
//        if(arr[j].size() != x.size())
//            continue;
//        int i;
//
//        for(i = 0; i < n; i++) {
//            if(x[i] == '.' || x[i] == arr[j][i])
//                continue;
//            else
//                break;
//        }
//
//        if(i == n)
//            cout<<arr[j]<<endl;
//    }
//}

int main(int argc, const char * argv[]) {
//    vector<int> A = {6, 17, 41, 3, 5, 2};
//    // leader no greater than right ajacent
//
//    int n = 4;
//    //0110
//    set<vector<int>> ans;
//    //1110
//    int noOfZero = 0;
//    int noOfones = 0;
//    vector<int> out;
//    solve(0, 4, 0, 0, out, ans);
//
//    for(vector<int> i : ans){
//        for(auto k : i)
//            cout<<k;
//        cout<<endl;
//    }
//
////    vector<string> arr = {"bad", "mad", "dad", "dam", "ban", "bat", "add", "sum", "num"};
////    solve(arr);
////
////    O(m2+n);
    
    solve_min_no_BS({3,1}, 2);
    
    return 0;
}
