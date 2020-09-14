//
//  main.cpp
//  Search in a sorted matrix
//
//  Created by Giriraj Saigal on 16/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int main(int argc, const char * argv[]) {
    int key = 29;
    vector<vector<int>> x;
    
    vector<int> x0 = {10,20,30,40};
    x.push_back(x0);
    
    vector<int> x1 = {15,25,35,45};
    x.push_back(x1);
    
    vector<int> x2 = {27,29,37,48};
    x.push_back(x2);
    
    vector<int> x3 = {32,33,39,50};
    x.push_back(x3);
    
    int i = 0;
    int j = 3;
    int y;
    
    while(i < 4 && j < 4 && i >= 0 && j >= 0)
    {
        y = x[i][j];
        
        if(key == y)
        {
            break;
        }
        
        if(y > key)
            j--;
        else
        {
            i++;
        }
    }
    
    return 0;
}
