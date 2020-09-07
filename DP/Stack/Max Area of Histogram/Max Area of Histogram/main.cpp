//
//  main.cpp
//  Max Area of Histogram
// Smallest on left + smallest on right
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
        
        if(s.size() == 0){
            v.push_back(i);
        }else if(s.size() > 0 && x[s.top()] < x[i])
            v.push_back(i - s.top() - 1);
        else if(s.size() > 0 && x[s.top()] >= x[i]){
            while(s.size() > 0 && x[s.top()] >= x[i]){
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(i);
            else
                v.push_back(i - s.top() - 1);
        }
        s.push(i);
    }
    
    return v;
}

vector<int> solve1(vector<int> x){
    stack<int> s;
    vector<int> v;
    int n = (int)x.size();
    
    for(int i = n-1; i >= 0 ; i--){
        
        if(s.size() == 0){
            v.push_back(n - i - 1);
        }else if(s.size() > 0 && x[s.top()] < x[i])
            v.push_back(s.top() - i - 1);
        else if(s.size() > 0 && x[s.top()] >= x[i]){
            while(s.size() > 0 && x[s.top()] >= x[i]){
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(n - i - 1);
            else
                v.push_back(s.top() - i - 1);
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {6,2,5,4,5,1,6};
    vector<int> left = solve(x);
    vector<int> right = solve1(x);
    
    int max1 = INT_MIN;
    
    for(int i = 0 ; i < left.size(); i++ ){
        max1 = max(max1, (left[i] + right[i] + 1)*x[i]);
    }
    
    cout<<max1<<endl;

    return 0;
}




