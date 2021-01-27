//
//  main.cpp
//  Sort array with squares!
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
vector<int> solve(vector<int> &A) {
    
    vector<int> neg;
    vector<int> pos;
    
    for(int i : A) {
        if(i < 0) {
            neg.push_back(-1 * i);
        }else{
            pos.push_back(i);
        }
    }
    
    reverse(neg.begin(), neg.end());
    
    int k = 0;
    int i = 0, j = 0;
    
    int n = neg.size();
    int m = pos.size();
    
    while(i < n && j < m) {
        if(neg[i] < pos[j]) {
            A[k] = neg[i];
            k++;
            i++;
        }else{
            A[k] = pos[j];
            k++;
            j++;
        }
    }
    
    while(i < n) {
        A[k] = neg[i];
        k++;
        i++;
    }
    
    while(j < m) {
        A[k] = pos[j];
        k++;
        j++;
    }
    
    for(int i = 0; i < A.size(); i++) {
        A[i] = A[i] * A[i];
    }
    
    return A;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
