//
//  main.cpp
//  First Repeating element
//
//  Created by Giriraj Saigal on 06/05/21.
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

int solve(vector<int> A) {
    int ans = INT_MAX;
    map<int,int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        if(mp.find(A[i]) != mp.end()) {
            ans = min(ans, mp[A[i]]);
        }else{
            mp[A[i]] = i;;
        }
    }
    
    return ans == INT_MAX ? -1 : A[ans];
}


int main(int argc, const char * argv[]) {
    cout<<solve( {10, 5, 3, 4, 3, 5, 6} )<<endl;
    return 0;
}
