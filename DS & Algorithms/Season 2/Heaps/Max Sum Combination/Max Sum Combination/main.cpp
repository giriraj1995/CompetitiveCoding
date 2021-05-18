//
//  main.cpp
//  Max Sum Combination
//
//  Created by Giriraj Saigal on 18/05/21.
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

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    priority_queue<pair<int, pair<int,int>>> q;
    vector<int> ans;
    
    for(int i = 0; i < A.size(); i++) {
        q.push({A[0]+B[i], {0,i}});
    }
    
    while(ans.size() < A.size()) {
        ans.push_back(q.top().first);
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        
        q.push({A[x+1]+B[y], {x+1,y}});
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
