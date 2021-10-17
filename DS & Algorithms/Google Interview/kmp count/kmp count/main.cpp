//
//  main.cpp
//  kmp count
//
//  Created by Giriraj Saigal on 16/10/21.
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

int countPattern(string p, string s) {
        int n = p.size();
        vector<int> pi(n,0);
        
        int j = 1;
        int i = 0;
        
        // g i r g i r a g i j k
        // 0 0 0 1 2 3 0 1 2 3 0
        
        while(j < n) {
            if(p[j] == p[i]){
                pi[j] = i + 1;
                i++;
                j++;
            }else{
                if(i == 0){
                    pi[j] = 0;
                    j++;
                }else{
                    i = pi[i-1];
                }
            }
        }
        
        j = 0;
        i = 0;
        int m = s.size();
        int count = 0;
        
        while(j < m) {
            if(i == p.size()) {
                count++;
                i = 0;
            }
            if(p[i] == s[j]) {
                i++;
                j++;
            }else{
                if(i == 0) {
                    j++;
                }else{
                    i = pi[i-1];
                }
            }
        }
        
        if(i == p.size()) {
            count++;
            i = 0;
        }
        return count;
    }

int main(int argc, const char * argv[]) {
    cout << countPattern("xyz", "xyzabcxyzabcxyzzabxyzcdexyzfgxyz") << endl;
    return 0;
}
