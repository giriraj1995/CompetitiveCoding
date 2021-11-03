//
//  main.cpp
//  514. Freedom trail
//
//  Created by Giriraj Saigal on 31/10/21.
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

//int findRotateSteps2(string ring, string key) {
//    int n = (int)ring.size();
//
//    if(n == 0)
//        return 0;
//
//    queue<pair<int,pair<int,int>>> q;
//
//    //ring index, {steps, key index}
//    q.push({0, {0,0}});
//
//    int ans = INT_MAX;
//    set<pair<char, char>> s;
//    s.insert({ring[0], key[0]});
//
//    while(q.size() > 0) {
//        pair<int,pair<int,int>> pii = q.front();
//        q.pop();
//
//        int ringIndex = pii.first;
//        int step_still_now = pii.second.first;
//        int index_to_match = pii.second.second;
//
//        if(step_still_now > ans){
//            continue;
//        }
//
//        int curr = ringIndex;
//        int prev = (ringIndex+n-1) % n;
//        int next = (ringIndex+1) % n;
//
//        while(index_to_match != key.size() && ring[ringIndex] == key[index_to_match]) {
//            index_to_match++;
//            step_still_now++;
//        }
//
//        if(index_to_match == key.size()) {
//            ans = min(ans, step_still_now);
//            continue;
//        }
//
//        q.push({prev, {step_still_now+1, index_to_match}});
//        q.push({next, {step_still_now+1, index_to_match}});
//
//    }
//
//    return ans;
//}
//
//int solve(int i, int j, string ring, string key) {
//    if(j == key.size()){
//        return 0;
//    }
//
//    int n = (int)ring.size();
//
//    int curr = i;
//    int prev = i + n - 1;
//    int next = ( i + 1 ) % n;
//
//    int steps = 0;
//
//    while(j != key.size() && ring[curr] == key[j]) {
//        steps++;
//        j++;
//    }
//
//    if(j == key.size()) {
//        return steps;
//    }
//
//    //go anti - clock
//    int x = 1 + steps + solve(prev, j, ring, key);
//
//    //go clock
//    int y = 1 + steps + solve(next, j, ring, key);
//
//    return min(x,y);
//}
//
//int findRotateSteps(string ring, string key) {
//    return solve(0, 0, ring, key);
//}

vector<vector<int>> dp;
   int solve(int i, int j, string ring, string key, map<char, vector<int>> &mp) {
       if(j == key.size())
           return 0;
       
       if(dp[i][j] != -1)
           return dp[i][j];
       
       int n = ring.size();
       int temp = INT_MAX;
       
       for(int next : mp[key[j]]) {
           int steps = min((int)abs(next - i), (int)min((int)abs(i + n - next), (int)abs(next - (i - n))));
           temp = min(1 + steps + solve(next, j+1, ring, key, mp), temp);
       }
       
       return dp[i][j] = temp;
   }
   
   int findRotateSteps(string ring, string key) {
       int n = ring.size();
       int m = key.size();
       dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
       map<char, vector<int>> mp;
       
       for(int i = 0; i < n; i++) {
           mp[ring[i]].push_back(i);
       }
       
       return solve(0, 0, ring, key, mp);
   }

int main(int argc, const char * argv[]) {
    cout << findRotateSteps2("czjdn",
                            "zzznnnjjjdddccc") << endl;
    return 0;
}
