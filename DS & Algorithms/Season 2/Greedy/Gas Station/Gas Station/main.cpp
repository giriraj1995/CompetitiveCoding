//
//  main.cpp
//  Gas Station
//
//  Created by Giriraj Saigal on 26/08/21.
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

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int i = 0;
    int count = 0;
    int n = A.size();
    int gas = 0;
    int st = 0;
    set<int> s;
    
    while(count != n) {
        gas += A[i];
        if(gas >= B[i]) {
            gas -= B[i];
            i = (i+1)%n;
            count++;
        }else{
            if(s.find(i) != s.end())
                break;
            s.insert(i);
            st = (i+1)%n;
            i = (i+1)%n;
            gas = 0;
            count = 0;
        }
    }
    
    if(count == n){
        return st;
    }
    
    return -1;
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1, 2, 3, 4, 5};
    vector<int> y = {3, 4, 5, 1, 2};
    canCompleteCircuit(x,y);
    return 0;
}
