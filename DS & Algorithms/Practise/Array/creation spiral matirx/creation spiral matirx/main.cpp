//
//  main.cpp
//  creation spiral matirx
//
//  Created by Giriraj Saigal on 28/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

vector<vector<int> > generateMatrix(int A) {
    
    vector<vector<int>> k(A, vector<int>(A, -1));
    
    int t = 1;
    int i = 0,j = 0;
    k[0][0] = t;
    t++;
    
    while(i < A && j < A) {
        
        bool flag = true;
        
        while(j + 1 < A && k[i][j+1] == -1) {
            if(flag)
                flag = !flag;
            j = j + 1;
            k[i][j] = t;
            t++;
        }
        
        while(i + 1 < A && k[i+1][j] == -1) {
            if(flag)
                flag = !flag;
            i = i + 1;
            k[i][j] = t;
            t++;
        }
        
        while(j - 1 >= 0 && k[i][j-1] == -1) {
            if(flag)
                flag = !flag;
            j = j - 1;
            k[i][j] = t;
            t++;
        }
        
        while(i - 1 >= 0 && k[i-1][j] == -1){
            if(flag)
                flag = !flag;
            i = i - 1;
            k[i][j] = t;
            t++;
        }
        
        
        if(flag) {
            break;
        }
    }
    
    return k;
}

int main(int argc, const char * argv[]) {
    generateMatrix(100);
    return 0;
}
