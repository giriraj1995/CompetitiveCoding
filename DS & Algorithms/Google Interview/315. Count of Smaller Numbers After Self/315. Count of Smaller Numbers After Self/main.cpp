//
//  main.cpp
//  315. Count of Smaller Numbers After Self
//
//  Created by Giriraj Saigal on 06/10/21.
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


void merge(vector<int>&ans, vector<pair<int,int>> &vec, int low, int high) {
    int m = low + (high-low)/2;
    int k = 0;
    vector<pair<int,int>> temp(high-low+1);
    int i = low;
    int j = m+1;
    
    while(i <= m && j <= high) {
        if(vec[i].first > vec[j].first) {
            ans[vec[i].second] += high-j+1;
            temp[k++] = vec[i++];
        }else{
            temp[k++] = vec[j++];
        }
    }
    
    while(i <= m) {
        temp[k++] = vec[i++];
    }
    
    while(j <= high){
        temp[k++] = vec[j++];
    }
    
    for(int g = low; g <= high; g++) {
        vec[g] = temp[g-low];
    }
    
    return;
}
void mergeSort(vector<int>&ans, vector<pair<int,int>> &vec, int low, int high) {
    if(low >= high){
        return;
    }
    
    int m = low + (high-low)/2;
    mergeSort(ans,vec,low, m);
    mergeSort(ans,vec, m+1, high);
    merge(ans, vec, low, high);
}

vector<int> countSmaller(vector<int> nums) {
    int n = nums.size();
    if(n == 0)
        return {};
    
    if(n == 1)
        return {0};
    
    vector<pair<int,int>> vec;
    vector<int> ans(n);
    
    for(int i = 0; i < nums.size(); i++) {
        vec.push_back({nums[i],i});
    }
    
    mergeSort(ans, vec, 0, nums.size()-1);
    return ans;
}


int main(int argc, const char * argv[]) {
    countSmaller({5,2,6,1});
    return 0;
}
