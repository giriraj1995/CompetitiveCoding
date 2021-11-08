//
//  main.cpp
//  43. Multiply Strings
//
//  Created by Giriraj Saigal on 07/11/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <set>
using namespace std;

string multiply(string num1, string num2) {
        int n = (int)num1.size();
        int m = (int)num2.size();
        
        vector<int> mul(n+m, 0);
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {

                int x = num1[i] - '0'; //above
                int y = num2[j] - '0'; //below
                
                int m = x*y;
                int add = mul[i+j] + m;
                mul[i+j] = add%10;
                mul[i+j+1] = mul[i+j+1] + add/10;
                
            }
        }
        
        string ans = "";
        for(int i = 0; i < n+m; i++) {
            ans.push_back(mul[i] + '0');
        }
        
        reverse(ans.begin(), ans.end());
        
        while(ans.size() > 0 && ans[0] == '0') {
            ans.erase(ans.begin());
        }
        
        return ans == "" ? "0" : ans;
    }

int main(int argc, const char * argv[]) {
    string x;
    string y;
    
    cout << "Enter x : ";
    cin >> x;
    
    cout << "Enter y : ";
    cin >> y;
    
    cout << "Multiplication :" << multiply(x,y) << endl;
    return 0;
}
