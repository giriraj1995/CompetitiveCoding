//
//  main.cpp
//  Ceil

//
//  Created by Giriraj Saigal on 28/11/20.
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

int ceill(int ele, vector<int> x, unordered_map<int, int> mp) {
    
    sort(x.begin(), x.end());
    int i = 0;
    int j = x.size()-1;
    int res = -1;
    
    while(i <= j) {
        
        int mid = i + (j-i)/2;
        
        if(x[mid] == ele)
        {
            res = mid;
            break;
        }else{
            if(ele < x[mid]){
                res = mid;
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
    }
    
    if(res == -1)
        return -1;
        
    return mp.find(x[res])->second;
    
}

vector<int> solve(vector<int> A, vector<int> B) {
    
    unordered_map<int, int> mp;
    
    for(int i =0; i < A.size(); i++) {
        mp[A[i]] = i;
    }
    
    int n = B.size();
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        ans.push_back(ceill(B[i], A, mp));
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    solve({9,1},{7,10,3});
    return 0;
}
