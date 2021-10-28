//
//  main.cpp
//  321. Create Maximum Number
//
//  Created by Giriraj Saigal on 29/10/21.
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
//unordered_map<string, string> dp;
//
//    string getKey(int i, int j, int k){
//        return to_string(i) + "|" + to_string(j) + "|" + to_string(k);
//    }
//
//    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int k) {
//        if(k == 0){
//            dp[getKey(i,j,k)] = "";
//            return 1;
//        }
//
//        if(i == nums1.size() && j == nums2.size()){
//            return 0;
//        }
//
//        if(k > (nums1.size() - i) + (nums2.size() - j)){
//            return 0;
//        }
//
//        if(dp.count(getKey(i,j,k))) {
//            return true;
//        }
//
//        set<string> vec;
//
//        if(i == nums1.size()) {
//            if(nums2[j] == 9) {
//                solve(i, j+1, nums1, nums2, k-1);
//                dp[getKey(i, j, k)] = "9" + dp[getKey(i,j+1,k-1)];
//                return 1;
//            }
//            //wait take
//            int x = solve(i, j+1, nums1, nums2, k-1);
//            if(x)
//                vec.insert(to_string(nums2[j]) + dp[getKey(i,j+1,k-1)]);
//            //wait skip
//            int y = solve(i, j+1, nums1, nums2, k);
//            if(y)
//                vec.insert(dp[getKey(i,j+1,k)]);
//
//            if(vec.size() == 0)
//                return 0;
//
//            dp[getKey(i, j, k)] = *(--vec.end());
//            return 1;
//        }
//
//        if(j == nums2.size()) {
//            if(nums1[i] == 9) {
//                solve(i+1, j, nums1, nums2, k-1);
//                dp[getKey(i, j, k)] = "9" + dp[getKey(i+1,j,k-1)];
//                return 1;
//            }
//            //wait take
//            int x = solve(i+1, j, nums1, nums2, k-1);
//            if(x)
//                vec.insert(to_string(nums1[i]) + dp[getKey(i+1,j,k-1)]);
//            //wait skip
//            int y = solve(i+1, j, nums1, nums2, k);
//            if(y)
//                vec.insert(dp[getKey(i+1,j,k)]);
//
//            if(vec.size() == 0)
//                return 0;
//
//            dp[getKey(i, j, k)] = *(--vec.end());
//            return 1;
//        }
//
//        if(nums2[j] == 9 && nums1[i] == 9) {
//            solve(i+1, j+1, nums1, nums2, k-2);
//            dp[getKey(i, j, k)] = "99" + dp[getKey(i+1,j+1,k-2)];
//            return 1;
//        }else if(nums2[j] == 9){
//            solve(i, j+1, nums1, nums2, k-1);
//            dp[getKey(i, j, k)] = "9" + dp[getKey(i,j+1,k-1)];
//            return 1;
//        }else if(nums1[i] == 9){
//            solve(i+1, j, nums1, nums2, k-1);
//            dp[getKey(i, j, k)] = "9" + dp[getKey(i+1,j,k-1)];
//            return 1;
//        }
//        //take i - wait j
//        int one = solve(i+1, j, nums1, nums2, k-1);
//
//        if(one) {
//            vec.insert(to_string(nums1[i]) + dp[getKey(i+1,j,k-1)]);
//        }
//        //take i - skip j
//        int two = solve(i+1, j+1, nums1, nums2, k-1);
//
//        if(two) {
//            vec.insert(to_string(nums1[i]) + dp[getKey(i+1,j+1,k-1)]);
//        }
//
//        //wait i - take j
//        int three = solve(i, j+1, nums1, nums2, k-1);
//
//        if(three){
//            vec.insert(to_string(nums2[j]) + dp[getKey(i,j+1,k-1)]);
//        }
//
//        //skip i - take j
//        int four = solve(i+1, j+1, nums1, nums2, k-1);
//
//        if(four){
//            vec.insert(to_string(nums2[j]) + dp[getKey(i+1,j+1,k-1)]);
//        }
//
//        //skip skip
//        int five = solve(i+1, j+1, nums1, nums2, k);
//
//        if(five){
//            vec.insert(dp[getKey(i+1,j+1,k)]);
//        }
//
//        //skip wait
//        int six = solve(i+1, j, nums1, nums2, k);
//
//        if(six){
//            vec.insert(dp[getKey(i+1,j,k)]);
//        }
//
//        //wait skip
//        int seven = solve(i, j+1, nums1, nums2, k);
//
//        if(seven){
//            vec.insert(dp[getKey(i,j+1,k)]);
//        }
//
//        if(vec.size() == 0)
//            return 0;
//
//        dp[getKey(i,j,k)] = *(--vec.end());
//        return 1;
//    }
//
//vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//    solve(0,0,nums1,nums2,k);
//    string x = dp[getKey(0, 0, k)];
//    vector<int> ans;
//    cout << x << endl;
//    for(int i = 0; i < x.size(); i++) {
//        ans.push_back(x[i] - '0');
//    }
//    return ans;
//}

vector<int> findmaxnumber(vector<int> nums, int len) {
        int n = nums.size();
        vector<int> ans(len);
        
        if(len == 0)
            return ans;
        if(len == n)
            return nums;
        
        stack<int> s;
        s.push(nums[0]);
        
        // s.size() - 1 + n - i > len
        for(int i = 1; i < n; i++) {
            while(s.size() > 0 && nums[i] > s.top() && (s.size()-1+n-i) >= len){
                s.pop();
            }

            if(s.size() < len)
                s.push(nums[i]);
        }
        
        int k = len-1;
        while(s.size() > 0) {
            ans[k--] = s.top();
            s.pop();
        }
        
        return ans;
    }
    
    bool cmp(vector<int> x, int i, vector<int> y, int j) {
        while(i < x.size() && j < y.size() && x[i] == y[j]) {
            i++;
            j++;
        }
        if(j == y.size())
            return true;
        if(i != x.size() && x[i] > y[j])
            return true;
        return false;
    }
    
    vector<int> merge(vector<int> x, vector<int> y, int k) {
        vector<int> ans(k);
        int st1 = 0;
        int st2 = 0;
        int st = 0;
        
        while(st < k) {
            if(cmp(x,st1,y,st2)) {
                ans[st++] = x[st1++];
            }else{
                ans[st++] = y[st2++];
            }
        }
        
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result = vector<int>(k, 0);
        
        for(int i = 0; i <= k; i++) {
            if(i <= n && (k-i) <= m) {
                vector<int> x = findmaxnumber(nums1, i);
                vector<int> y = findmaxnumber(nums2, k-i);
                vector<int> m = merge(x,y,k);
                if(cmp(m,0,result,0)){
                    result = m;
                }
            }
        }
        
        return result;
    }

int main(int argc, const char * argv[]) {
    vector<int> x = {6,0,4};
    vector<int> y = {6,7};
    maxNumber(x,y,5);
    return 0;
}
