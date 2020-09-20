//
//  main.cpp
//  Max points in same line
//
//  Created by Giriraj Saigal on 20/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

int max(int a, int b){
    return a > b ? a:b;
}

int maxPoints(vector<int> x, vector<int> y) {

    int n = (int)x.size();
    if(n<=2) return n;
    int max_points = 2;
    
    unordered_map<double,int> map;
    
    for(int i=0;i<n;i++){
        int same_points = 0;
        int inf_slope = 0; // verticle points
        int curr_max = 0;
        for(int j=i+1;j<n;j++){
            if(x[i]==x[j] && y[i]==y[j]) same_points++; // avoinding 0/0 case
            else if(x[i]==x[j]){        // avoiding division by 0
                inf_slope++;
                curr_max = max(curr_max,inf_slope);
            }else{
                double slope = (y[j]-y[i])/((x[j]-x[i])*1.0);
                map[slope]++;
                curr_max = max(curr_max,map[slope]);
            }
        }
        max_points = max(max_points,curr_max + same_points + 1);
        map.clear();
    }
    return max_points;
}

int main(int argc, const char * argv[]) {
    cout<<maxPoints({0,1,-1}, {0,1,-1})<<endl;

    return 0;
}
