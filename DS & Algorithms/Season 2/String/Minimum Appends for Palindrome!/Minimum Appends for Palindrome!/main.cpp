//
//  main.cpp
//  Minimum Appends for Palindrome!
//
//  Created by Giriraj Saigal on 28/02/21.
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

int solve(string A) {
    int n = (int)A.size();
    
    if(n <= 1)
        return 0;
        
    int i = 0;
    int j = (int)A.size()-1;
    int ans = 0;
    
    while(i < j) {
        
        if(A[i] != A[j]) {
            ans = i + 1;
            j = (int)A.size()-1;
            i = i + 1;
            continue;
        }
        
        i++;
        j--;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve("oqycntornscygodzdctxnhoc");
    return 0;
}
