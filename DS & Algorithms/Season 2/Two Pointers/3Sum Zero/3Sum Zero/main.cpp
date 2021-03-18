//
//  main.cpp
//  3Sum Zero
//
//  Created by Giriraj Saigal on 18/03/21.
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

vector<vector<int> > threeSum(vector<int> &A) {
    int n = A.size();
    if(n < 3) {
        return {};
    }
    
    sort(A.begin(), A.end());
    long long temp = 0;
    set<vector<int>> mp;
    for(int i = 0; i < n-2; i++) {
        int low = i+1;
        int high = n-1;
        while(low < high) {
            temp = (long long)A[i] + (long long)A[low] + (long long)A[high];
            if(temp == (long long)0) {
                mp.insert({A[i], A[low], A[high]});
                high--;
            }else if(temp < (long long)0){
                low++;
            }else if(temp > (long long)0){
                high--;
            }
        }
    }
    
    vector<vector<int> > ans;
    for(auto k : mp) {
        ans.push_back(k);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<int> A = {2147483647, -2147483648, -2147483648, 0, 1};
    threeSum(A);
    return 0;
}
