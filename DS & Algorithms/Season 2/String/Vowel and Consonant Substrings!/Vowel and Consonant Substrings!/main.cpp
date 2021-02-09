//
//  main.cpp
//  Vowel and Consonant Substrings!
//
//  Created by Giriraj Saigal on 07/02/21.
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

bool isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

int solve(string A) {
    int n = A.size();
    int mod = 1000000007;
    vector<int> c(n, 0);
    vector<int> v(n, 0);

    int con = 0;
    int vol = 0;
    for(int i = n-1; i >= 0; i--) {
        c[i] = con;
        v[i] = vol;
        
        if(!isVowel(A[i])) {
            con++;
        }else{
            vol++;
        }
    }
    
    long ans = 0;
    for(int i = 0; i < n; i++) {
        if(isVowel(A[i])) {
            ans = (ans + c[i]) % mod;
        }else{
            ans = (ans + v[i]) % mod;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve("inttnikjmjbemrberk");
    return 0;
}
