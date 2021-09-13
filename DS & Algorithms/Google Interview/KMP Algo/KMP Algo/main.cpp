//
//  main.cpp
//  KMP Algo
//
//  Created by Giriraj Saigal on 13/09/21.
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

vector<int> kmp(string s) {
    int n = s.size();
    if(n == 1)
        return {0};

    vector<int> ans(n, 0);
    int i = 1;
    int j = 0;

    while(i < n) {
        if(s[i] == s[j]){
            ans[i] = j+1;
            i++;
            j++;
            continue;
        }else{
            if(j == 0){
                ans[i] = 0;
                i++;
            }else{
                j = ans[j-1];
            }
        }
    }

    return ans;
}

string rev(string s) {
    string ans = s;
    reverse(ans.begin(), ans.end());
    return ans;
}

string shortestPalindrome(string s) {
    int n = (int)s.size();
    string x = s + "#" + rev(s);
    vector<int> k = kmp(x);
    return x.substr(n+1, n-k[x.size()-1]) + s;
}

int main(int argc, const char * argv[]) {
    cout << shortestPalindrome("aacecaaa") << endl;
    return 0;
}
