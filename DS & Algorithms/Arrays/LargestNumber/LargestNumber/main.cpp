//
//  main.cpp
//  LargestNumber
//
//  Created by Giriraj Saigal on 30/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
using namespace std;

bool compare(string a, string b) {
    return (a+b) > (b+a);
}

string largestNumber(const vector<int> A) {
    vector<string> B;
    
    for(int i : A){
        B.push_back(to_string(i));
    }
    
    sort(B.begin(), B.end(), compare);
    
    string ans = "";
    
    for(string h : B)
        ans += h;
        
    int m = ans.size();
    int i = 0;
    
    while(i < m) {
        if(ans[i] == '0'){
            i++;
        }else{
            break;
        }
    }
        
    return i == m ? "0" : ans;
}


int solve(vector<int> &A) {

    int n = A.size();
    
    vector<int> maxSuffix(n+1);
    maxSuffix[n] = 0;
    for(int i = n-1; i >= 0; i++) {
        maxSuffix[i] = max(maxSuffix[i+1], A[i]);
    }
    
    set<int> s;
    s.insert(INT_MIN);
    s.insert(A[0]);
    int ans = INT_MIN;
    for(int k = 1; k < n-1; k++) {
        
        if(A[k] < maxSuffix[k+1]){
            ans = max(ans,maxSuffix[k+1] + A[k] + *(--s.lower_bound(A[k])));
        }
        s.insert(A[k]);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<largestNumber({9, 99, 999, 9999, 9998});
    cout<<endl;
    return 0;
}
