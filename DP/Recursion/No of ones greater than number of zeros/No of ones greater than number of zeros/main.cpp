//
//  main.cpp
//  No of ones greater than number of zeros
//
//  Created by Giriraj Saigal on 01/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> x;
void solve(int o, int z, string out, int n){
    
    if(out.size() == n){
        x.push_back(out);
        return;
    }
    if(o != n){
        solve(o+1,z,out+"1",n);
    }
    
    if(o > z+1){
        solve(o,z+1,out+"0",n);
    }
}

int main(int argc, const char * argv[]) {
    int n = 10;
    solve(0,0,"",n);
    
    for(string t : x){
        cout<<t<<endl;
    }
    return 0;
}
