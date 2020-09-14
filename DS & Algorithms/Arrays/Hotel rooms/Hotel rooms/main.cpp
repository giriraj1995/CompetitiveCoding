//
//  main.cpp
//  Hotel rooms
//
//  Created by Giriraj Saigal on 20/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if(K == 0)
        return false;
    
    if(arrive.size() == 0 || depart.size() == 0)
        return 1;
    
    // int min = INT_MAX;
    int max = INT_MIN;
    
    // for(int i:arrive){
    //     if(i < min)
    //         min = i;
    // }
    
    for(int i:depart){
        if(i > max)
            max = i;
    }
    
    vector<int> x;
    x.assign(max+1, 0);
    int n = (int)arrive.size();
    int m = (int)depart.size();
    int c = 0;
    
    if(n != m)
        return false;
        
    for(int i = 0; i<n; i++)
    {
        int s = arrive[i];
        int e = depart[i];
        
        for(int j = s; j< e; j++){
            x[j]++;
        }
    }
    
    int max2 = INT_MIN;
    
    for(int i = 0; i <= max; i++)
        if(x[i] > max2)
            max2 = x[i];
            
    if(max2 > K)
        return false;
        
    return true;
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = { 1, 2, 3 };
    vector<int> y = { 2, 3, 4 };
    int k = 1;
    hotel(x,y,1);
    return 0;
}
