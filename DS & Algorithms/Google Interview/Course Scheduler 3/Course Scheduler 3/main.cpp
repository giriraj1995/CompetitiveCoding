//
//  main.cpp
//  Course Scheduler 3
//
//  Created by Giriraj Saigal on 14/10/21.
//

#define pii pair<int,int>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int scheduleCourse(vector<vector<int>> courses) {
        priority_queue<pii, vector<pii>, greater<pii>> c;
        priority_queue<pii> d;
        
        for(int i = 0; i < courses.size(); i++) {
            c.push({courses[i][1],courses[i][0]});
        }
        
        int st = 0;
        while(c.size() > 0) {
            pii x = c.top();
            c.pop();
            
            int lastDayCurr = x.first; //lastday
            int durationCurr = x.second; //duration
            
            if(st + durationCurr <= lastDayCurr) {
                st += durationCurr;
                d.push({durationCurr,lastDayCurr});
            }else if(d.size() != 0) {
                pii y = d.top();
                int lastDayPrev = y.second;
                int durationPrev = y.first;
                if(durationCurr < durationPrev) {
                    st -= durationPrev;
                    st += durationCurr;
                    d.pop();
                    d.push({durationCurr,lastDayCurr});
                    lastDayCurr = lastDayPrev;
                    durationCurr = durationPrev;
                }
            }
        }
        
        return d.size();
    }

int main(int argc, const char * argv[]) {
    cout << scheduleCourse({{20,20},{50,70},{100,170},{30,190},{20,300}});
    return 0;
}
