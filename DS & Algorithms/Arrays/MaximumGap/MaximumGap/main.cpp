//
//  main.cpp
//  MaximumGap
//
//  Created by Giriraj Saigal on 22/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxGap(vector<int> x){
    vector<pair<int, int>> y;
    
    int n = (int)x.size();
    for(int i = 0; i<n;i++)
    {
        y.push_back(make_pair(x[i], i));
    }
    sort(y.begin(), y.end());
    
    int p = 0;
    
    int min = INT_MAX;
    
    for(int i = 0; i<n;i++){
        if(y[i].second < min)
            min = y[i].second;
        else if(y[i].second-min >p)
            p =y[i].second-min;
    }
    
    return p;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {3,5,4,2};
    maxGap(x);
    return 0;
}
