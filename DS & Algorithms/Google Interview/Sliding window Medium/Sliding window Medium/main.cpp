//
//  main.cpp
//  Sliding window Medium
//
//  Created by Giriraj Saigal on 27/09/21.
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

    void insert(pair<int,int> p, set<pair<int,int>, greater<pair<int,int>>> &maxset, set<pair<int,int>> &minset) {
            if(maxset.size() == 0) {
                maxset.insert(p);
            }else if(maxset.size() == minset.size()){
                if(p.first > minset.begin()->first) {
                    maxset.insert(*minset.begin());
                    minset.erase(minset.begin());
                    minset.insert(p);
                }else{
                    maxset.insert(p);
                }
            }else if(maxset.size() == 1+minset.size()){
                if(p.first < maxset.begin()->first){
                    minset.insert(*maxset.begin());
                    maxset.erase(maxset.begin());
                    maxset.insert(p);
                }else{
                    minset.insert(p);
                }
            }
        }
        
    void erase(pair<int,int> p, set<pair<int,int>, greater<pair<int,int>>> &maxset, set<pair<int,int>> &minset) {
        maxset.erase(p);
        minset.erase(p);
        if(maxset.size() < minset.size()) {
            while(maxset.size() < minset.size()) {
                maxset.insert(*minset.begin());
                minset.erase(minset.begin());
            }
        }else if(maxset.size() > 1+minset.size()){
            while(maxset.size() > 1+minset.size()) {
                minset.insert(*maxset.begin());
                maxset.erase(maxset.begin());
            }
        }
    }
        
    vector<double> medianSlidingWindow(vector<int> nums, int k) {
        bool isOdd = k&1 ? true : false;
        int i = 0;
        int n = nums.size();
        set<pair<int,int>> minset;
        set<pair<int,int>, greater<pair<int,int>>> maxset;
        
        while(i < k) {
            insert({nums[i],i},maxset,minset);
            i++;
        }
        
        vector<double> ans;
        if(isOdd) {
            ans.push_back(maxset.begin()->first);
        }else{
            ans.push_back((maxset.begin()->first + minset.begin()->first)/2.0);
        }
        
        while(i < n) {
            insert({nums[i],i},maxset,minset);
            erase({nums[i-k],i-k},maxset,minset);
            if(isOdd) {
                ans.push_back(maxset.begin()->first);
            }else{
                ans.push_back((maxset.begin()->first + minset.begin()->first)/2.0);
            }
            i++;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<double> x = medianSlidingWindow({1,3,-1,-3,5,3,6,7},3);
    return 0;
}
