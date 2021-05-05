//
//  main.cpp
//  Longest Substring Without Repeat
//
//  Created by Giriraj Saigal on 05/05/21.
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

int lengthOfLongestSubstring(string A) {
    map<char, int> mp;
    int ans = 0;
    int i = 0;
    int j = 0;
    int len = 0;
    int st = 0;
    
    while(j < (int)A.size()) {
        if(mp.find(A[j]) != mp.end()) {
            if(j-i > len) {
                len = j-i;
                st = i;
            }
            
            while(mp.find(A[j]) != mp.end()) {
                mp[A[i]]--;
                
                if(mp[A[i]] == 0)
                    mp.erase(A[i]);
                
                i++;
            }
        }
        
        mp[A[j]]++;
        j++;
        
        if(j-i > len) {
            len = j-i;
            st = i;
        }
    }
    
    return len;
}


int main(int argc, const char * argv[]) {
    cout<<lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}
