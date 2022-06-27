//
//  main.cpp
//  Min Jumps
//
//  Created by Giriraj Saigal on 11/06/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int solve(int A, vector<int> B) {
    int eaten = 0;
    int energy = 0;
    int next_max = 0;
    int new_max = 0;
    for(int i = 0; i < B.size(); i++) {
        if(next_max == i) {
            eaten++;
            next_max = max(i+B[i],new_max);
            if(i == next_max)
                return -1;
        }else{
            new_max = max(i+(next_max-i)+B[i],new_max);
        }
    }
    return eaten;
}


int main(int argc, const char * argv[]) {
    solve(10,{6,0,2,4,5,0,1,2,0,5});
    return 0;
}
