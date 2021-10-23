//
//  main.cpp
//  632. Smallest Range Covering Elements from K Lists
//
//  Created by Giriraj Saigal on 22/10/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

vector<int> search(vector<int> vec, int ele) {
        int i = 0;
        int j = vec.size()-1;
        vector<int> ans = {INT_MIN, INT_MAX};
        int n = vec.size();
        
        while(i <= j) {
            int m = i + (j-i)/2;
            if(vec[m] == ele) {
                return {ele,ele};
            }
            else
            if(ele < vec[m]) {
                j = m - 1;
            }else{
                i = m + 1;
            }
        }
        
        if(j == -1) {
            ans[1] = vec[0];
            return ans;
        }
        
        if(i == n) {
            ans[0] = vec[n-1];
            return ans;
        }
        
        ans[0] = vec[j];
        ans[1] = vec[i];
        
        return ans;
    }
    
vector<int> solve(vector<vector<int>> &nums) {
        int p = -1;
        int sz = INT_MAX;
    
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i].size() < sz){
                sz = (int)nums[i].size();
                p = i;
            }
        }
    
        vector<int> ans = {-100000, 100000};
        
        for(int i = 0; i < sz; i++) {
            int ele = nums[p][i];
            
            for(int j = 0; j < nums.size(); j++) {
                if(j == i)
                    continue;
                
                vector<int> vec1 = search(y, ele);
                
                if(vec1[0] == vec2[0] && vec1[1] == ele){
                    return {ele, ele};
                }
                
                vector<int> temp1 = {vec1[0],vec2[1]};
                vector<int> temp2 = {vec2[0],vec1[1]};
            
                if(temp1[0] == INT_MIN)
                    temp1[0] = ele;
                
                if(temp1[1] == INT_MAX)
                    temp1[1] = ele;
                
                if(temp2[0] == INT_MIN)
                    temp2[0] = ele;
                
                if(temp2[1] == INT_MAX)
                    temp2[1] = ele;
                
                if((temp1[1] - temp1[0] < ans[1] - ans[0]) || (temp1[1] - temp1[0] == ans[1] - ans[0] && temp1[0] < ans[0])) {
                    ans = temp1;
                }
                    
                if((temp2[1] - temp2[0] < ans[1] - ans[0]) || (temp2[1] - temp2[0] == ans[1] - ans[0] && temp2[0] < ans[0])) {
                    ans = temp2;
                }
            }
        }
        
        return ans;
    }

void removeDuplicates(vector<vector<int>> &nums) {
    for(int i = 0 ; i < nums.size(); i++) {
        unordered_set<int> s;
        for(int j = 0; j < nums[i].size(); i++) {
            s.insert(nums[i][j]);
        }
        vector<int> g;
        for(auto k : s){
            g.push_back(k);
        }
        nums[i] = g;
    }
}
vector<int> smallestRange(vector<vector<int>> nums) {
    removeDuplicates(nums);
    return solve(nums);
}

int main(int argc, const char * argv[]) {
    smallestRange({{10,10},{11,11}});
    return 0;
}
