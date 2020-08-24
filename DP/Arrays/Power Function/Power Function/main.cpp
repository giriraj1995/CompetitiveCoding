//
//  main.cpp
//  Power Function
//
//  Created by Giriraj Saigal on 23/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
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
}


int main(int argc, const char * argv[]) {
    cout<<pow(71045970,41535484,64735492);
    return 0;
}
