//
//  main.cpp
//  get Row pascal
//
//  Created by Giriraj Saigal on 21/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int A) {
    vector<vector<int>> x;
    for(int i = 0; i <= A; i++){
        vector<int> y;
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0)
                y.push_back(1);
            else{
                y.push_back(x[i-1][j-1] + x[i-1][j]);
            }
        }
        x.push_back(y);
    }
    return x[A];
}


int main(int argc, const char * argv[]) {
    int A = 2;
    getRow(A);
    return 0;
}
