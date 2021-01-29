//
//  main.cpp
//  Hotel Booking Possible
//
//  Created by Giriraj Saigal on 29/01/21.
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

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>> v;
    
    for(int i : arrive) {
        v.push_back({i,1});
    }
    
    for(int i : depart) {
        v.push_back({i,0});
    }
    
    sort(v.begin(), v.end());
    
    int count = 0;
    
    for(int i = 0; i < v.size(); i++) {
        pair<int, int> p = v[i];
        if(p.second == 1)
        {
            count++;
        }
        else
        {
            count--;
        }
        
        if(count > K)
            return false;
    }
    
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
