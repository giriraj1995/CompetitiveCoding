//
//  main.cpp
//  952. Largest Component Size by Common Factor
//
//  Created by Giriraj Saigal on 23/11/21.
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

int find(int x, vector<int> &parent) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x], parent);
}

void unionj(int x, int y, vector<int> &size, vector<int> &parent) {
    int px = find(x, parent);
    int py = find(y, parent);
    
    if(px == py)
        return;
    
    if(size[px] > size[py]) {
        size[px] += size[py];
        parent[py] = px;
    }else{
        size[py] += size[px];
        parent[px] = py;
    }
}

int largestComponentSize(vector<int> nums) {
    unordered_map<int, int> mp;
    int n = (int)nums.size();
    int high = INT_MIN;

    for(int i = 0; i < n; i++){
        mp[nums[i]] = i;
        high = max(high, nums[i]);
    }
    
    vector<int> size(n, 1);
    vector<int> parent(n, -1);
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    if(n == 1)
        return 1;
    
    vector<bool> prime(high+1, true);
    
    for(int i = 2; i <= high; i++) {
        if(prime[i] == true) {
            int prev = -1;
            for(int j = i; j <= high; j+=i) {
                if(mp.count(j)) {
                    if(prev != -1) {
                        unionj(mp[prev], mp[j], size, parent);
                    }
                    prev = j;
                }
                prime[j] = false;
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
        ans = max(ans, size[i]);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << largestComponentSize({2,3,6,7,4,100000,21,39}) << endl;
    return 0;
}
