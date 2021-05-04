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
    string ans = "";
    map<char, int> mp;
    int len = (int)B.size();
    
    for(char c : B)
        mp[c]++;
    
    int i = 0;
    int j = 0;
    int k = 0;
    int start = 0;
    int end = -1;
    int siz = INT_MAX;
    
    while(j < (int)A.size()) {
        if(mp.find(A[j]) != mp.end() && mp[A[j]] > 0){
            mp[A[j]]--;
            k++;
        }
        
        if(len == k) {
            if((j-i+1) < siz) {
                siz = j-i+1;
                start = i;
                end = j;
            }
            
            bool isF = false;
            while(i <= j) {
                
                if(mp.find(A[i]) != mp.end() && mp[A[i]] >= 0){
                    if(isF == true)
                        break;
                    mp[A[i]]++;
                    k--;
                    isF = true;
                }
                i++;
            }
        }
        
        j++;
    }
    
    
    return A.substr(start, end-start+1);
}


int main(int argc, const char * argv[]) {
    minWindow("ADOBECODEBANC", "ABC");
    return 0;
}
