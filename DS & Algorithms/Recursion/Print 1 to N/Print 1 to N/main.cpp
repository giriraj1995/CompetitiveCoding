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

void solve(int n){
    if(n == 0)
        return;
    solve(n-1);
    cout<<n<<endl;

}

int main(int argc, const char * argv[]) {
    solve(50);
    return 0;
}
