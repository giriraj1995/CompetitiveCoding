//
//  main.cpp
//  Kth smallest ele in sorted matrix
//
//  Created by Giriraj Saigal on 07/07/21.
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

int kthSmallest(vector<vector<int>> matrix, int k) {
        int n = (int)matrix.size();
        
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int ans = INT_MAX;
        while(low <= high) {
            int ele = 0;
            int mid = low + (high-low)/2;
            int x = INT_MIN;
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    
                    if(matrix[i][j] <= mid) {
                        ele++;
                        x = max(x, matrix[i][j]);
                    }
                    
                }
            }
            
            if(ele >= k){
                ans = min(ans, x);
            }
            
            if(ele < k) {
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    kthSmallest({{-5}},1);
    return 0;
}
