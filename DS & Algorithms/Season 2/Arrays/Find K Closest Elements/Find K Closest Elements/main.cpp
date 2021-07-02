//
//  main.cpp
//  Find K Closest Elements
//
//  Created by Giriraj Saigal on 02/07/21.
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

vector<int> findClosestElements(vector<int> arr, int k, int x) {
        int n = arr.size();
        
        vector<int> e = arr;
        for(int i = 0; i < n; i++) {
            arr[i] = abs(arr[i] - x);
        }
        
        int start = 0;
        int end = -1;
        
        int i = 0;
        
        int sum = 0;
        int minA = INT_MAX;
        
        for(i = 0; i < k; i++){
            sum += arr[i];
        }
        
        if(sum < minA){
            minA = sum;
            start = 0;
            end = i-1;
        }
        
        while(i < n) {
            sum -= arr[i-k];
            sum += arr[i];
            
            if(sum < minA)
            {
                minA = sum;
                start = i-k+1;
                end = i;
            }
            
            i++;
        }
        
        vector<int> ans;
        
        for(int j = start; j<=end; j++){
            ans.push_back(e[j]);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    findClosestElements({1,2,3,4,5}, 4, 3);
    return 0;
}
