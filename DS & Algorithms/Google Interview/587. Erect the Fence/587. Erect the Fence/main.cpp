//
//  main.cpp
//  587. Erect the Fence
//
//  Created by Giriraj Saigal on 21/10/21.
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

int cartiansProduct(vector<int> a, vector<int> b, vector<int> c) {
        return (c[1] - a[1]) * (b[0] - a[0]) - (b[1] - a[1]) * (c[0] - a[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>> trees) {
        int n = trees.size();
        
        if(n <= 3)
            return trees;
        
        set<vector<int>> uniqueSet;
        int leftModeX = 0;
        
        
        //find the most left most index of trees
        for(int i = 0; i < trees.size(); i++) {
            if(trees[i][0] < trees[leftModeX][0]) {
                leftModeX = i;
            }
        }
        //{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}}
        
        int curr = leftModeX;
        int cand = (leftModeX+1) % n;
        
        while(cand != leftModeX) {
            uniqueSet.insert(trees[curr]);
            cand = (curr+1) % n;
            for(int i = 0; i < n; i++) {
                if(cartiansProduct(trees[curr], trees[i], trees[cand]) > 0) {
                    cand = i;
                }
            }
            
            for(int i = 0; i < n; i++) {
                if(cartiansProduct(trees[curr], trees[cand], trees[i]) == 0) {
                    uniqueSet.insert(trees[i]);
                }
            }
            
            curr = cand;
        }
        
        vector<vector<int>> ans;
        
        for(auto k : uniqueSet)
            ans.push_back(k);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    outerTrees({{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}});
    return 0;
}
