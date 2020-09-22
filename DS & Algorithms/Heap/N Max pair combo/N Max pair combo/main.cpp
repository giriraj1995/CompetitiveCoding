//
//  main.cpp
//  N Max pair combo
//
//  Created by Giriraj Saigal on 21/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> com(vector<int> x, vector<int> y, int k){
    
    vector<int > ans;
    
    for(int i = 0; i < x.size(); i++)
    {
        for(int j = 0; j < y.size(); j++){
            ans.push_back(x[i] + y[j]);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    while(ans.size() != k){
        ans.erase(ans.begin());
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}

bool c(int a, int b){
    if(a > b)
        return 1;
    else
        return 0;
}

vector<int> solve(vector<int> A, vector<int> B) {
    
    
    sort(A.begin(), A.end(), c);
    sort(B.begin(), B.end(), c);
    
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            long long sum = A[i] + B[j];
            if(i == 0)
                minHeap.push(sum);
            else if(minHeap.top() < sum){
                minHeap.pop();
                minHeap.push(sum);
            }
            else break;
        }
        
    }
    
    vector<int> ans(minHeap.size(), 0);
    
    int i = minHeap.size() - 1;
    
    while(i >= 0){
        ans[i] = minHeap.top();
        minHeap.pop();
        i--;
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    solve({9, 7, -6, 49, -39, -23, 0},{-14, 10, -32, -45, 13, -1, -6});
    return 0;
}
