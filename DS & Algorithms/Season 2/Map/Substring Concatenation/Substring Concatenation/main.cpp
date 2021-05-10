//
//  main.cpp
//  Substring Concatenation
//
//  Created by Giriraj Saigal on 10/05/21.
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

vector<int> findSubstring(string A, const vector<string> &B) {
    if(B.size() == 0)
        return {};
    
    map<string, int> mp;
    
    for(string k : B)
        mp[k]++;
    
    vector<int> ans;
    int len = (int)B[0].size();
    int t = B.size();
    int to = t*len;
    
    for(int i = 0; i <= (int)A.size()-to; i++) {
        map<string, int> mp2 = mp;
        int j = i;
        int sz = t;
        
        if(mp2.find(A.substr(j,len)) != mp2.end()) {
            while(j <= (int)A.size()-to && mp2.find(A.substr(j,len)) != mp2.end()) {
                string f = A.substr(j,len);
                mp2[f]--;
                
                if(mp2[f] == 0)
                    mp2.erase(f);
                
                j = j+len;
            }
            
            if(mp2.size() == 0)
                ans.push_back(i);
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    string k= "barfoothefoobarman";
    vector<string> l = {"foo", "bar"};
    findSubstring(k,l);
    return 0;
}
