//
//  main.cpp
//  Magician and Chocolates
//
//  Created by Giriraj Saigal on 17/05/21.
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

int nchoc(int A, vector<int> &B) {
    long long ans = 0;
    priority_queue<long long> q;
    
    for(int i : B) {
        q.push(i);
    }
    
    while(A--) {
        long long w = q.top();
        ans = (ans + q.top()) % 1000000007;
        q.pop();
        q.push(w/2);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
