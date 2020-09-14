//
//  main.cpp
//  MAH Stack
//
//  Created by Giriraj Saigal on 08/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<int> smallestLeft(vector<int> A){
    int n = (int)A.size();
    vector<int> ans;
    stack<int> s;
    
    for(int i = 0; i < n; i++){
        if(s.size() == 0)
            ans.push_back(-1);
        else if(s.size() > 0 && A[s.top()] < A[i])
            ans.push_back(s.top());
        else if(s.size() > 0 && A[s.top()] >= A[i]){
            while(s.size() > 0 && A[s.top()] >= A[i]){
                s.pop();
            }
            if(s.size() == 0)
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(i);
    }
    return ans;
}

vector<int> smallestRight(vector<int> A){
    int n = (int)A.size();
    vector<int> ans;
    stack<int> s;
    
    for(int i = n-1; i >= 0; i--){
        if(s.size() == 0)
            ans.push_back(n);
        else if(s.size() > 0 && A[s.top()] < A[i])
            ans.push_back(s.top());
        else if(s.size() > 0 && A[s.top()] >= A[i]){
            while(s.size() > 0 && A[s.top()] >= A[i]){
                s.pop();
            }
            if(s.size() == 0)
                ans.push_back(n);
            else
                ans.push_back(s.top());
        }
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int largestRectangleArea(vector<int> &A) {
    
    vector<int> left = smallestLeft(A);
    vector<int> right = smallestRight(A);
    
    int ans = INT_MIN;
    
    for(int i = 0; i < A.size(); i++){
        ans = max(ans, (right[i] - left[i] - 1)*A[i]);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<int> x = {6,2,5,4,5,1,6};
    
    cout<<largestRectangleArea(x)<<endl;
    return 0;
}
