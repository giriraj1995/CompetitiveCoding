//
//  main.cpp
//  Split Array with equal Avg
//
//  Created by Giriraj Saigal on 07/09/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
#include <set>
#include <unordered_set>
using namespace std;

bool is_possible(int sum, int m, int n) {
    for(int i = 1; i<=m; i++) {
        if(((sum*i) % n) == 0)
            return true;
    }
    
    return false;
}
bool splitArraySameAverage(vector<int> nums) {
    int n = (int)nums.size();
    
    if(n <= 1)
        return false;
    
    int m = n/2;
    int sum = accumulate(nums.begin(), nums.end(),0);
    
    if(!is_possible(sum, m, n)) {
        return false;
    }
    
    vector<unordered_set<int>> vec(m+1);
    
    vec[0].insert(0);
    
    for(int ele : nums) {
        for(int i = m; i>=1; i--) {
            for(int t : vec[i-1]){
                vec[i].insert(ele+t);
            }
        }
    }
    
    for(int i = 1; i <= m; i++) {
        if((sum * i) % n == 0 && vec[i].find(sum*i/n) != vec[i].end())
            return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    splitArraySameAverage({2,12,18,16,19,3});
    return 0;
}
