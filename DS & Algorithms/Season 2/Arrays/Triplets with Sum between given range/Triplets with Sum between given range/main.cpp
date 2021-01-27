//
//  main.cpp
//  Triplets with Sum between given range
//
//  Created by Giriraj Saigal on 27/01/21.
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

int solve(vector<string> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<double> A;
    
    set<double> s;
    
    for(string j : a) {
        A.push_back(stod(j));
    }
    
    s.insert(A[0]);
    
    for(int i = 1; i < n-1; i++) {
        double k = A[i]+A[i+1];
        
        if(k > 2.0) {
            break;
        }
        
        double ele1 = 2 - k;
        double ele2 = 1 - k;

        auto add1 = s.lower_bound(ele1);
        auto add2 = s.lower_bound(ele2);
        
        if(add1 != s.begin() && add2 != s.end()) {
            return 1;
        }
        
        s.insert(A[i]);
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    cout<<solve({"0.297657", "0.420048", "0.053365", "0.437979", "0.375614", "0.264731", "0.060393", "0.197118", "0.203301", "0.128168"});
    return 0;
}
