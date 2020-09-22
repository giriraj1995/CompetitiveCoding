//
//  main.cpp
//  Min cost of connecting ropes
//
//  Created by Giriraj Saigal on 21/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void minCost(vector<int> x){
    
    int cost=0;
    
    if(x.size() < 2)
        return;
    
    if(x.size() == 2)
    {
        cout<<x[0]+x[1]<<endl;
        return;
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < x.size(); i++)
    {
        minHeap.push(x[i]);
    }
    
//    cost += minHeap.top();
//    minHeap.pop();
//    cost += minHeap.top();
//    minHeap.pop();
    
    while(minHeap.size() != 1){
        int x = minHeap.top();
        minHeap.pop();
        int y = minHeap.top();
        minHeap.pop();
        cost += x+y;
        minHeap.push(x+y);
    }
    
    cout<<cost<<endl;
    
    return;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1,2,3,4,5};
    minCost(x);
    return 0;
}
