//
//  main.cpp
//  394. Decode String
//
//  Created by Giriraj Saigal on 19/12/21.
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
    string times(string k, int i, int j, int t) {
        
        k = k.substr(i, j-i+1);
        string ans = "";
        while(t--) {
            ans += k;
        }
        return ans;
    }
    
    string solve(string s, int i, int j) {
        
        stack<int> st;
        for(int k = i; k <= j; k++) {
            if(s[k] == '[') {
                st.push(k);
            }else if(s[k] == ']') {
                int p = st.top();
                st.pop();
                string g;
                
                int newL;
                int oddL;
                
                if(s[p-1] <= '9' && p-2 >= 0 && s[p-2] <= '9' && p-3 >= 0 && s[p-3] <= '9'){
                    g = times(s, p+1, k-1, stoi(s.substr(p-3,3)));
                    oddL = k - (p-3) + 1;
                    newL = g.size();
                    s = s.substr(0, p-3) + g + s.substr(k+1);
                }else if(s[p-1] <= '9' && p-2 >= 0 && s[p-2] <= '9') {
                    g = times(s, p+1, k-1, stoi(s.substr(p-2,2)));
                    oddL = k - (p-2) + 1;
                    newL = g.size();
                    s = s.substr(0, p-2) + g + s.substr(k+1);
                }else{
                    g = times(s, p+1, k-1, stoi(s.substr(p-1,1)));
                    oddL = k - (p-1) + 1;
                    newL = g.size();
                    s = s.substr(0, p-1) + g + s.substr(k+1);
                }

                k = k + newL - oddL;
                j = s.size()-1;
            }
        }
        
        return s;
    }
    
    string decodeString(string s) {
        return solve(s, 0, s.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
