//
//  main.cpp
//  Between 2 sets
//
//  Created by Giriraj Saigal on 23/02/21.
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
typedef long long int ll;
using namespace std;

ll hcf(ll a, ll b) {
    if(b > a) {
        return hcf(b, a);
    }
    if(b == 0)
        return a;
    return hcf(b, a%b);
}

ll getTotalX(vector<int> a, vector<int> b) {
    //lcm of a
    //hcf of b
    
    ll gcd = b[0];
    ll lcm = a[0];
    
    for(int i = 1; i < b.size(); i++) {
        gcd = hcf(b[i],gcd);
    }
    
    for(int i = 1; i < a.size(); i++) {
        lcm = (lcm * a[i]) / hcf(lcm, a[i]);
    }
    
    int ans = 0;
    int x = lcm;
    int f = 1;
    while((x <= gcd)) {
        if((gcd % (x) == 0)){
            ans++;
        }
        f++;
        x = lcm*f;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<getTotalX({2,4}, {16,32,96});
    return 0;
}
