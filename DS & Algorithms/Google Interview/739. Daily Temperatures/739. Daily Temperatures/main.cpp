//
//  main.cpp
//  739. Daily Temperatures
//
//  Created by Giriraj Saigal on 13/11/21.
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

vector<int> solve(vector<int> x) {
    int n = (int)x.size();
    stack<int> s;
    vector<int> ans;
    
    for(int i = n-1; i >= 0; i--) {
        if(s.size() == 0)
            ans.push_back(-1);
        else if(x[s.top()] > x[i]) {
            ans.push_back(s.top());
        }else{
            while(s.size() > 0 && x[s.top()] <= x[i]){
                s.pop();
            }
            
            if(s.size() == 0)
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        
        s.push(i);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
    
vector<int> dailyTemperatures(vector<int> temp) {
    vector<int> x = solve(temp);
    vector<int> ans;
    
    for(int i = 0; i < x.size(); i++) {
        if(x[i] == -1)
            ans.push_back(0);
        else
            ans.push_back(x[i]-i);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    dailyTemperatures({73,74,75,71,69,72,76,73});
    return 0;
}
