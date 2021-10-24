//
//  main.cpp
//  1883. Minimum Skips to Arrive at Meeting On Time
//
//  Created by Giriraj Saigal on 24/10/21.
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

int solve(int n, vector<int>& dist, int speed, double travelled, double hoursBefore) {
    if(n == dist.size() && travelled <= hoursBefore)
        return 0;
    
    if(travelled > hoursBefore)
        return -1;
    
    double next = ceil(travelled);
    double now = travelled;
    
    if(next - travelled == 0.0) {
        //do not skip
        next += ((double)dist[n])/((double)speed);
        int x = solve(n+1, dist, speed, next, hoursBefore);
        
        if(x == -1)
            return -1;

        return x;
    }else{
        
        //skip
        double plus = ((double)dist[n])/((double)speed);
        now +=  plus;
        
        int y = solve(n+1, dist, speed, now, hoursBefore);
        
        now = travelled;
        
        //do not skip
        next += plus;
        int x = solve(n+1, dist, speed, next, hoursBefore);
        
        if(x == -1 && y == -1)
            return -1;
        if(x == -1)
            return y+1;
        if(y == -1)
            return x;

        return min(x,y+1);
    }
}
    
    int minSkips(vector<int> dist, int speed, int hoursBefore) {
        return solve(1, dist, speed, (double)dist[0]/(double)speed, hoursBefore);
    }

int minSkips1(vector<int> A, int s, int target) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 0; --j) {
                dp[j] += A[i];
                if (i < n - 1)
                    dp[j] = (dp[j] + s - 1) / s * s; // take a rest
                if (j > 0)
                    dp[j] = min(dp[j], dp[j - 1] + A[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dp[i] <= (long)s * target)
                return i;
        }
        return -1;
    }

int main(int argc, const char * argv[]) {
    cout << minSkips1({1,3,2},
                     4,
                     2) << endl;
    return 0;
}
