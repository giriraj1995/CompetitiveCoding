//
//  main.cpp
//  Sorted Permutation rank with duplicate
//
//  Created by Giriraj Saigal on 04/01/21.
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

int findRank(string a) {
    
    int fact[100];
    memset(fact, 0, sizeof(fact));
    
    fact[0] = fact[1] = 1;
    
    for(int i = 2; i <= a.size(); i++) {
        fact[i] = (fact[i-1] * i) % 1000003;
    }
    
    string b = a;
    
    map<char, int> mp;
    
    for(char f : b) {
        mp[f]++;
    }
    
    int rank = 1;
    sort(b.begin(), b.end());
    
    int i = 0;
    int j = 0;
    while(i < a.size()) {
        if(a[i] != b[0]) {
            int k = 0;
            int count = 0;
            char c = a[i];
            set<char> s;
            
            for(char t : b) {
                if(t == c)
                    break;
                
                if(s.find(t) == s.end()) {
                    k++;
                    s.insert(t);
                }
                count++;
            }
            
            
            for(auto d : s) {
                long fac = 0;
                map<char, int> mp2 = mp;
                mp2[d]--;
                
                if(mp2[d] == 0)
                    mp2.erase(d);
                
                fac += fact[b.size()-1];
                
                for(auto r : mp2) {
                    if(r.second > 1) {
                        fac = fac / fact[r.second];
                    }
                }
                
                rank = rank + fac;
            }
            
            mp[c]--;
            if(mp[c] == 0)
                mp.erase(c);
            
            b.erase(b.begin() + count);
            
            
//
//            long fac = fact[b.size()];
//
//            for(auto itr : mp) {
//                if(itr.second > 1) {
//                    fac = fac / fact[itr.second];
//                }
//            }
//
            i++;
        }else{
            b.erase(b.begin());
            i++;
        }
    }
    
    return rank;
}


int main(int argc, const char * argv[]) {
    cout<<findRank("baaa")<<endl;
    return 0;
}
