//
//  main.cpp
//  402. Remove K Digits
//
//  Created by Giriraj Saigal on 29/10/21.
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

string removeKdigits(string num, int k) {
        stack<char> s;
        s.push(num[0]);
        int n = num.size();
        
        for(int i = 1; i < n; i++) {
            while(k > 0 && s.size() > 0 && s.top() > num[i]) {
                k--;
                s.pop();
            }
            
            if(num[i] == 0 && s.size() == 0)
                continue;
            
            s.push(num[i]);
        }
        
        while(s.size() > 0 && k > 0) {
            s.pop();
            k--;
        }
        
        string ans = "";
        
        while(s.size() > 0) {
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans == "" ? "0" : ans;
    }

int main(int argc, const char * argv[]) {
    removeKdigits("1432219",
                  3);
    return 0;
}
