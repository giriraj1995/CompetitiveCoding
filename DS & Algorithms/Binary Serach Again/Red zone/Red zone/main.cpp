//
//  main.cpp
//  Red zone
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

int check(vector<vector<int> > &A, int B, int x_mid, int y_mid, int &x, int &y){
    
    vector<pair<double, int>> v;
    double l = 0;
    for(int i = 0; i < A.size(); i++) {
        
        double dis = 0;
        dis = sqrt(pow(x_mid - A[i][0], 2) + pow(y_mid - A[i][1], 2));
        
        v.push_back({dis, i});
    }
    
    int k = 0;
    sort(v.begin(), v.end());
    while(B--) {
        
        x = A[v[k].second][0];
        y = A[v[k].second][1];
        l = v[k].first;
        
        k++;
    }
    
    return ceil(l);
}

int solve2(vector<vector<int> > &A, int B, int x_min, int x_max, int y_min, int y_max){
    
    int days = 0;
    while(x_min <= x_max && y_min <= y_max) {
        
        int x_mid = x_min + (x_max - x_min)/2;
        int y_mid = y_min + (y_max - y_min)/2;
        
        int x, y;
        
        days = check(A, B, x_mid, y_mid, x, y);
        
        if(x > x_mid) {
            x_min = x_mid + 1;
        }else{
            x_max = x_mid - 1;
        }
        
        if(y > y_mid) {
            y_min = y_mid + 1;
        }else{
            y_max = y_mid - 1;
        }
        
    }
    
    int x,y;
    return check(A,B,x_min, y_min, x,y);
    
}

int solve(vector<vector<int> > A, int B) {
    
    int n = A.size();
    
    if(n == 0)
        return 0;
        
    int x_min = INT_MAX;
    int x_max = INT_MIN;
    
    int y_min = INT_MAX;
    int y_max = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        
        x_min = min(x_min, A[i][0]);
        x_max = max(x_max, A[i][0]);
        
        y_min = min(y_min, A[i][1]);
        y_max = max(y_max, A[i][1]);
        
    }
    
    return solve2(A, B, x_min, x_max, y_min, y_max);
    
}


int main(int argc, const char * argv[]) {
    cout<<solve({{2,3}, {9,4}, {10,3}}, 2);
    return 0;
}
