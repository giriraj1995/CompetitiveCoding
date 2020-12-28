//
//  main.cpp
//  Partition
//
//  Created by Giriraj Saigal on 28/12/20.
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

int solve(int A, vector<int> B) {
    
    long long sum = 0;
    for(int i = 0; i < A; i++) {
        sum += B[i];
    }
    
    if(sum%3 == 0 && A >= 3) {
        
    }else{
        return 0;
    }
    
    long long check = 0;
    int ans = 0;
    
    for(int i = 0; i < A-2; i++) {
        check += B[i];
        if(check == sum/3) {
            long long check2 = 0;
            for(int j = i+1; j < A-1; j++) {
                check2 += B[j];
                if(check2 == sum/3) {
                    ans++;
                }
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve(4,{0, 1, -1, 0});
    return 0;
}
