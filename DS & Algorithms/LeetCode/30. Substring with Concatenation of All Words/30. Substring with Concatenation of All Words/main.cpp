//
//  main.cpp
//  30. Substring with Concatenation of All Words
//
//  Created by Giriraj Saigal on 04/04/21.
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

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> words) {
        map<string,int> dic;
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        
        if(len*m > n)
            return {};
        
        for(string k : words) {
            dic[k]++;
        }
        
        vector<int> ans;
        for(int i = 0; i <= n - len*m; i++) {
            map<string,int> ref = dic;
            
            int j = i;
            bool yes = true;
            while(ref.size() > 0) {
                if(ref.find(s.substr(j,len)) != ref.end()) {
                    ref[s.substr(j,len)]--;

                    if(ref[s.substr(j,len)] == 0) {
                        ref.erase(s.substr(j,len));
                    }
                    
                    j+=len;
                }else{
                    yes = false;
                    break;
                }
            }
            
            if(yes) {
                ans.push_back(i);
            }
            
        }
        
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution *s = new Solution();
    vector<int> ans = s->findSubstring("barfoothefoobarman",{"foo","bar"});
    return 0;
}
