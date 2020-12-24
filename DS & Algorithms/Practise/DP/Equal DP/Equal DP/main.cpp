//
//  main.cpp
//  Equal DP
//
//  Created by Giriraj Saigal on 24/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int equal(vector<int> arr) {
    int lowest = INT_MAX;
    map<int, int, greater<int>> highest;
    for(int i : arr) {
        lowest = min(lowest, i);
        highest[i]++;
    }
    
    int ops = 0;
    int high = highest.begin()->first;
    while(lowest < high) {
        for(int i =0 ;i < arr.size(); i++) {
            if(arr[i] - lowest >= 5){
                arr[i] -= 5;
                ops++;
                highest[arr[i]+5]--;
                
                if(highest[arr[i]+5] == 0){
                    highest.erase(arr[i]+5);
                }
                
                highest[arr[i]]++;
            }else if(arr[i] - lowest >= 2) {
                arr[i] -= 2;
                ops++;
                
                highest[arr[i]+2]--;
                if(highest[arr[i]+2] == 0){
                    highest.erase(arr[i]+2);
                }
                
                highest[arr[i]]++;
            }else if(arr[i] - lowest >= 1) {
                arr[i] -= 1;
                ops++;
                
                highest[arr[i]+1]--;
                if(highest[arr[i]+1] == 0){
                    highest.erase(arr[i]+1);
                }
                
                highest[arr[i]]++;
            }
            
            // else{
            //     lowest[arr[i]]--;
            //     if(lowest[arr[i]] == 0) {
            //         lowest.erase(arr[i]);
            //     }
            // }
            
        high = highest.begin()->first;
        }
    }
    
    return ops;
}

int main(int argc, const char * argv[]) {
    equal({2 ,2 ,3 ,7});
    return 0;
}
