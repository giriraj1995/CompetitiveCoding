//
//  main.cpp
//  Find Permutation
//
//  Created by Giriraj Saigal on 28/01/21.
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

vector<int> findPerm(const string A, int B) {
    int up = 1;
    int down = B;
    
    vector<int> ans;
    
    for(char c : A) {
        if(c == 'I') {
            ans.push_back(up++);
        }else{
            ans.push_back(down--);
        }
    }
    
    if(A[A.size()-1] == 'I')
        ans.push_back(down);
    else
        ans.push_back(up);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
