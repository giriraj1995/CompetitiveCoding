//
//  main.cpp
//  Sub matrix with sum lt k
//
//  Created by Giriraj Saigal on 30/09/21.
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


int maxSumSubmatrix(vector<vector<int>> matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
//      maxSumSubmatrix({
//        { 5,-4,-3, 4},
//        {-3,-4, 4, 5},
//        { 5, 1, 5,-4}}
        for(int c1 = 0; c1 < m; c1++) {
            for(int c2 = c1; c2 < m; c2++) {
                
                if(c1 == 0) {
                    int sum_so_far = matrix[0][c2];
                    int max_sum = matrix[0][c2];
                    for(int j = 1; j < n; j++) {
                        sum_so_far = max(sum_so_far+matrix[j][c2], matrix[j][c2]);
                        max_sum = max(max_sum, sum_so_far);
                    }
                }else{
                    int sum = 0;
                    int i = 0;
                    int j = 0;
                    
                    while(j < n) {
                        sum += (matrix[j][c2]-matrix[j][c1-1]);
                        while(i <= j && sum > k) {
                            sum -= (matrix[i][c2]-matrix[i][c1-1]);
                            i++;
                        }
                        if(i <= j)
                        ans = max(ans, sum);
                        j++;
                    }
                }
            }
        }
        
    return ans;
    }

int main(int argc, const char * argv[]) {
    cout << maxSumSubmatrix({
        { 5,-4,-3, 4},
        {-3,-4, 4, 5},
        { 5, 1, 5,-4}}
                            ,8) << endl;
    return 0;
}
