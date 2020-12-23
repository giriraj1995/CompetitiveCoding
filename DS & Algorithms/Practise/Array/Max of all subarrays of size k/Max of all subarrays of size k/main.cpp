//
//  main.cpp
//  Max of all subarrays of size k
//
//  Created by Giriraj Saigal on 23/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

vector<int> maxOfSubArray(vector<int> x, int k) {
    
    queue<pair<int,int>> q;
    vector<int> ans;
    int i = 0;
    while(i < k) {
        
        while(q.size() > 0 && q.front().first < x[i]){
            q.pop();
        }
        
        q.push({x[i], i});
        i++;
    }
    
    ans.push_back(q.front().first);
    
    while(i < x.size()) {
        
        while(q.size() > 0 && q.front().second <= i - k) {
            q.pop();
        }
        
        while(q.size() > 0 && q.front().first < x[i]){
            q.pop();
        }
        
        q.push({x[i],i});
        i++;
        ans.push_back(q.front().first);
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    vector<int> x = {1,3,-1,-3,5,3,6,7};
    maxOfSubArray(x, 3);
    return 0;
}
