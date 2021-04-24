//
//  main.cpp
//  Multiply two Strings
//
//  Created by Giriraj Saigal on 22/04/21.
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

string solve(string a, string b) {
    int n = a.size();
    int m = b.size();
    
    if(a.compare("0") == 0 || b.compare("0") == 0)
        return "0";
    
    if(a.compare("1") == 0)
        return b;
    
    if(b.compare("1") == 0)
        return a;
    
    vector<char> st(n+m, '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    int k = 0;
    for(int j = 0; j < m; j++)  {
        int i;
        for(i = 0; i < n; i++) {
            int upper = a[i]-'0';
            int lower = b[j]-'0';
            
            int mul = upper*lower;
            int total = mul + st[i+k]-'0' + carry;
            st[i+k] = total%10+'0';
            carry = total/10;
            
        }
        while(carry != 0) {
            int x = st[i+k]-'0';
            int total = x + carry;
            st[i+k] = total%10+'0';
            carry = total/10;
            i++;
        }
        k++;
    }
    
    reverse(st.begin(), st.end());
    string ans = "";
    
    while(st.size() > 0 && st[0] == '0'){
        st.erase(st.begin());
    }
    
    for(int i = 0; i < st.size(); i++) {
        ans += st[i];
    }
    
    if(ans.compare("") == 0)
        return "0";
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<solve("774", "81")<<endl;
    return 0;
}
