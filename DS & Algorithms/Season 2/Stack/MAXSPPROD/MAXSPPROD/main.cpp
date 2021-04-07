//
//  main.cpp
//  MAXSPPROD
//
//  Created by Giriraj Saigal on 07/04/21.
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

vector<long long> solveleft(vector<int> &A) {
    stack<long long> st;
    long long n = A.size();
    vector<long long> ans;
    
    for(int i = 0; i < n; i++) {
        if(st.size() == 0) {
            ans.push_back(-1);
        }else if(A[st.top()] > A[i]) {
            ans.push_back(st.top());
        }else{
            while(st.size() > 0 && A[st.top()] <= A[i]) {
                st.pop();
            }
            
            if(st.size() == 0) {
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
        }
        st.push(i);
    }
    
    return ans;
}

vector<long long> solveright(vector<int> &A) {
    stack<long long> st;
    long long n = A.size();
    vector<long long> ans;
    
    for(int i = n-1; i >= 0; i--) {
        if(st.size() == 0) {
            ans.push_back(-1);
        }else if(A[st.top()] > A[i]) {
            ans.push_back(st.top());
        }else{
            while(st.size() > 0 && A[st.top()] <= A[i]) {
                st.pop();
            }
            
            if(st.size() == 0) {
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
        }
        st.push(i);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int maxSpecialProduct(vector<int> A) {
    vector<long long> left = solveleft(A);
    vector<long long> right = solveright(A);
    long long ans = 0;
    for(int i = 1; i < A.size()-1; i++) {
        if(left[i] == -1 || right[i] == -1)
            continue;
        ans = max(ans, (long long)((long long)left[i] * (long long)right[i]));
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    maxSpecialProduct({1, 4, 3, 4});
    return 0;
}
