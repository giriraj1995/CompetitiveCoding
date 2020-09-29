//
//  main.cpp
//  String to int
//
//  Created by Giriraj Saigal on 28/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> ans;
    int x = 0;
    
    for(char c : str){
        if(c == ','){
            ans.push_back(x);
            x = 0;
            continue;
        }
        x = (x * 10) + int(c - '0');
    }

    ans.push_back(x);

    return ans;
}

int main(int argc, const char * argv[]) {
    parseInts("3456,34,22,5467,34,667,2,3");
    return 0;
}
