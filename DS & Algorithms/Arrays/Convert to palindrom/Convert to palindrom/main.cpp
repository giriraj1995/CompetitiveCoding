//
//  main.cpp
//  Convert to palindrom
//
//  Created by Giriraj Saigal on 02/11/20.
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

bool check(int i, int j, string A, int flag) {
    
    if(i >= j)
        return true;
        
    if(A[i] == A[j]) {
        return check(i + 1, j - 1, A, flag);
    }else if (A[i] != A[j] && flag == 0){
        return check(i + 1, j, A, 1) || check(i, j - 1, A, 1);
    }else{
        return false;
    }
}

int solve(string A) {
    int j = A.size()-1;
    int x =  check(0, j, A, 0);
    return x;
}


int main(int argc, const char * argv[]) {
    solve("qifjhwvhvohmnnibd");
    return 0;
}
