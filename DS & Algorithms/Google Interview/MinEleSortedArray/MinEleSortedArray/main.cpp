//
//  main.cpp
//  MinEleSortedArray
//
//  Created by Giriraj Saigal on 12/09/21.
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

int minInd(vector<int> x, int i, int j) {
        int n = x.size();
        
        if(i > j)
            return n;
        
        int m = i+(j-i)/2;
        if(m == 0){
            if(x[m] <= x[m+1])
                return m;
            else
                return m+1;
        }else if(m == n-1) {
            if(x[m] < x[m-1]) {
                return m;
            }else{
                return m+1;
            }
        }else{
            if(x[m] <= x[m+1] && x[m] < x[m-1]){
                return m;
            }else{
                int left = minInd(x, i, m-1);
                if(x[m] >= x[0]) {
                    if(left != 0 && left != n) {
                        return left;
                    }
                    int right = minInd(x, m+1, j);
                    if(right != 0 && right != n) {
                        return right;
                    }
                    return n;
                }else{
                    return left;
                }
            }
        }
    }
    int findMin(vector<int> nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        int x = minInd(nums, 0, n-1);
        
        return nums[x%n];
    }

int main(int argc, const char * argv[]) {
    cout <<findMin({2,2,2,2,2,2,2,1,2,2,2,2,2});
    return 0;
}
