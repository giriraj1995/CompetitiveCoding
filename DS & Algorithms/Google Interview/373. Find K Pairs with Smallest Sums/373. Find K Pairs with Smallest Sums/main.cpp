//
//  main.cpp
//  373. Find K Pairs with Smallest Sums
//
//  Created by Giriraj Saigal on 05/11/21.
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

vector<vector<int>> kSmallestPairs(vector<int> nums1, vector<int> nums2, int k) {
        
        int i = 0;
        int j = 0;
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        
        vector<vector<int>> ans;
        
        while(true){
            ans.push_back({nums1[i], nums2[j]});
            
            int x = i;
            int y = j;
            
            if(ans.size() == k)
                break;
            
           while(i+1<n && j+1<m && nums1[i] + nums2[j+1] < nums1[i+1] + nums2[j] && nums1[i] + nums2[j+1] < nums1[i+1] + nums2[y]) {
               j++;
               
               ans.push_back({nums1[i], nums2[j]});
               
               if(ans.size() == k)
                   break;
           }
            
            if(ans.size() == k)
                   break;
            
            i = i+1;
            j = y;
            x = i;
            ans.push_back({nums1[i], nums2[j]});
            
            if(ans.size() == k)
                break;
            
           while(i+1<n && j+1<m && nums1[i+1] + nums2[j] < nums1[i] + nums2[j+1] && nums1[i+1] + nums2[j] < nums1[x] + nums2[j+1]) {
               i++;
               
               ans.push_back({nums1[i], nums2[j]});
               
               if(ans.size() == k)
                   break;
           }
            
            if(ans.size() == k)
                   break;
            
            i = x;
            j = j+1;
            y = j;
    
            ans.push_back({nums1[i], nums2[j]});
            
            if(ans.size() == k)
                   break;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    kSmallestPairs({-3,0,1,7,11,42,44,49,50,59,99,1000},
                   {-43,-9,-8,-7,-4,2,4,6,34,54,65,86,98,99,100,121,143,145,199},
                   7);
    return 0;
}
