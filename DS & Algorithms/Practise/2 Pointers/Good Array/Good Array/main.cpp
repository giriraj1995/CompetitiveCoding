//
//  main.cpp
//  Good Array
//
//  Created by Giriraj Saigal on 09/01/21.
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

int solve(vector<int> A, int B) {
    
    unordered_map<int, int> mp;
    int j = 0;
    int i = 0;
    int ans = 0;
    while(j < A.size()) {
        mp[A[j]]++;
        
        if(mp.size() == B) {
            ans++;
            
            if((j == A.size() - 1) || (mp.find(A[j+1]) == mp.end())) {
                
                    mp[A[i]]--;
                    
                    if(mp[A[i]] == 0){
                        mp.erase(A[i]);
                        i++;
                        break;
                    }
                    
                    ans++;
                    i++;
                }
            }
            else if(mp.size() > B) {
            
            while(mp.size() > B) {
                mp[A[i]]--;
                if(mp[A[i]] == 0)
                    mp.erase(A[i]);
                i++;
            }
            
            ans++;
            
            if((j == A.size() - 1) ||
               (mp.find(A[j+1]) == mp.end())) {
                while(mp.size() == B) {
                    mp[A[i]]--;
                    
                    if(mp[A[i]] == 0){
                        mp.erase(A[i]);
                        i++;
                        break;
                    }
                    
                    ans++;
                    i++;
                }
            }
        }
        
        j++;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({5, 3, 5, 1, 3 }, 3);
    return 0;
}
