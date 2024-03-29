//
//  main.cpp
//  Arrange 2
//
//  Created by Giriraj Saigal on 30/07/21.
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

int singleNumber(vector<int> nums) {
    vector<int> x(32, 0);
    
    for(int ele : nums) {
        for(int i = 0; i < 32; i++) {
            if(1<<i & ele){
                x[i]++;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        if(x[i] % 3 == 1) {
            ans += pow(2,i);
        }
    }
    
    return ans;
}

int solve(string A, int i, int B) {
    if(A.size() == i && B != 0)
        return -1;
    
    if((A.size()-i) == B)
        return 0;
        
    if((A.size()-i) < B)
        return -1;
        
    if(B == 1) {
            
        int blacks = 0;
        int whites = 0;
        
        for(int k = i; k < A.size(); k++) {
            if(A[k] == 'W')
                whites++;
            else
                blacks++;
        }
        
        return blacks*whites;
    }
    
    int blacks = 0;
    int whites = 0;
    
    int ans = INT_MAX;
    for(int k = i; k < A.size()-1; k++) {
        if(A[k] == 'W')
            whites++;
        else
            blacks++;
        
        int temp = blacks*whites;
        int s = solve(A, k+1, B-1);
        
        if(s != -1)
            ans = min(temp + s, ans);
    }
    
    if(ans != INT_MAX)
        return ans;
    
    return -1;
}

int arrange(string A, int B) {
    return solve(A,0,B);
}


int main(int argc, const char * argv[]) {
    //arrange("WWWB", 2);
    cout << singleNumber({-2,-2,1,1,4,1,4,4,-4,-2}) << endl;
    return 0;
}
