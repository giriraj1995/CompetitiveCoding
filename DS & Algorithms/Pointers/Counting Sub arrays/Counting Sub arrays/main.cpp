//
//  main.cpp
//  Counting Sub arrays
//
//  Created by Giriraj Saigal on 07/12/20.
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

int solve(vector<int> A, int B) {
    
    int i = 0, j = 0;
    
    int n = A.size();
    
    int sum = A[0];
    int ans = 0;
    
    while(i < n && j < n) {
        if(sum < B) {
            if(i == j)
                ans += 1;
            else
                ans += 2;
            j++;
            sum += A[j];
        }else{
            sum -= A[i];
            if(i == j) {
                i++;
                j++;
                sum += A[j];
            }else{
                i++;
            }
        }
    }
    
    return ans;
}

vector<int> freqQuery(vector<vector<int>> q) {
    
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i = 0; i < (int)q.size(); i++) {
        
        if(q[i][0] == 1) {
            mp[q[i][1]]++;
        }else if(q[i][0] == 2){
            if(mp.find(q[i][1]) != mp.end()){
                mp[q[i][1]]--;
            }
        }else{
            if(mp[q[i][1]] == q[i][1]){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    freqQuery({{3,4},{2,1003},{1,16},{3,1}});
    return 0;
}
