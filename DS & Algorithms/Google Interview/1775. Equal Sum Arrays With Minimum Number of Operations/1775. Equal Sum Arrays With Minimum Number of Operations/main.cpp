//
//  main.cpp
//  1775. Equal Sum Arrays With Minimum Number of Operations
//
//  Created by Giriraj Saigal on 20/11/21.
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

int minOperations(vector<int> nums1, vector<int> nums2) {
        int sum1 = 0;
        int sum2 = 0;
        
        unordered_map<int, int> mp1, mp2;
        
        for(int i = 0; i < nums1.size(); i++) {
            sum1 += nums1[i];
            mp1[nums1[i]]++;
        }
        
        for(int j = 0; j < nums2.size(); j++) {
            sum2 += nums2[j];
            mp2[nums2[j]]++;
        }
        
        if(sum1 == sum2){
            return 0;
        }
        
        unordered_map<int,int> mp;
        
        //up
        int temp1 = 0;
        int diff = abs(sum1-sum2);
        
        if(sum1 > sum2){
            mp = mp2;
        }else{
            mp = mp1;
        }
        
        for(int i = 1; i <= 5; i++) {
            int x = mp[i];
            int y = 6-i;
            if(diff - y*x == 0) {
                temp1 += x;
                diff = 0;
                break;
            }else if(diff - y*x < 0) {
                temp1 += ceil(diff*1.0/y);
                diff = 0;
                break;
            }else{
                temp1 += x;
                diff -= x*y;
            }
        }
           
        if(diff != 0)
            temp1 = INT_MAX;
    
        //down
        int temp2 = 0;
        diff = abs(sum1-sum2);
        
        if(sum1 > sum2){
            mp = mp1;
        }else{
            mp = mp2;
        }
        
        for(int i = 6; i >= 2; i--) {
            int x = mp[i];
            int y = i-1;
            if(diff - y*x == 0) {
                temp2 += x;
                diff = 0;
                break;
            }else if(diff - y*x < 0) {
                temp2 += ceil(diff*1.0/y);
                diff = 0;
                break;
            }else{
                temp2 += x;
                diff -= x*y;
            }
        }
        
        if(diff != 0)
            temp2 = INT_MAX;
        
        return min(temp1, temp1) == INT_MAX ? -1 : min(temp1, temp1);
    }

int main(int argc, const char * argv[]) {
    cout << minOperations({6,6}, {1}) << endl;
    return 0;
}
