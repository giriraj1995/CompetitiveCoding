//
//  main.cpp
//  Truck Tour
//
//  Created by Giriraj Saigal on 11/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int gas;
    int next;
};

int truckTour(vector<vector<int>> x) {

    queue<Node> q;

    int n = (int)x.size();

    for(int i = 0; i < n; i++){
        Node k;
        k.gas = x[i][0];
        k.next = x[i][1];
        q.push(k);
    }

    int gas = 0;
    int start = 0;
    int passed = 0;
    
    while(passed < n){
        Node k = q.front();
        q.pop();

        gas += k.gas;

        if(gas >= k.next){
            gas -= k.next;
            passed++;
        } else {
            gas = 0;
            passed = 0;
            start = start + 1;
            q.push(k);
        }
    }

    return start;
}

int main(int argc, const char * argv[]) {
    vector<vector<int> > x;
    vector<int> x1 = {10,3};
    vector<int> x2 = {3,4};
    vector<int> x3 = {1,5};

    x.push_back(x1);
    x.push_back(x2);
    x.push_back(x3);
    
    truckTour(x);

    return 0;
}
