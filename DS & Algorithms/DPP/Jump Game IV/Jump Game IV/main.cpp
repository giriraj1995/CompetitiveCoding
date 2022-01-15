//
//  main.cpp
//  Jump Game IV
//
//  Created by Giriraj Saigal on 15/01/22.
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

int minJumps(vector<int> arr) {
    int n = arr.size();
    
    if(n == 1)
        return 0;
    
    unordered_map<int, int> mp;
    
    // for(int i = 0; i < arr.size(); i++) {
    //     mp[arr[i]].insert(i);
    // }
    
    int ans = n - 1;
    
    //index to step
    queue<pair<int, int>> q;
    set<pair<int,int>> s;
    q.push({0, 0});
    
    while(q.size() > 0) {
        int index = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if(step > ans)
            continue;
        
        if(index == n-1){
            if(mp.count(arr[index]))
                step = min(step, mp[arr[index]]+1);
            ans = min(ans, step);
            continue;
        }
        
        //index, step
        if(mp.count(arr[index])) {
            if(step > mp[arr[index]]+1) {
                step = mp[arr[index]]+1;
                if(s.count({index, step}) == 0){
                    q.push({index, step});
                    s.insert({index, step});
                }
            }
        }
        
        if(index + 1 < n){
            if(s.count({index+1, step+1}) == 0){
                q.push({index+1, step+1});
                s.insert({index+1, step+1});
            }
        }
        
        if(index - 1 >= 0 && mp[arr[index-1]] > step+1){
            if(s.count({index-1, step+1}) == 0){
                q.push({index-1, step+1});
                s.insert({index-1, step+1});
            }
        }
        
        if(mp.count(arr[index]))
            mp[arr[index]] = min(step, mp[arr[index]]);
        else
            mp[arr[index]] = step;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << minJumps({100,-23,-23,404,100,23,23,23,3,404}) << endl;
    return 0;
}
