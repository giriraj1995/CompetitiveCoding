//
//  main.cpp
//  Shidt string
//
//  Created by Giriraj Saigal on 11/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

void shiftone(string &s){
    
    reverse(s.begin(), s.end() - 1);
    reverse(s.begin(), s.end());
    
}

int maximumPower(string s) {
    
    int ans = 0;
    
    int n = s.size();
    
    int i = 0;
    
    while(i < n){
        
        int k = s.size()-1;
        int g = 0;
        while(s[k] == '0'){
            g++;
            k--;
        }
        
        ans  = max(ans, g);
        shiftone(s);
        i++;
    }
    
    return ans;
    
}

int maximumStones(vector<int> arr) {
    
    long long odd = 0;
    long long even = 0;
    
    for(int i = 0; i < arr.size(); i++){
        
        if(i & 1){
            odd += arr[i];
        }else{
            even += arr[i];
        }
        
    }
    
    return (int)min(odd, even);
}

int main(int argc, const char * argv[]) {
    maximumPower("0011");
    return 0;
}
