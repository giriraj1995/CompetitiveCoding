//
//  main.cpp
//  Matrix Search
//
//  Created by Giriraj Saigal on 11/02/21.
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

int searchMatrix(vector<vector<int> > A, int B) {
    vector<int> s;
    int n = A.size();
    
    if(n == 0)
        return 0;
        
    int m = A[0].size();
    
    if(m == 0)
        return 0;
        
    for(auto j : A) {
        s.push_back(j[0]);
    }
    
    int i = 0;
    int j = n-1;
    
    bool found = false;
    while(i <= j) {
        int m = i + (j-i)/2;
        if(s[m] == B) {
            found = true;
            break;
        }else if(s[m] < B) {
            i = m + 1;
        }else if(s[m] > B) {
            j = m - 1;
        }
    }
    
    if(j == -1)
        return 0;
    
    vector<int> arr = A[j];
    
    if(found) {
        return 1;
    }
    
    i = 0;
    j = m-1;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(arr[m] == B) {
            return 1;
        }else if(arr[m] < B) {
            i = m + 1;
        }else if(arr[m] > B) {
            j = m - 1;
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    searchMatrix({{5, 17, 100, 111},
        {119, 120,  127,   131}}, 3);
    return 0;
}
