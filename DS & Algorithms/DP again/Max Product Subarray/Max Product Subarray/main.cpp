//
//  main.cpp
//  Max Product Subarray
//
//  Created by Giriraj Saigal on 16/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int kanedes_maxsubproduct(vector<int> arr) {
    int n = arr.size();
    
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 1;
    int flag = 0;
    
    for(int i = 0; i < n; i++) {
        
        if(arr[i] > 0) {
            
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(1, min_ending_here * arr[i]);
            flag = 1;
            
        }
        
        else if(arr[i] == 0) {
            
            max_ending_here = 1;
            min_ending_here = 1;
            
        }
        
        else {
            
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
            
        }
        
        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        
    }
    
    if(flag == 0 && max_so_far == 1)
        return 0;
    
    return max_so_far;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {2, 3, -2, 4};
    cout<<kanedes_maxsubproduct(x)<<endl;
    return 0;
}
