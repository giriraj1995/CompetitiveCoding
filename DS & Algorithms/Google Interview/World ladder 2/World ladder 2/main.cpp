//
//  main.cpp
//  World ladder 2
//
//  Created by Giriraj Saigal on 29/09/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
using namespace std;

vector<vector<string> > findLadders(string start, string end,
vector<string> dict) {
    unordered_map<string, int> mp;
    
    int k = 0;
    for(string x : dict){
        mp[x] = k++;
    }
    
    if(!mp.count(end))
        mp[end] = k++;
    
    
    queue<pair<pair<string ,string>, vector<string>>> q;
    q.push({{start, string(k, '0')},{}});
    vector<vector<string>> ans;
    
    while(q.size() > 0) {
        string f = q.front().first.first;
        string con = q.front().first.second;
        vector<string> vec = q.front().second;
        q.pop();
        
        vec.push_back(f);
        
        if(f == end) {
            if(ans.size() == 0){
                ans.push_back(vec);
            }else if(ans[0].size() > vec.size()) {
                ans.clear();
                ans.push_back(vec);
            }else if(ans[0].size() == vec.size()) {
                ans.push_back(vec);
            }
            
            continue;
        }
        
        for(int i = 0; i < 26; i++) {
            char c = 'a'+i;
            for(int j = 0; j < f.size(); j++) {
                string temp = f;
                temp[j] = c;
                if(temp != f && mp.count(temp) && con[mp[temp]] == '0') {
                    con[mp[temp]] = '1';
                    q.push({{temp, con},vec});
                    con[mp[temp]] = '0';
                }
            }
        }
    }
    
    
    return ans;
}
int main(int argc, const char * argv[]) {
    findLadders("hit","cog",{"hot","dot","dog","lot","log"});
    return 0;
}
