//
//  main.cpp
//  Disjoint Intervals Greedy
//
//  Created by Giriraj Saigal on 27/11/20.
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

int solve(vector<vector<int> > A) {
    
    sort(A.begin(), A.end());
    
    int x = -1;
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] > x){
            x = A[i][1];
            ans++;
        }else{
            if(A[i][1] < x){
                x = A[i][1];
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<solve({{1, 9}, {2, 3}, {5, 7}});
    cout<<endl;
    return 0;
}
