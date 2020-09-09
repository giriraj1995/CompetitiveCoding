//
//  main.cpp
//  Min Stack
//
//  Created by Giriraj Saigal on 09/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int minElement;

class MinStack{
    
    public :
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

MinStack::MinStack() {
    minElement = -1;
}

void MinStack::push(int x) {
    if(s.size() == 0){
        s.push(x);
        minElement = x;
        return;
    }else{
        if(x >= s.top()){
            s.push(x);
        }else{
            s.push(2 * x - minElement);
            minElement = x;
        }
    }
}

void MinStack::pop() {
    if(s.size() == 0){
        return;
    }else{
        if(s.top() >= minElement){
            s.pop();
        }else{
            int x = s.top();
            s.pop();
            minElement = 2 * minElement - x;
        }
    }
}

int MinStack::top() {
    if(s.size() == 0)
        return -1;
    else{
        if(s.top() >= minElement){
            return s.top();
        }else{
            return minElement;
        }
    }
}

int MinStack::getMin() {
    if(s.size() == 0)
        return -1;
    else
        return minElement;
}



int main(int argc, const char * argv[]) {
    MinStack m;
    m.push(19);
    m.push(10);
    m.push(9);
    cout<<m.getMin()<<endl;
    
    
    return 0;
}
