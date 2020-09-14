//
//  main.cpp
//  Max rectangle
//
//  Created by Giriraj Saigal on 13/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> lowestLeft(vector<int> x){
    vector<int> l;
    stack<int> s;
    for(int i = 0; i < (int)x.size(); i++){

        if(s.size() == 0){
            l.push_back(-1);
        }else if(x[i] > x[s.top()]){
            l.push_back(s.top());
        }else{
            while(s.size() != 0 && x[i] <= x[s.top()]){
                s.pop();
            }
            if(s.size() == 0)
                l.push_back(-1);
            else
                l.push_back(s.top());
        }
        s.push(i);
    }

    return l;
}

long max(long a, long b){
    return a>b?a:b;
}

vector<int> lowestRight(vector<int> x){
    vector<int> l;
    stack<int> s;
    for(int i = (int)x.size()-1; i >=0; i--){

        if(s.size() == 0){
            l.push_back(x.size());
        }else if(x[i] > x[s.top()]){
            l.push_back(s.top());
        }else{
            while(s.size() != 0 && x[i] <= x[s.top()]){
                s.pop();
            }
            if(s.size() == 0)
                l.push_back(x.size());
            else
                l.push_back(s.top());
        }
        s.push(i);
    }
    reverse(l.begin(), l.end());
    return l;
}

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    
    vector<int> left = lowestLeft(h);
    vector<int> right = lowestRight(h);
    
    long ans = 0;

    for(int i = 0; i < (int)h.size(); i++){
        ans = max(ans, (right[i]-left[i]-1)*h[i]);
    }

    return ans;

}

int main(int argc, const char * argv[]) {
    vector<int> x = {1, 2, 3, 4, 5};
    largestRectangle(x);
    return 0;
}
