//
//  main.cpp
//  Points on the Straight Line
//
//  Created by Giriraj Saigal on 09/05/21.
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

int maxPoints(vector<int> A, vector<int> B) {
    long long mx = 0;
    
    if(A.size() <= 2)
        return A.size();
    
    map<pair<int,int>,int> mp;
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++) {
        mp[{A[i],B[i]}]++;
        ans = max(ans, mp[{A[i],B[i]}]);
    }
    
    if(ans = A.size())
        return ans;
    
    map<double, int> mp_m;
    
    
    return -1;
}


int main(int argc, const char * argv[]) {
    cout<<maxPoints({1, 1, 1, 1, 1},{1, 1, 1,1,1})<<endl;
    return 0;
}
