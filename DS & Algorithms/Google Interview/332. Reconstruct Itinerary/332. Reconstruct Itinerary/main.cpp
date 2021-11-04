//
//  main.cpp
//  332. Reconstruct Itinerary
//
//  Created by Giriraj Saigal on 04/11/21.
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

vector<string> ans;
    
    void solve(string u, vector<string> inp, int s, unordered_map<string, multiset<string>> mp) {
        inp.push_back(u);

        if(mp[u].size() == 0){
            
            if(inp.size() == s+1)
                ans = inp;
            
            return;
        }
        
        multiset<string> Vs = mp[u];
        
        for(string vs : Vs) {
            unordered_map<string, multiset<string>> mp2 = mp;
            auto itr = mp2[u].find(vs);
            mp2[u].erase(itr);
            solve(vs, inp, s, mp2);
            
            if(ans.size() != 0)
                return;
        }
    }
    
    vector<string> findItinerary(vector<vector<string>> tickets) {
        unordered_map<string, multiset<string>> mp;
        int n = (int)tickets.size();
        
        for(int i = 0; i < n; i++) {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        ans = {};
        solve("JFK", {}, n, mp);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    findItinerary({{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}});
    return 0;
}
