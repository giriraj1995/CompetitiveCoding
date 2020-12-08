//
//  main.cpp
//  Vowel and Consonant Substrings! Vowel and Consonant Substrings!
//
//  Created by Giriraj Saigal on 08/12/20.
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

bool isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int solve(string A) {
    
    int n = A.size();
    vector<int> vL(n, 0);
    
    int count = 0;
    if(isVowel(A[0])){
        count++;
    }
    
    for(int i = 1; i < n; i++){
        vL[i] = count;
        
        if(isVowel(A[i]))
            count++;
    }
    
    vector<int> vR(n, 0);

    count = 0;
    if(isVowel(A[n-1])){
        count++;
    }
    
    for(int i = n - 2; i >= 0; i--) {
        vR[i] = count;
        
        if(isVowel(A[i]))
            count++;
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        
        if(isVowel(A[i])) {
//            ans += i - vL[i];
            ans += (n-i-1) - vR[i];
        }else{
//            ans += vL[i];
            ans += vR[i];
        }
        
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve("vnpbeutxfqxriiajoejjmtjcx");
    return 0;
}
