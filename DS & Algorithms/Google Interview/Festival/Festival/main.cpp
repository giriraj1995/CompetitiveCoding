//
//  main.cpp
//  Festival
//
//  Created by Giriraj Saigal on 18/09/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#define ll long long
using namespace std;

//long long getMax(int ind, priority_queue<pair<long long,pair<int,int>>> p, int high) {
//    long long ans = 0;
//
//    while(p.size() > 0 && high){
//        pair<long long,pair<int,int>> x = p.top();
//        p.pop();
//        if(ind >= x.second.first && ind <= x.second.second){
//            high--;
//            ans += x.first;
//        }
//    }
//
//    return ans;
//}
//int main(int argc, const char * argv[]) {
//    int T;
//    cin>>T;
//    int t = 1;
//    while(t <= T) {
//        int days;
//        cin>>days;
//        int attractions;
//        cin>>attractions;
//        int high;
//        cin>>high;
//        priority_queue<pair<long long,pair<int,int>>> p;
//
//        for(int i = 0; i < attractions; i++) {
//            long long h;
//            cin>>h;
//            int x;
//            cin>>x;
//            int y;
//            cin>>y;
//            p.push({h,{x,y}});
//        }
//
//        long long ans = 0;
//        for(int i = 1; i <= days; i++)
//            ans = max(ans, getMax(i, p, high));
//
//        cout<<"Case #"<<t<<": "<<ans<<endl;
//        t++;
//    }
//    return 0;
//}

int main() {
    int t;
    cin>>t;
    
    for(int T = 1; T <= t; T++) {
        ll sum = 0;
        ll ans = 0;
        int days, att, k;
        cin>>days>>att>>k;
        
        vector<pair<ll,ll>> out[days+2];
        vector<pair<ll,ll>> in[days+2];
        
        for(int i = 0; i < att; i++) {
            int h,inn,outt;
            cin>>h>>inn>>outt;
            
            out[outt+1].push_back({h,i});
            in[inn].push_back({h,i});
        }
        
        set<pair<ll,ll>> topK;
        set<pair<ll,ll>, greater<pair<ll,ll>>> avalaible;
        for(int d = 1; d <= days; d++) {
            vector<pair<ll,ll>> exit = out[d];
            for(int y = 0; y < exit.size(); y++) {
                if(topK.find(exit[y]) != topK.end()){
                    sum -= exit[y].first;
                    topK.erase(exit[y]);
                }
                
                if(avalaible.find(exit[y]) != avalaible.end()){
                    avalaible.erase(exit[y]);
                }
            }
            
            vector<pair<ll,ll>> entry = in[d];
            for(int y = 0; y < entry.size(); y++) {
                avalaible.insert(entry[y]);
            }
            
            while(topK.size() < k && avalaible.size() > 0) {
                sum += avalaible.begin()->first;
                topK.insert(*avalaible.begin());
                avalaible.erase(avalaible.begin());
            }
            
            while(topK.size() == k && avalaible.size() > 0) {
                if(avalaible.begin()->first > topK.begin()->first) {
                    pair<ll,ll> top = *topK.begin();
                    topK.erase(top);
                    pair<ll,ll> ava = *avalaible.begin();
                    avalaible.erase(ava);
                    
                    avalaible.insert(top);
                    topK.insert(ava);
                }else{
                    break;
                }
            }
            
            ans = max(ans, sum);
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
    
    return 0;
}
