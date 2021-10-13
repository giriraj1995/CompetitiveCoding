//
//  main.cpp
//  1186. Maximum Subarray Sum with One Deletion
//
//  Created by Giriraj Saigal on 14/10/21.
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

int maxSum2(vector<int> arr) {
        int sum_so_far = arr[0];
        
        vector<int> left(arr.size());
        left[0] = sum_so_far;
        
        for(int i = 1; i < arr.size(); i++) {
            sum_so_far = max(sum_so_far+arr[i], arr[i]);
            left[i] = sum_so_far;
        }
        
        sum_so_far = arr[arr.size()-1];
        vector<int> right(arr.size());
        right[arr.size()-1] = sum_so_far;
        
        for(int i = arr.size()-2; i >= 0; i--) {
            sum_so_far = max(sum_so_far+arr[i], arr[i]);
            right[i] = sum_so_far;
        }
        
        int ans = max(right[1], left[arr.size()-1]);
        
        for(int i = 1; i < arr.size()-1; i++) {
            ans = max(ans, left[i-1]+right[i+1]);
            ans = max(ans, left[i-1]);
            ans = max(ans, right[i+1]);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    //[2,1,-2,-5,-2]
    cout << maxSum2({2,1,-2,-5,-2});
    return 0;
}
