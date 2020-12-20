//
//  main.cpp
//  First Negative number of size k
//
//  Created by Giriraj Saigal on 20/12/20.
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

vector<int> firstNegativeNumber(vector<int> arr, int k) {
    
    queue<pair<int,int>> q;
    vector<int> ans;
    int i = 0;
    while(i < k) {
        if(arr[i] < 0){
            q.push({arr[i],i});
        }
        i++;
    }
    
    if(q.size() > 0) {
        ans.push_back(q.front().first);
    }else{
        ans.push_back(0);
    }
    
    while(i < arr.size()) {
        
        while(q.front().second <= i - k){
            q.pop();
        }
        
        if(arr[i] < 0) {
            q.push({arr[i],i});
        }
        
        if(q.size() > 0) {
            ans.push_back(q.front().first);
        }else{
            ans.push_back(0);
        }
        
        i++;
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    vector<int> arr = {12,-1,-7,8,-18,30,16,28};
    
    arr = firstNegativeNumber(arr, 3);
    return 0;
}
