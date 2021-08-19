//
//  main.cpp
//  Buy  and sell 2
//
//  Created by Giriraj Saigal on 19/08/21.
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

int maxProfit(const vector<int> &A) {
    int x = 0;
    if(A.size()<=1)
        return 0;
    
    for(int i = 1;i<A.size(); i++){
        x += max(0, A[i] - A[i-1]);
    }
    
    return x;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
