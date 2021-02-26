//
//  main.cpp
//  Count & Say
//
//  Created by Giriraj Saigal on 22/02/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

string next_string(string x) {
    string y = "";
    char prev = x[0];
    int count = 1;
    for(int i = 1; i < x.size(); i++) {
        if(x[i] == prev){
            count++;
        }else{
            y += to_string(count);
            y += prev;
            
            count = 1;
            prev = x[i];
        }
    }
    
    
    y += to_string(count);
    y += prev;
    
    return y;
}


int main(int argc, const char * argv[]) {
    string x = "1";
    cout<<x<<endl;
    int y = 10;
    while(y--){
        x = next_string(x);
        cout<<x<<endl;
    }
    return 0;
}
