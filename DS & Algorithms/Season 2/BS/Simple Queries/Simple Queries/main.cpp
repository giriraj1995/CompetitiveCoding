//
//  main.cpp
//  Simple Queries
//
//  Created by Giriraj Saigal on 15/02/21.
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

#define mod 1000000007

long long divisorProduct(int n) {
    long long product = 1;
    for(int i=1; i*i<=n; i++){
        if (n%i == 0){
            if (n/i == i) product = (product*i)%mod;
            else{
                product = (product*i)%mod;
                product = (product*(n/i))%mod;
            }
        }
    }
    return product;
}

bool compare(pair<int, long long> a, pair<int, long long> b){
    return a.first > b.first;
}

vector<int> solve(vector<int> A, vector<int> B) {
    int n=(int)A.size();
    vector<int> leftFreq(n, 1);
    vector<int> rightFreq(n, 1);
    for(int i=1; i<n; i++){
        int prev=i-1;
        while(prev>=0 && A[prev]<=A[i]){
            leftFreq[i] += leftFreq[prev];
            prev -= leftFreq[prev];
        }
    }
    for(int i=n-2; i>=0; i--){
        int next=i+1;
        while(next<n && A[next]<A[i]){
            rightFreq[i] += rightFreq[next];
            next += rightFreq[next];
        }
    }
    
    vector<pair<int, long long>> numFreq(n);
    for(int i=0; i<n; i++) numFreq[i] = {divisorProduct(A[i]), leftFreq[i]*rightFreq[i]};
    sort(numFreq.begin(), numFreq.end(), compare);
    vector<long long> cumFreq(n);
    cumFreq[0]=numFreq[0].second;
    for(int i=1; i<n; i++) cumFreq[i] = numFreq[i].second + cumFreq[i-1];
    
    vector<int> ans;
    for(int i=0; i<B.size(); i++){
        auto id=lower_bound(cumFreq.begin(), cumFreq.end(), B[i])-cumFreq.begin();
        ans.push_back(numFreq[id].first);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    solve({1, 2, 4}, {1, 2, 3, 4, 5, 6});
    return 0;
}
