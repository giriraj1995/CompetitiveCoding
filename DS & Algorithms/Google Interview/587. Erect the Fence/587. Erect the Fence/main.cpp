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

//int cartiansProduct(vector<int> a, vector<int> b, vector<int> c) {
//        return (c[1] - a[1]) * (b[0] - a[0]) - (b[1] - a[1]) * (c[0] - a[0]);
//    }
    
//vector<vector<int>> outerTrees(vector<vector<int>> trees) {
//        int n = trees.size();
//
//        if(n <= 3)
//            return trees;
//
//        set<vector<int>> uniqueSet;
//        map<vector<int>, int> mp;
//        int leftModeX = 0;
//
//
//        //find the most left most index of trees
//        for(int i = 0; i < trees.size(); i++) {
//            mp.insert({trees[i],i});
//            if(trees[i][0] < trees[leftModeX][0]) {
//                leftModeX = i;
//            }
//        }
//        //{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}}
//
//        int curr = leftModeX;
//        int cand = (leftModeX+1) % n;
//        uniqueSet.insert(trees[leftModeX]);
//
//        while(cand != leftModeX) {
//            cand = (curr+1) % n;
//
//            for(auto k : mp) {
//                if(cartiansProduct(trees[curr], trees[k.second], trees[cand]) > 0) {
//                    cand = k.second;
//                }
//            }
//
//            for(auto k : mp) {
//                if(cartiansProduct(trees[curr], trees[cand], trees[k.second]) == 0) {
//                    uniqueSet.insert(trees[k.second]);
//                }
//            }
//
//            mp.erase(trees[cand]);
//            uniqueSet.insert(trees[cand]);
//            curr = cand;
//        }
//
//        vector<vector<int>> ans;
//
//        for(auto k : uniqueSet)
//            ans.push_back(k);
//
//        return ans;
//    }

int slope(vector<int> l2, vector<int> l1, vector<int> l) {
        int x2 = l2[0];
        int y2 = l2[1];
        
        int x1 = l1[0];
        int y1 = l1[1];
        
        int x = l[0];
        int y = l[1];
        
        int t =  (y - y1)*(x1 - x2) - (y1 - y2)*(x - x1) ;
    return t;
    }
    
vector<vector<int>> outerTrees(vector<vector<int>> trees) {
        int n = trees.size();
        if(n <= 3)
            return trees;
        
        sort(trees.begin(), trees.end());
        
        vector<vector<int>> lower;
        vector<vector<int>> higher;
        
        for(int i = 0; i < trees.size(); i++) {
            
        while(lower.size() >= 2 && slope(lower[lower.size()-2], lower[lower.size()-1], trees[i]) < 0){
                lower.pop_back();
            }
                
        while(higher.size() >= 2 && slope(higher[higher.size()-2], higher[higher.size()-1], trees[i]) > 0){
                higher.pop_back();
            }
                
            lower.push_back(trees[i]);
            higher.push_back(trees[i]);
        }
        
        set<vector<int>> ans;
        
        for(auto k : lower) {
            ans.insert(k);
        }
        
        for(auto k : higher) {
            ans.insert(k);
        }
        
        vector<vector<int>> vec;
        
        for(auto k : ans){
            vec.push_back(k);
        }
        
        return vec;
    }

int main(int argc, const char * argv[]) {
    outerTrees({{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}});
    return 0;
}
