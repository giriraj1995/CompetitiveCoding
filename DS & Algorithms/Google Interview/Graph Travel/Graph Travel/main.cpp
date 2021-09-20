//
//  main.cpp
//  Graph Travel
//
//  Created by Giriraj Saigal on 19/09/21.
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

//using namespace std;
//
//vector<int> powMinReq(16);
//vector<int> powMaxReq(16);
//vector<int> power(16);
//long long req;
//
//void solve(int &pos, int i, vector<int> visited, long long sum, unordered_map<int, vector<int>> mp) {
//
//    if(visited[i] == 0){
//        visited[i] = 1;
//        sum += power[i];
//    }
//
//    if(sum > req)
//        return;
//
//    if(sum == req){
//        pos++;
//        return;
//    }
//
//    for(int v : mp[i]) {
//        if(visited[v] == 0 && sum >= powMinReq[v] && sum <= powMaxReq[v]) {
//            solve(pos,v,visited,sum,mp);
//        }
//    }
//
//    for(int v : mp[i]) {
//
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    int T;
//    cin>>T;
//    int t = 1;
//
//    while(t <= T){
//        int ans = 0;
//        int rooms;
//        cin>>rooms;
//        int coor;
//        cin>>coor;
//        long long k;
//        cin>>k;
//        req = k;
//
//        for(int i = 0; i < rooms; i++) {
//            cin>>powMinReq[i];
//            cin>>powMaxReq[i];
//            cin>>power[i];
//        }
//
//        unordered_map<int, vector<int>> mp;
//
//        for(int i = 0; i < coor; i++) {
//            int x;
//            cin>>x;
//            int y;
//            cin>>y;
//            mp[x].push_back(y);
//            mp[y].push_back(x);
//        }
//
//        vector<int> visited(rooms, 0);
//        int pos = 0;
//        int sum = 0;
//        for(int i = 0; i < rooms; i++) {
//            pos = 0;
//            sum = 0
//            solve(pos, i, visited, sum, mp);
//            ans += pos;
//        }
//
//        cout<<"Case #"<<t<<": "<<ans<<endl;
//        t++;
//    }
//    return 0;
//}

////#include<bits/stdc++.h>
//using namespace std;
//
//const int maxN = 16;
//const int ways = (1<<maxN);
//
//int adj[maxN];
//long long a[maxN];
//long long l[maxN], r[maxN];
//
//int n;
//long long k;
//
//long long DP[ways];
//
//
//long long solve(int mask, long long currSum)
//{
//    if(DP[mask] != -1)
//        return DP[mask];
//
//    DP[mask] = 0;
//
//    if(currSum == k)
//        DP[mask] += 1;
//
//    int next = 0;
//    for(int i=0;i<n;i++)
//    {
//        if(mask & (1<<i)){
//            next |= adj[i];
//        }
//    }
//
//    next = (next ^ (next & mask));
//
//    for(int i=0;i<n;i++)
//    {
//        if(next & (1<<i))
//        {
//            if(currSum >= l[i] && currSum <= r[i])
//                DP[mask] += solve(mask ^ (1<<i), currSum + a[i]);
//        }
//    }
//
//    return DP[mask];
//}
//
//void solve()
//{
//    int m;
//    cin>>n>>m>>k;
//
//    for(int i=0;i<n;i++)
//    {
//        cin>>l[i]>>r[i]>>a[i];
//        adj[i] = 0;
//    }
//
//    int x,y;
//    while(m--)
//    {
//
//        cin>>x>>y;
//        //x--,y--;
//
//        adj[x] |= (1<<y);
//        adj[y] |= (1<<x);
//    }
//
//    for(int i=0;i<(1<<n);i++)
//        DP[i] = -1;
//
//    long long ans = 0;
//    for(int i=0;i<n;i++)
//    {
//        ans += solve((1<<i), a[i]);
//    }
//
//    cout<<ans<<endl;
//}
//
//int main()
//{
//    int t;
//    cin>>t;
//
//    for(int i=1;i<=t;i++)
//    {
//        cout<<"Case #"<<i<<": ";
//        solve();
//    }
//
//    return 0;
//}
int req;
int tot;
const int maxN = 16;
const int ways = (1<<maxN);
int adj[ways];

int solve(int u, long long sum, int mask, vector<int> power, vector<int> minReq, vector<int> maxReq,
          vector<int> &DP) {
    if(DP[mask] != -1)
        return DP[mask];
    
    DP[mask] = 0;
    
    if(sum == req){
        DP[mask]++;
    }
    
    int next = 0;
    for(int i = 0; i < tot; i++) {
        if(1<<i & mask){
            next |= adj[i];
        }
    }
    
    next = next ^ (next&mask);
    
    for(int i = 0; i < tot; i++) {
        if((1<<i) & next) {
            if(sum >= minReq[i] && sum <= maxReq[i])
                DP[mask] += solve(i,sum+power[i],mask|(1<<i),power,minReq,maxReq,DP);
        }
    }
    
    return DP[mask];
}

int main() {
    int T;
    cin>>T;
    
    for(int t = 1; t <= T; t++) {
        int n,e,k;
        cin>>n>>e>>k;
        vector<int> minReq(n);
        vector<int> maxReq(n);
        vector<int> power(n);
        req = k;
        tot = n;
        for(int i = 0; i < n; i++){
            cin>>minReq[i]>>maxReq[i]>>power[i];
        }
                
        for(int i = 0; i < e; i++){
            int p,q;
            cin>>p>>q;
            adj[p] |= (1<<q);
            adj[q] |= (1<<p);
        }
        
        int ans = 0;
        vector<int> DP(1<<n, -1);
        for(int i = 0; i < n; i++){
            int mask = 0;
            mask |= (1<<i);
            ans += solve(i, power[i], mask, power, minReq, maxReq, DP);
        }
        
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    
    return 0;
}
