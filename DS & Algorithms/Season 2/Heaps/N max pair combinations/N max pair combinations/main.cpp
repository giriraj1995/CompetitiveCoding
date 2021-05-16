//
//  main.cpp
//  N max pair combinations
//
//  Created by Giriraj Saigal on 16/05/21.
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

void solve1(int i, int j, int n,
            vector<int> a, vector<int> b,
            priority_queue<long long> &sum) {
    if(sum.size() == n)
        return;
        
    if(i == 0 && j == 0) {
        sum.push(a[i] + b[j]);
        return;
    }
    
    if(i == 0) {
        sum.push(a[i] + b[j]);
        solve1(i, j-1, n, a,b,sum);
        return;
    }
    
    if(j == 0) {
        sum.push(a[i] + b[j]);
        solve1(i-1, j, n, a,b,sum);
        return;
    }
    
    sum.push(a[i] + b[j]);
    
    if(sum.size() == n)
        return;
    
    int ref = a[i] + b[j-1];
    
    int k = i-1;
    
    while(k >= 0 && ref <= a[k] + b[j]) {
        sum.push(a[k] + b[j]);
        
        if(sum.size() == n)
            break;
        
        k--;
    }
    
    if(sum.size() == n)
        return;
    
    solve1(i, j-1, n, a,b,sum);
    
    return;
}

vector<int> solve(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = (int)A.size();
    int i = n-1;
    int j = n-1;
    
    priority_queue<long long> q;
    
    if(A[i] > B[i]) {
        solve1(j,i,n,B,A,q);
    }else
        solve1(i,j,n,A,B,q);
    
    vector<int> ans;
    
    while((int)q.size() > 0) {
        ans.push_back((int)q.top());
        q.pop();
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({18, 26, -18}, {-23, -20, 17});
    return 0;
}
