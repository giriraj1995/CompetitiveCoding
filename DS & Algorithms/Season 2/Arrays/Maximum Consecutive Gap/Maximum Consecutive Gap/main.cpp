//
//  main.cpp
//  Maximum Consecutive Gap
//
//  Created by Giriraj Saigal on 27/01/21.
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

int maximumGap(const vector<int> &A) {
    priority_queue<int> q;
    int ans = 0;
    
    for(int i : A) {
        q.push(i);
    }
    
    int check = q.top();
    q.pop();
    
    while(q.size() > 0) {
        ans = max(ans, check - q.top());
        check = q.top();
        q.pop();
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
