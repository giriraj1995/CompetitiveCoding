//
//  main.cpp
//  k Closest Points to origin
//
//  Created by Giriraj Saigal on 21/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<double,pair<int,int>> ppi;


void findKClosestPoints(vector<int> x, vector<int> y, int k){
    
    priority_queue<ppi> maxheap;
    int n = x.size();
    
    for(int i = 0; i < n; i++){
        maxheap.push({sqrt(pow(x[i], 2) + pow(y[i], 2)), {x[i],y[i]}});
        if(maxheap.size() > k)
            maxheap.pop();
    }
    
    while (maxheap.size() > 0) {
        cout<<maxheap.top().second.first<<" "<<maxheap.top().second.second<<endl;
        maxheap.pop();
    }
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1,-2,5,0};
    vector<int> y = {3,2,8,1};
    
    findKClosestPoints(x,y,2);
    return 0;
}
