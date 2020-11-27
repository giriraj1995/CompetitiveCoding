//
//  main.cpp
//  Sam and substring
//
//  Created by Giriraj Saigal on 26/11/20.
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

int solve(string s, unordered_map<string, int> &mp) {
    
    int const MOD = 1000000007;
    int n = s.size();
    
    if(mp.find(s) != mp.end())
        return 0;
        
    if(n == 0)
        return 0;
        
    if(n == 1){
        return mp[s] = stoi(s);
    }
    
    long value = 0;
    long x = 0;
    long ans = 0;
    for(int k = 0; k < n; k++) {
        
        value = (((value * 10) % MOD)  + ((s[k] - '0') % MOD) % MOD);
        string right = s.substr(k+1, n - k - 1);
        
        x = solve(right, mp);
        
        ans += x + value;
    }
    
    return mp[s] = ans;
    
}
// Complete the substrings function below.
//int substrings(string n) {
//    unordered_map<string, int> mp;
//    return solve(n, mp);
//}

//int substrings(string s) {
//    // unordered_map<string, int> mp;
//    // return solve(n, mp);
//    int const mod = 1000000007;
//
//    long n = s.length();
//    long sod[n];
//
//    sod[0] = s[0]-'0';
//    long res = sod[0];
//
//    for(long i=1; i<n; i++)
//    {
//        int x = i+1;
//        int y = (s[i]-'0');
//        sod[i] = (x * y + 10 * sod[i-1])%mod;
//        res = (res+sod[i])%mod;
//    }
//
//    return res;
//}

//long substrings(string s) {
//    int const mod = 1000000007;
//
//    long n = s.size();
//    long i;
//    vector<long> a(n);
//    vector<long> b(n);
//    a[0] = 1,b[0]=1;
//
//    for(i = 1;i<n;i++)
//    {
//        a[i] = (a[i-1]*10) % mod;
//        b[i] = (b[i-1]+a[i]) % mod;
//    }
//
//    long ans=0;
//
//    for(i = 0;i<n;i++)
//    {
//        ans+=((s[i]-'0')*b[n-i-1]*(i+1))%mod;
//        ans%=mod;
//    }
//
//    return ans;
//
//}

int substrings(string s) {
    int n = s.size();
    int const mod = 1000000007;

    vector<int> a(n);
    vector<int> b(n);
    
    a[0] = 1;
    b[0] = 1;
    
    for(int i = 1; i < n; i++) {
        a[i] = 10 * a[i-1] % mod;
        b[i] = a[i] + b[i-1] % mod;
    }
    
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += ((s[i] - '0') * b[n-i-1] * (i + 1)) % mod;
        sum %= mod;
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    cout<<substrings("123")<<endl;
    return 0;
}
