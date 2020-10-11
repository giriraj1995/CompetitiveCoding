//
//  main.cpp
//  Smallest waiting time
//
//  Created by Giriraj Saigal on 10/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int minimumAverage(vector<vector<int>> customers) {

    if(customers.size() == 0){
        return 0;
    }
    
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;
    map<int, vector<int>> u;

    for(int i = 0; i < customers.size(); i++){
        u[customers[i][0]].push_back(customers[i][1]);
    }

    long long int ans = 0;
    long long int curTime = 0;

    for(auto i : u){

        if(curTime > i.first){

            vector<int> x = i.second;

            for(int k : x){
                heap.push({k,i.first});
            }

        }else{

            vector<int> x = i.second;

            for(int k : x){
                heap.push({k,i.first});
            }

            pair<int,int> p = heap.top();
            heap.pop();

            curTime += p.first;
            ans+= curTime - p.second;
        }
    }
    
    while(heap.size() > 0){
        
        pair<int,int> p = heap.top();
        heap.pop();

        curTime += p.first;
        ans+= curTime - p.second;
        
    }

    return ans/customers.size();
}

int main(int argc, const char * argv[]) {
    minimumAverage({{0 ,3},{1, 9},{2 ,6}});
    return 0;
}
