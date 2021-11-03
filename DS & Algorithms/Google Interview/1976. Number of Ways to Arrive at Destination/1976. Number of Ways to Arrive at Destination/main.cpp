//
//  main.cpp
//  1976. Number of Ways to Arrive at Destination
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

int countPaths(int n, vector<vector<int>> roads) {
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        unordered_map<int, vector<pair<int,int>>> mp;
        
        for(auto k : roads) {
            mp[k[0]].push_back({k[1],k[2]});
            mp[k[1]].push_back({k[0],k[2]});
        }
        
        //dis, i
        q.push({0, 0});
        dis[0] = 0;
        
        int minTime = INT_MAX;
        vector<int> count(n,0);
        count[0] = 1;
        int res = INT_MAX;
        
        while(q.size() > 0) {
            int ind = q.top().second;
            int d = q.top().first;
            q.pop();
            
            for(auto v : mp[ind]) {
                if(dis[ind] + v.second < dis[v.first]) {
                    dis[v.first] = dis[ind] + v.second;
                    q.push({dis[v.first], v.first});
                    count[v.first] = count[ind];
                }else if(dis[ind] + v.second == dis[v.first]){
                    count[v.first] += count[ind];
                }
                
                if(v.first == n-1) {
                    if(dis[ind] + v.second < minTime) {
                        minTime = dis[v.first];
                        res = count[ind];
                    }else if(dis[ind] + v.second == minTime){
                        res += count[ind];
                    }
                }
            }
        }
        
        return res;
    }

int main(int argc, const char * argv[]) {
    cout << countPaths(7, {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}}) << endl;
    return 0;
}
