//
//  main.cpp
//  936. Stamping The Sequence
//
//  Created by Giriraj Saigal on 18/11/21.
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


    vector<int> movesToStamp(string stamp, string target) {
        char firstLetter = stamp[0];
        vector<int> inds;
        
        for(int i = 0; i < target.size(); i++)
            if(firstLetter == target[i])
                inds.push_back(i);
        
        if(inds.size() == 0)
            return {};
        
        if(inds.size() == target.size()){
            return inds;
        }
        
        queue<pair<string, vector<int>>> q;
        q.push({string(target.size(), '?'), {}});
        int turn = 0;
        
        while(q.size() > 0) {
            
            int x = q.size();
            
            if(turn > 10 * target.size())
                return {};
            
            for(int i = 0; i < x; i++) {
                string curr = q.front().first;
                vector<int> vec = q.front().second;
                q.pop();
                
                if(curr == target)
                    return vec;
                    
                for(int i = 0; i <= target.size()-stamp.size(); i++) {
                    if(vec.size() > 0 && i == vec[vec.size()-1])
                        continue;
                    
                    vector<int> f = vec;
                    f.push_back(i);
                    int prev = i;
                    int sn = stamp.size();
                    int next = target.size() - sn - prev;
                    string t;
                    if(next < 0) {
                        t = curr.substr(0,i) +  stamp.substr(0, target.size() - i);
                    }else{
                        t = curr.substr(0,i) + stamp + curr.substr(i + stamp.size());
                    }
                    q.push({t, f});
                }
            }
            
            turn++;
        }
        
        return {};
    }

int main(int argc, const char * argv[]) {
    vector<int> x = movesToStamp("abca","aabcaca");
    return 0;
}
