//
//  main.cpp
//  Get Running Median
//
//  Created by Giriraj Saigal on 03/10/20.
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

void add(int ele, priority_queue<int, vector<int>> &lowers, priority_queue<int, vector<int>, greater<int>> &highers){

    if(lowers.size() == 0 || ele < lowers.top()){
        lowers.push(ele);
    }else{
        highers.push(ele);
    }

}

void balance(priority_queue<int, vector<int>> &lowers, priority_queue<int, vector<int>, greater<int>> &highers){
    int x = lowers.size();
    int y = highers.size();
    if(x - y >= 2){

        highers.push(lowers.top());
        lowers.pop();

    }else if(y - x >= 2){

        lowers.push(highers.top());
        highers.pop();

    }
}

double getMedian(priority_queue<int, vector<int>> lowers, priority_queue<int, vector<int>, greater<int>> highers){
    if(lowers.size() == highers.size()){
        return (lowers.top() + highers.top())/2.0;
    }else{
        if(lowers.size() > highers.size())
            return lowers.top() * 1.0;
        else{
            return highers.top() * 1.0;
        }
    }
}

vector<double> runningMedian(vector<int> a) {
    
    vector<double> ans(a.size());
    priority_queue<int, vector<int>> lowers;
    priority_queue<int, vector<int>, greater<int>> highers;

    for(int i = 0; i < a.size(); i++){
        add(a[i], lowers, highers);
        balance(lowers, highers);
        ans[i] = getMedian(lowers, highers) / 1.0;
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    runningMedian({12,
        4,
        5,
        3,
        8,
        7});
    return 0;
}
