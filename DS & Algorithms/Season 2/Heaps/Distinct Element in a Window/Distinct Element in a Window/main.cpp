//
//  main.cpp
//  Distinct Element in a Window
//
//  Created by Giriraj Saigal on 20/05/21.
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

vector<int> dNums(vector<int> &A, int B) {
    map<int, int> mp;
    vector<int> ans;
    int i = 0;
    while(i < B) {
        mp[A[i++]]++;
    }
    
    ans.push_back(mp.size());
    
    while(i < (int)A.size()) {
        mp[A[i-B]]--;
        
        if(mp[A[i-B]] == 0)
            mp.erase(A[i-B]);
        
        mp[A[i]]++;
        
        ans.push_back(mp.size());
        i++;
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
