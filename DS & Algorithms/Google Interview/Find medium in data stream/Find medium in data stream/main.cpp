//
//  main.cpp
//  Find medium in data stream
//
//  Created by Giriraj Saigal on 23/09/21.
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


int n;
priority_queue<int> first;
priority_queue<int, vector<int>, greater<int>> second;

void addNum(int num) {
    n++;
    if(first.size() == 0) {
        first.push(num);
        return;
    }else if(first.size() == second.size()) {
        if(num > second.top()) {
            first.push(second.top());
            second.pop();
            second.push(num);
        }else{
            first.push(num);
        }
    }else if(first.size() == 1+second.size()){
        if(num <= first.top()) {
            second.push(first.top());
            first.pop();
            first.push(num);
        }else{
            second.push(num);
        }
    }
    
}

double findMedian() {
    if(n&1){
        return first.top()/1.0;
    }else{
        return (first.top()+second.top())/2.0;
    }
}

int main(int argc, const char * argv[]) {
    n = 0;
    while(first.size() > 0)
        first.pop();
    while(second.size() > 0)
        second.pop();
    
    addNum(1);
    addNum(2);
    cout << findMedian() << endl;
    addNum(3);
    cout << findMedian() << endl;
    return 0;
}
