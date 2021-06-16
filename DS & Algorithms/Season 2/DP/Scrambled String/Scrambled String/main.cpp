//
//  main.cpp
//  Scrambled String
//
//  Created by Giriraj Saigal on 16/06/21.
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

bool solve(string A, string B) {
    
    if(A.size() != B.size())
        return false;
    
    if(A.compare(B) == 0)
        return true;
    
    if(A.size() == 1) {
        return A[0] == B[0];
    }
    
    int n = A.size();
    
    for(int i = 0; i < n-1; i++) {
        string preA = A.substr(0,i+1);
        string nexA = A.substr(i+1);
        string preB = B.substr(0,i+1);
        string nexB = B.substr(i+1);
        
        if((solve(preA, preB) && solve(nexA, nexB)) ||
           (solve(preA, nexB) && solve(nexA, preB)) )
            return true;
    }
    
    return false;
}

int isScramble(const string A, const string B) {
    if(A.size() != B.size())
        return 0;
    
    return solve(A,B);
}


int main(int argc, const char * argv[]) {
    isScramble("abcde", "edfgh");
    return 0;
}
