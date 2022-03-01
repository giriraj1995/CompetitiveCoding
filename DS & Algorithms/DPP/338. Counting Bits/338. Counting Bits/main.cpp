//
//  main.cpp
//  338. Counting Bits
//
//  Created by Giriraj Saigal on 02/03/22.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        
        if(n == 1)
            return {0,1};
        
        vector<int> ans(n+1, 0);
        ans[0] = 0;
        ans[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            if(i % 2 != 0)
                ans[i] = ans[i-1]+1;
            else{
                if(log2(i) - (int)(log2(i)) == 0.0){
                    ans[i] = 1;
                }else{
                    ans[i] = 1 + ans[i - pow(2, (int)(log2(i)))];
                }
            }
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> x = s.countBits(23);
    return 0;
}
