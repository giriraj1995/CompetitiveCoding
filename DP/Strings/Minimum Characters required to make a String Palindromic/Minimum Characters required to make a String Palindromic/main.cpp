//
//  main.cpp
//  Minimum Characters required to make a String Palindromic
//
//  Created by Giriraj Saigal on 25/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int solve1(string A){
    string B = A;
    reverse(B.begin(), B.end());
    int n = A.size();
    int t[n+1][n+1];
    
    for(int i = 0; i<=n ; i++){
        for(int j = 0; j<=n ; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=n ; j++){
            if(A[i-1] == B[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[n][n];
}

int solve(string A) {
    int n = A.size();
    
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 0;
    
    int res = solve1(A);
    
    return n - res;
}

int solve_eff(string A) {
int l=0, r=A.length()-1;
int count = 0;
while(l < r){
    if(A[l] == A[r]){
        l++;
        r--;
    }else{
        if(l == 0) {
            count++;
            r--;
        }
        else {
            count += l;
            l = 0;
        }
    }
}
return count;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
