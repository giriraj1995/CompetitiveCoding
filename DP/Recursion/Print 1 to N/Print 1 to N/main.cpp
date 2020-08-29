//
//  main.cpp
//  Print 1 to N
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int l){
    if(n == l+1)
        return;
    
    cout<<n<<endl;
    solve(n+1, l);
}

int main(int argc, const char * argv[]) {
    solve(1,50);
    return 0;
}
