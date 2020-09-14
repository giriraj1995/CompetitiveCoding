//
//  main.cpp
//  Nearest smallest to left
//
//  Created by Giriraj Saigal on 07/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solve(vector<int> x){
    stack<int> s;
    vector<int> v;
    int n = (int)x.size();
    
    for(int i = 0; i < n ; i++){
        if(s.size() == 0)
            v.push_back(-1);
        else if(s.size() > 0 && x[s.top()] < x[i])
            v.push_back(s.top());
        else if(s.size() > 0 && x[s.top()] >= x[i])
        {
            while(s.size() > 0 && x[s.top()] >= x[i]){
                s.pop();
            }
            
            if(s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        
        s.push(i);
    }
    
    return v;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {4,5,8,4,9,6,3,5,3,2,1,5};
    x = solve(x);
    return 0;
}


