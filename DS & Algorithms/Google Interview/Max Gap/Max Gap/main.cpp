//
//  main.cpp
//  Max Gap
//
//  Created by Giriraj Saigal on 12/09/21.
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

int maximumGap(vector<int> x) {
    int n = x.size();
    if(n < 2)
        return 0;

    vector<int> y(n, INT_MAX);
    set<int> s;
    int i;
    int ans = 0;

    for(i = 0; i < n; i++) {
        int t = x[i];
        s.erase(x[i]);
        auto k = s.lower_bound(t);
        if(k != s.end()) {
            int ele = *k;
            y[i] = min(y[i], ele - t);
        }
        s.insert(x[i]);
    }

    s.clear();
    for(i = n-1; i >= 0; i--) {
        s.erase(x[i]);
        auto k = s.lower_bound(x[i]);
        if(k != s.end()) {
            y[i] = min(y[i], *k - x[i]);
        }
        s.insert(x[i]);
    }

    for(int i = 0; i < n; i++) {
        if(y[i] != INT_MAX)
            ans = max(ans, y[i]);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    cout << maximumGap({15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740}) << endl;
}
