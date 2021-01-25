//
//  main.cpp
//  Partitions
//
//  Created by Giriraj Saigal on 25/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

int solve(int A, vector<int> B) {
    int sum = 0;
    
    for(int i : B) {
        sum+=i;
    }
    
    if(sum % 3 != 0) {
        return 0;
    }
    
    int part = sum/3;
    
    int sum2 = 0;
    int ans = 0;
    
    for(int i = 0; i < A-2; i++) {
        sum2 += B[i];
        if(sum2 == part) {
            int sum3 = 0;
            for(int j = i+1; j < A-1; j++) {
                sum3 += B[j];
                if(sum3 == part) {
                    ans++;
                }
            }
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<solve(5, {1, 2, 3, 0, 3})<<endl;
    return 0;
}
