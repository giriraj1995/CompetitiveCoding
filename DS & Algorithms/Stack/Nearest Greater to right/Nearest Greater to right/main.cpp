//
//  main.cpp
//  Nearest Greater to right
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
    
    for(int i = n -1; i >= 0 ; i--){
        if(s.size() == 0)
            v.push_back(-1);
        else if(s.size() > 0 && s.top() > x[i])
            v.push_back(s.top());
        else if(s.size() > 0 && s.top() <= x[i]){
            while(s.size() > 0 && s.top() <= x[i]){
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        
        s.push(x[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1,3,2,4,4,5,7,3,6,7,3,5,7,8,9,1};
    x = solve(x);
    return 0;
}
