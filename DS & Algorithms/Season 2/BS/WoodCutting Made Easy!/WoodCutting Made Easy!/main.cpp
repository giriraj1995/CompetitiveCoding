//
//  main.cpp
//  WoodCutting Made Easy!
//
//  Created by Giriraj Saigal on 10/02/21.
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

int total(int x, vector<int> &A) {
    long sum = 0;
    
    for(int h : A) {
        if(h > x) {
            sum += h-x;
        }
    }
    
    return sum;
}

int solve(vector<int> A, int B) {
    int h = INT_MIN;
    int l = INT_MAX;
    
    for(int i : A) {
        h = max(h, i);
        l = min(l, i);
    }
    
    while(l <= h) {
        int m = l + (h-l)/2;
        int x = total(m, A);
        if(x == B) {
            return m;
        }else if(x < B) {
            h = m-1;
        }else if(x > B) {
            l = m+1;
        }
    }
    
    return h;
}


int main(int argc, const char * argv[]) {
    cout<<solve({114, 55, 95, 131, 77, 111, 141},95)<<endl;
    return 0;
}
