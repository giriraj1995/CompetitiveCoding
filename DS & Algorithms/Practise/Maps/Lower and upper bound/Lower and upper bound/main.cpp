//
//  main.cpp
//  Lower and upper bound
//
//  Created by Giriraj Saigal on 24/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int solve(vector<int> &A) {
    int n = A.size();
    
    if(n < 3)
        return 0;
        
    map<int, bool> left, right;
    vector<int> le(n), re(n);
    left[A[0]] = true;
    le[0] = INT_MIN/4;
    for(int i = 1; i < n; i++) {
        
        auto k = left.lower_bound(A[i]);
        if(k == left.begin()) {
            le[i] = INT_MIN/4;
        }else{
            k--;
            le[i] = k->first;
        }
        
        left[A[i]] = true;
    }
    
    right[A[n-1]] = true;
    re[n-1] = INT_MIN/4;
    
    for(int i = n-2; i >= 0; i--) {
        
        auto k = right.lower_bound(A[i]);
        if(k == right.end()) {
            re[i] = INT_MIN/4;
        }else{
            auto l = right.end();
            l--;
            re[i] = l->first;
        }
        
        right[A[i]] = true;
    }
    
    int ans = 0;
    
    for(int i = 1; i < n-1; i++) {
        ans = max(ans, A[i] + le[i] + re[i]);
    }
    re.erase(re.begin());
    return 0;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605, 3903, 154, 293, 12383, 17422, 18717, 19719, 19896, 5448, 21727, 14772, 11539, 1870, 19913, 25668, 26300, 17036, 9895, 28704, 23812, 31323, 30334, 17674, 4665, 15142, 7712, 28254, 6869, 25548, 27645, 32663, 32758, 20038, 12860, 8724, 9742, 27530, 779, 12317, 3036, 22191, 1843, 289, 30107, 9041, 8943, 19265, 22649, 27447, 23806, 15891, 6730, 24371, 15351, 15007, 31102, 24394, 3549, 19630, 12624, 24085, 19955, 18757, 11841, 4967, 7377, 13932, 26309, 16945, 32440, 24627, 11324, 5538, 21539, 16119, 2083, 22930, 16542, 4834, 31116, 4640, 29659, 22705, 9931, 13978, 2307, 31674, 22387, 5022, 28746, 26925, 19073, 6271, 5830, 26778, 15574, 5098, 16513, 23987, 13291, 9162, 18637, 22356, 24768, 23656, 15575, 4032, 12053, 27351, 1151, 16942, 21725, 13967, 3431, 31108, 30192, 18008, 11338, 15458, 12288};
    solve(x);
    return 0;
}
