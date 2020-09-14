//
//  main.cpp
//  No of ways to climb stairs
//
//  Created by Giriraj Saigal on 13/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> A, int n, int &ways){

    if(n == 0){
        ways += 1;
        return;
    }

    if(A.size() == 0)
        return;

    int x = A[0];

    if(x <= n){
        solve(A, n-x, ways);
    }

    A.erase(A.begin());
    solve(A, n, ways);

}

int stepPerms(int n) {

    if(n == 0)
        return 0;

    vector<int> x = {1,2,3};
    int ways = 0;
    solve(x, n, ways);
    return ways;
}

int main(int argc, const char * argv[]) {
    stepPerms(3);
    return 0;
}
