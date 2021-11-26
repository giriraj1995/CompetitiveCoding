//
//  main.cpp
//  1231. Divide Chocolate
//
//  Created by Giriraj Saigal on 26/11/21.
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

//vector<vector<int>> dp;
//
//    int sum(int i, vector<int>& sweetness) {
//        int x = 0;
//
//        for(int k = i; k < sweetness.size(); k++)
//            x += sweetness[k];
//
//        return x;
//    }
//
//    int findmin(int i, vector<int>& sweetness) {
//        int x = INT_MAX;
//        for(int k = i; k < sweetness.size(); k++)
//            x = min(sweetness[k], x);
//        return x;
//    }
//
//    int solve(int i, vector<int>& sweetness, int k) {
//        if(i == sweetness.size() && k == -1)
//            return INT_MAX;
//
//        if(sweetness.size()-i < k+1)
//            return INT_MIN;
//
//        if(sweetness.size()-i == k+1)
//            return findmin(i, sweetness);
//
//        if(k == 0){
//            return sum(i, sweetness);
//        }
//
//        if(dp[i][k] != -1)
//            return dp[i][k];
//
//        int sum = 0;
//        int ans = INT_MIN;
//
//        for(int t = i; t < sweetness.size(); t++) {
//            sum += sweetness[t];
//            int temp = solve(t+1, sweetness, k-1);
//            temp = min(temp, sum);
//            ans = max(ans, temp);
//        }
//
//        return dp[i][k] = ans;
//    }
//
//    int maximizeSweetness(vector<int> sweetness, int k) {
//        dp = vector<vector<int>>(sweetness.size()+1, vector<int>(k+1,-1));
//        return solve(0, sweetness, k);
//    }

int find(int x, vector<int>& sweetness) {
    int count = 0;
    int sum = 0;
    int n = sweetness.size();
    int i = 0;
    
    while(i < n) {
        sum += sweetness[i];
        
        if(sum >= x){
            count++;
            sum = 0;
        }
        
        i++;
    }
    
    return count;
}

int maximizeSweetness(vector<int> sweetness, int k) {
    int n = sweetness.size();
    int low = INT_MAX,high = 0;
    
    for(int i = 0; i < n; i++){
        high += sweetness[i];
        low = min(low, sweetness[i]);
    }
    
    while(low < high) {
        int mid = low + (high-low+1)/2;
        if(find(mid, sweetness) >= k+1) {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return low;
}

int main(int argc, const char * argv[]) {
    cout << maximizeSweetness({5,6,7,8,9,1,2,3,4},8) << endl;
    return 0;
}
