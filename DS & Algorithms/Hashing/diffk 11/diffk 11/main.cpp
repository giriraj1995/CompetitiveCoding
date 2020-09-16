//
//  main.cpp
//  diffk 11
//
//  Created by Giriraj Saigal on 16/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int diffPossible(const vector<int> &A, int B) {
    
    map<int, int> u;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(u.find(A[i]) == u.end())
            u.insert(make_pair(A[i], 1));
    }
    
    for(int i = 0; i < A.size(); i++){
        if(u.find(B + A[i]) != u.end())
            return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1, 3, 2};
    diffPossible(x,0);

    return 0;
}
