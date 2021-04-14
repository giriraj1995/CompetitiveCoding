//
//  main.cpp
//  Sliding Window Maximum
//
//  Created by Giriraj Saigal on 14/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
using namespace std;

vector<int> slidingMaximum(const vector<int> A, int B) {
    int n = (int)A.size();
    int i = 0;
    vector<int> ans;
    deque<pair<int,int>> q;
    
    while(i < B) {
        while(q.size() > 0) {
            if(q.back().first <= A[i]){
                q.pop_back();
            }else{
                break;
            }
        }
        q.push_back({A[i],i});
        i++;
    }
    
    ans.push_back(q.front().first);
    
    while(i < n) {
        if(q.front().second <= i-B) {
            q.pop_front();
        }
        
        while(q.size() > 0) {
            if(q.back().first <= A[i]){
                q.pop_back();
            }else{
                break;
            }
        }
        
        q.push_back({A[i],i});
        
        ans.push_back(q.front().first);
        i++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    slidingMaximum({648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368}, 9);
    return 0;
}
