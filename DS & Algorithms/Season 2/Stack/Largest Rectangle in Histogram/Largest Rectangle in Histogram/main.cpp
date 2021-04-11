//
//  main.cpp
//  Largest Rectangle in Histogram
//
//  Created by Giriraj Saigal on 11/04/21.
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

vector<int> leftsmallest(vector<int> x) {
    vector<int> ans;
    stack<int> st;
    
    for(int i = 0; i < (int)x.size(); i++) {
        if(st.size() == 0) {
            ans.push_back(-1);
        }else if(x[st.top()] < x[i]) {
            ans.push_back(st.top());
        }else if(x[st.top()] >= x[i]) {
            while(st.size() > 0 && x[st.top()] >= x[i]) {
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

vector<int> rightsmallest(vector<int> x) {
    vector<int> ans;
    stack<int> st;
    
    for(int i = (int)x.size()-1; i >= 0; i--) {
        if(st.size() == 0) {
            ans.push_back((int)x.size());
        }else if(x[st.top()] < x[i]) {
            ans.push_back(st.top());
        }else if(x[st.top()] >= x[i]) {
            while(st.size() > 0 && x[st.top()] >= x[i]) {
                st.pop();
            }
            if(st.size() == 0) {
                ans.push_back((int)x.size());
            }else{
                ans.push_back(st.top());
            }
        }
        
        st.push(i);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int largestRectangleArea(vector<int> A) {
    vector<int> left = leftsmallest(A);
    vector<int> right = rightsmallest(A);
    
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++) {
        ans = max(ans, A[i] * (right[i] - left[i] - 1));
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    largestRectangleArea({2, 1, 5, 6, 2, 3});
    return 0;
}
