//
//  main.cpp
//  Buy and sell 2
//
//  Created by Giriraj Saigal on 09/08/21.
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

    int maxProfit(vector<int> prices) {
        vector<int> left(prices.size());
        vector<int> right(prices.size());

        int low = prices[0];
        int profit = 0;
        left[0] = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - low);
            left[i] = profit;
            low = min(low, prices[i]);
        }
        
        right[prices.size()-1] = 0;
        int high = prices[prices.size()-1];
        profit = 0;
        
        for(int i = prices.size()-2; i >= 0; i--) {
            profit = max(high - prices[i], profit);
            right[i] = profit;
            high = max(high, prices[i]);
        }
        
        int ans = 0;
        ans = max(left[prices.size()-1], ans);
        for(int i = 0; i < prices.size()-1; i++) {
            ans = max(left[i] + right[i+1], ans);
        }
        
        return ans;
        
    }

int main(int argc, const char * argv[]) {
    cout << maxProfit({1,2,3,4,5}) << endl;
    return 0;
}
