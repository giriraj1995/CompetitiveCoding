//
//  main.cpp
//  Window String
//
//  Created by Giriraj Saigal on 04/05/21.
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

string minWindow(string A, string B) {
    int rem = (int)B.size();
    map<char, int> mp;
    
    int i = 0, j = 0;
    
    while(j < (int)B.size()) {
        mp[B[j]]++;
        j++;
    }
    
    j = 0;
    int ans = INT_MAX;
    int st = 0;
    
    while(j < (int)A.size()) {
        if(--mp[A[j++]] >= 0) {
            rem--;
        }
        
        while(rem == 0) {
            if(j-i < ans) {
                ans = j-i;
                st = i;
            }
            
            if(++mp[A[i++]] > 0)
                rem++;
        }
    }
    
    return ans == INT_MAX ? "" : A.substr(st,ans);
}


int main(int argc, const char * argv[]) {
    cout<<minWindow("w", "o")<<endl;
    return 0;
}
