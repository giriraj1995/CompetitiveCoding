//
//  main.cpp
//  5999. Count Good Triplets in an Array
//
//  Created by Giriraj Saigal on 19/02/22.
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

//    int solve(vector<int>& x) {
//        long long i = 0;
//        long long j = x.size()-1;
//
//        while(i <= j) {
//            long long m = i + (j-i)/2;
//            if(m > 0 && m < x.size()) {
//                if(x[m] < x[m+1] && x[m] < x[m-1]){
//                    return m;
//                }else{
//                    if(x[m] > x[0])
//                        i = m+1;
//                    else
//                        j = m-1;
//                }
//            }else{
//                if(m == 0) {
//                    if(x[m+1] < x[m])
//                        return m+1;
//                    else
//                        j = m-1;
//                }else{
//                    if(x[m-1] < x[m])
//                        return m-1;
//                    else
//                        i = m+1;
//                }
//            }
//        }
//
//        if(x[0] < x[x.size()-1])
//            return 0;
//        else
//            return x.size()-1;
//    }
//
//    long long cal(long long n, long long len) {
//
//        if(len <= 2)
//            return 0;
//
//        if(len == 3)
//            return 1;
//
//        vector<long long> nc2(n+1, 0);
//        nc2[2] = 1;
//
//        //O(n)
//        for(int x = 3; x <= n; x++) {
//            nc2[x] = (x*nc2[x-1])/(x-2);
//        }
//
//        vector<long long> dp(len+1);
//        dp[3] = 1;
//
//        for(int x = 4; x <= len; x++) {
//            dp[x] = nc2[x-1]+dp[x-1];
//        }
//
//        return dp[len];
//    }
//
//    long long goodTriplets(vector<int> nums1, vector<int> nums2) {
//        int n = nums1.size();
//
//        int minInd1 = solve(nums1);
//        int minInd2 = solve(nums2);
//
//        int minI = min(minInd1, minInd2);
//        int maxI = max(minInd1, minInd2);
//
//        // 0 - (minI-1) = len = minI
//        //(maxI) - n-1 = len = n - maxI
//
//        return cal(n, minI) + cal(n, n - maxI);
//    }

long long solvec(vector<char> &c1, vector<char> &c2) {
       int n = c1.size();
       int m = c2.size();
       
       vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
       
       for(int i = 1; i <= n; i++) {
           for(int j = 1; j <= m; j++) {
               if(c1[i-1] == c2[j-1])
                   dp[i][j] = dp[i-1][j-1]+1;
               else{
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
               }
           }
       }
       
       return dp[n][m];
   }
   
   long long cal(long long n, long long len) {
       
       if(len <= 2)
           return 0;
       
       if(len == 3)
           return 1;
       
       vector<long long> nc2(n+1, 0);
       nc2[2] = 1;
       
       //O(n)
       for(int x = 3; x <= n; x++) {
           nc2[x] = (x*nc2[x-1])/(x-2);
       }
       
       vector<long long> dp(len+1);
       dp[3] = 1;
       
       for(int x = 4; x <= len; x++) {
           dp[x] = nc2[x-1]+dp[x-1];
       }
       
       return dp[len];
   }
   
   long long goodTriplets(vector<int> nums1, vector<int> nums2) {
       int n = nums1.size();
       
       vector<char> c1;
       vector<char> c2;
       
       for(int i : nums1){
           c1.push_back(i+'0');
       }
       
       for(int i : nums2){
           c2.push_back(i+'0');
       }
       
       long long len = solvec(c1, c2);
       return cal(n, len);
   }

int main(int argc, const char * argv[]) {
    goodTriplets({4,0,1,3,2},{4,1,0,2,3});
    return 0;
}
