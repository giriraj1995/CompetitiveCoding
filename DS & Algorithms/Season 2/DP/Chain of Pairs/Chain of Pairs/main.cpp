//
//  main.cpp
//  Chain of Pairs
//
//  Created by Giriraj Saigal on 04/08/21.
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

int solve(vector<vector<int> > A) {
    sort(A.begin(), A.end());
    vector<int> x(A.size(), 1);
    int ans = 1;
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < i; j++) {
            
            if(A[j][0] > A[i][1] && x[j] < x[i] + 1) {
                x[j] = x[i]+1;
                ans = max(x[j], ans);
            }
            
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve({
        {98, 894},
        {397, 942},
        {70, 519},
        {258, 456},
        {286, 449},
        {516, 626},
        {370, 873},
        {214, 224},
        {74, 629},
        {265, 886},
        {708, 815},
        {394, 770},
        {56, 252},
      }
          );
    return 0;
}
