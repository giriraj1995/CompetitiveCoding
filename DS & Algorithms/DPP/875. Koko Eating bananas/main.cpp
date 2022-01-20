#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;;

class Solution {
public:
    
    bool isPossible(vector<int> &piles, int m, int h) {
        int x = 0;
        
        for(int i : piles) {
            x += ceil(i/(m*1.0));
            
            if(x > h)
                return false;
        }
        
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int hi = 1;
        
        for(int i : piles){
            hi = max(hi, i);
        }
        
        int ans = -1;
        
        while(l <= hi) {
            int m = l + (hi-l)/2;
            
            if(isPossible(piles, m, h)) {
                ans = m;
                hi = m-1;
            }else{
                l = m+1;
            }
        }
        
        return ans;
    }
};
