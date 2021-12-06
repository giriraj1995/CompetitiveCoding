//
//  main.cpp
//  1217. Minimum Cost to Move Chips to The Same Position
//
//  Created by Giriraj Saigal on 06/12/21.
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

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        
        for(int p : position) {
            if(p&1)
                odd++;
            else
                even++;
        }
        
        return min(odd,even);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
