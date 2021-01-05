//
//  main.cpp
//  Merge Intervals
//
//  Created by Giriraj Saigal on 05/01/21.
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
    
    int st,ed;
    
    if(newInterval.start < newInterval.end) {
        st = newInterval.start;
        ed = newInterval.end;
    }else{
        st = newInterval.end;
        ed = newInterval.start;
    }
    
    vector<pair<int, int>> v;
    
    for(auto i : intervals) {
        v.push_back({i.start, 0});
        v.push_back({i.end, 1});
    }
    
    v.push_back({st, 0});
    v.push_back({ed, 1});
    
    sort(v.begin(), v.end());
    vector<Interval> ans;
    Interval c;
    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second == 0) {
            count++;
        }else{
            count--;
        }
        
        
        if(count == 1 && v[i].second == 0) {
            c.start = v[i].first;
        }
        
        if(count == 0 && v[i].second == 1) {
            c.end = v[i].first;
            ans.push_back(c);
        }
    }
    
    return ans;
    
    
}


int main(int argc, const char * argv[]) {
    insert({Interval(1,3), Interval(6,9)}, Interval(2,5));
    return 0;
}
