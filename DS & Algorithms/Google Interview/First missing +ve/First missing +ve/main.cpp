//
//  main.cpp
//  First missing +ve
//
//  Created by Giriraj Saigal on 19/10/21.
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

int findMissing(vector<int> x) {
        int i = 0;
        int n = x.size();
        
        for(;i < n; i++) {
            if(x[i] > n || x[i] <= 0)
                x[i] = n+1;
        }
        
        for(i = 0; i < n; i++) {
            if(x[i] == abs(n+1))
                continue;
            x[abs(x[i])-1] = -1 * abs(x[abs(x[i])-1]);
        }
        
        for(int i = 0; i < n; i++) {
            if(x[i] > 0)
                return i+1;
        }
        
        return n+1;
    }

int main(int argc, const char * argv[]) {
    cout << findMissing({3,4,2,1,6,-34,7,8}) << endl;
    return 0;
}
