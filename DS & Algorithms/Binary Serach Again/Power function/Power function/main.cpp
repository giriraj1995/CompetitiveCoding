//
//  main.cpp
//  Power function
//
//  Created by Giriraj Saigal on 28/11/20.
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

int pow(int x, int n, int d) {
    
    long long int p = n, cal = x, ans = 1;
    
    while(p>0){
        
        if(p & 1)
            ans = (ans * cal) % d;
        
        p = p/2;
        cal = cal*cal % d;
    }
    
    return (ans+d)%d;
   
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(int argc, const char * argv[]) {
    cout<<pow(2,8,INT_MAX)<<endl;
    return 0;
}
