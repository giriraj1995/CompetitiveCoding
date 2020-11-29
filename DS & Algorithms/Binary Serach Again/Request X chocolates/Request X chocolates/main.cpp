//
//  main.cpp
//  Request X chocolates
//
//  Created by Giriraj Saigal on 29/11/20.
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

bool isvalid(vector<vector<int> > &A, int B, int mid) {
    
    unordered_map<int, int> mp;
    unordered_map<int, int> rejected;

    int n = (int)A.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        
        int identity = A[i][0];
        int choco = A[i][1];
        
        if(rejected.find(identity) != rejected.end()){
            continue;
        }
    
        if(mp.find(identity) != mp.end()){
            int x = mp.find(identity)->second;
            if(x + choco > mid){
                rejected[identity] = 1;
            }else{
                sum += choco;
                mp[identity]=x+choco;
            }
        }else{
            if(choco > mid){
                rejected[identity] = 1;
            }else{
                sum += choco;
                mp[identity]=choco;
            }
        }
        
        if(sum > B){
            return false;
        }
    }
    
    return true;
    
}

int solve2(vector<vector<int> > &A, int B, int i, int j) {
    
    int res = -1;
    while(i <= j) {

        int mid = i + (j-i)/2;
        
        if(isvalid(A, B, mid)){
            res = mid;
            i = mid + 1;
        }else{
            j = mid - 1;
        }
    }
    
    return res;
}

int solve(vector<vector<int> > A, int B) {
    
    int low = INT_MAX;
    int sum = 0;
    for(int i = 0; i < A.size(); i++) {
        low = min(low, A[i][1]);
        sum += A[i][1];
    }
    
    return solve2(A, B, 0, sum);
}


int main(int argc, const char * argv[]) {
    cout<<solve({{13,3}}, 2);
    return 0;
}
