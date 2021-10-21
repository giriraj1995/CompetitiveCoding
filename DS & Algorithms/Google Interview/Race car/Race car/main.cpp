//
//  main.cpp
//  Race car
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

int racecar(int target) {
        vector<int> dp(target+3);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 4;
        
        if(target < 2)
            return target;
        
        for(int i = 3; i <= target; i++) {
            int pos = 0;
            int speed = 1;
            int steps = 0;
            
            while(pos < i) {
                pos += speed;
                speed *= 2;
                steps++;
            }
            
            if(pos == i){
                dp[i] = steps;
                continue;
            }
            //ans 1 when exceeds
            //0 1 3 7 15
            int afterT = (1<<steps) - 1;
            int ans1 = steps + 1 + dp[afterT - i];
            
            //ans 2 when behind
            int ans2 = INT_MAX;
            for(int j = 0; j < steps-1; j++) {
                int beforeT = (1<<(steps-1)) - 1;
                int afterJ = (1<<j) - 1;
                ans2 = min(ans2, steps - 1 + 1 + j + 1 + dp[i - beforeT + afterJ]);
            }
            
            dp[i] = min(ans1, ans2);
        }
        return dp[target];
    }

int racecar1(int target) {
        
        queue<pair<int,int>> q;
        q.push({0,1});
        set<pair<int,int>> mem;
        mem.insert({0,1});
        int level = 0;
        
        while(q.size() > 0) {
            int k = q.size();
            
            for(int i = 0; i < k; i++) {
                int pos = q.front().first;
                int speed = q.front().second;
                q.pop();
                
                if(pos == target)
                    return level;
                //A
                int new_pos = pos + speed;
                int new_speed = speed*2;
                
                if(new_pos < 2*target  && mem.count({new_pos, new_speed}) == 0 && new_pos > 0) {
                    q.push({new_pos, new_speed});
                    mem.insert({new_pos, new_speed});
                }
                
                //R
                new_speed = speed >= 1 ? -1 : 1;
                
                if(pos < 2*target && mem.count({pos, new_speed}) == 0 && pos > 0) {
                    q.push({pos, new_speed});
                    mem.insert({pos, new_speed});
                }
            }
            level++;
        }
        
        return -1;
    }

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int count = 0;
    for(int i : arr) i == 1 ? count++ : count = count + 0;
    cout << racecar(20) << endl;
    return 0;
}
