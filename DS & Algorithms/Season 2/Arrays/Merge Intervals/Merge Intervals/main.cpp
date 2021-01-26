//
//  main.cpp
//  Merge Intervals
//
//  Created by Giriraj Saigal on 26/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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


//  Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
vector<Interval> insert(vector<Interval> intervals, Interval newInterval) {
    vector<pair<int,int>> v;
    
    for(auto k : intervals) {
        v.push_back({k.start,0});
        v.push_back({k.end,1});
    }
    
    v.push_back({newInterval.start,0});
    v.push_back({newInterval.end,1});
    
    sort(v.begin(), v.end());
    
    int count = 0;
    vector<Interval> ans;
    Interval interval;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second == 0) {
            count++;
        }else{
            count--;
        }
        
        if(v[i].second == 0 && count == 1) {
            interval.start = v[i].first;
        }
        
        if(v[i].second == 1 && count == 0) {
            interval.end = v[i].first;
            ans.push_back(interval);
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    insert({Interval(1, 3), Interval(6, 9)}, Interval(2, 5));
    return 0;
}
