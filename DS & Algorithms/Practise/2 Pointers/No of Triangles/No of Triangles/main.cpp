//
//  main.cpp
//  No of Triangles
//
//  Created by Giriraj Saigal on 08/01/21.
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

int nTriang(vector<int> A) {
    int n = A.size();
    int ans = 0;
    int m=1e9+7;
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n-2; i++) {
        
        for(int j = i + 1; j < n - 1; j++)
        {
            int x = j+1;
            int y = n-1;
            int ele = A[i] + A[j];
            int res = -1;
            
            while(x <= y) {
                int m = x + (y - x)/2;
                if(A[m] == ele) {
                    y = m - 1;
                }else if(ele < A[m]) {
                    y = m - 1;
                }else if(ele > A[m]) {
                    x = m + 1;
                    res = m;
                }
            }
            
            if(res != -1)
                ans = (ans + res - j) % m;
        }
    }
    
    return ans;
}

int nTriang1(vector<int> A) {
    int n=A.size(),ans=0,m=1e9+7;
    sort(A.begin(),A.end());
    
    for(int i=0;i<n-2;i++){
        
        if(A[i]==0) continue;
        
        for(int j=i+1;j<n-1;j++) {
            auto k = lower_bound(A.begin(),A.end(),A[i]+A[j]);
            auto p = A.begin()+j+1;
            ans=(ans + (k - p))%m;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<nTriang({4, 6, 13, 16, 20, 3, 1, 12});
    return 0;
}
