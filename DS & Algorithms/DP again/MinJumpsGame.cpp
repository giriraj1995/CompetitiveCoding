#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int jump(vector<int> &A) {
    
    int n = A.size();
    
    if(0 >= n-1)
        return 0;
        
    int jumps = 1;
    int reach = A[0];
    int nextReach = A[0];
    
    if(reach >= n-1)
        return jumps;
        
    for(int i = 0 ; i < A.size(); i++) {
        nextReach = max(nextReach, i + A[i]);
        
        if(i > reach)
            return -1;
        
        if(i == reach) {
            reach = nextReach;
            jumps++;
            
            if(reach >= n-1)
                return jumps;
        }
    }
    
    return jumps;
}

int main(int argc, const char * argv[]) {
    return 0;
}
