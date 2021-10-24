//
//  main.cpp
//  Seive Algo
//
//  Created by Giriraj Saigal on 23/10/21.
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

int find(int x, unordered_map<int, int> &parent) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x], parent);
}
void unionXY(int x, int y, unordered_map<int, int> &parent) {
        int p = find(x, parent);
        int q = find(y, parent);
        
        if(p != q) {
            parent[p] = q;
        }
    }
    
    void seive(int high, unordered_map<int, int> &parent, set<int> s) {
        int p = 2;
        vector<bool> prims(high+1, true);
        while(p < high) {
            int prev = 0;
                if(prims[p]){
                    for(int k = p; k <= high; k+=p){
                        prims[p] = false;
                        if(s.count(k)){
                            if(prev > 0)
                                unionXY(k, prev, parent);
                            prev = k;
                        }
                        prims[k] = false;
                    }
                }
            p+=1;
        }
    }

    bool gcdSort(vector<int> nums) {
       int n = (int)nums.size();
        if(n <= 1)
            return true;
        
        int high = 2;
        set<int> s;
        s.clear();
        for(int i : nums){
            s.insert(i);
            high = max(high, i);
        }
        
        unordered_map<int, int> parent;
        parent.clear();
        
        for(int i = 0; i < nums.size(); i++){
            parent[nums[i]] = (nums[i]);
        }
        
        seive(high, parent, s);
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != sorted[i] && find(nums[i], parent) != find(sorted[i], parent))
                return false;
        }
        
        return true;
    }
int main(int argc, const char * argv[]) {
    cout << gcdSort({7,21,3});
    return 0;
}
