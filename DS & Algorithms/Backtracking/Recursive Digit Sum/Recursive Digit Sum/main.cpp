//
//  main.cpp
//  Recursive Digit Sum
//
//  Created by Giriraj Saigal on 13/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int solve(string n){

    if(n.size() == 0)
        return 0;
    
    char c = n[0];
    n.erase(n.begin());
    int x = solve(n);
    int sum = (int)(c-'0') + x;
    return sum;
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
    string n1 = "";
    for(int i = 1; i <= k; i++){
        n1 += n;
    }
    int x;
    
    while((x = solve(n1)) > 9){
        n1 = to_string(x);
    };

    return x;
}

int main(int argc, const char * argv[]) {
    cout<<superDigit("148", 3);
    return 0;
}
