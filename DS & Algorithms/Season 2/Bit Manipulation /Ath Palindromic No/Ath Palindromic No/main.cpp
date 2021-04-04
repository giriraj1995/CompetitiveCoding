//
//  main.cpp
//  Ath Palindromic No
//
//  Created by Giriraj Saigal on 04/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

int solve(int A) {
    queue<string> q;
    
    if(A == 1)
        return 1;
    
    int x = A;
    string no;
    q.push("1");
    while(x--) {
        no = q.front();
        q.pop();
        
        if(x == 0){
            break;
        }
        
        if(no.size() % 2 == 0) {
            q.push(no.substr(0, no.size()/2) + "0" + no.substr(no.size()/2));
            q.push(no.substr(0, no.size()/2) + "1" + no.substr(no.size()/2));
        }else{
            if(no[no.size()/2] == '1') {
                q.push(no.substr(0, no.size()/2+1) + "1" + no.substr(no.size()/2+1));
            }else{
                q.push(no.substr(0, no.size()/2+1) + "0" + no.substr(no.size()/2+1));
            }
        }
    }
    
    long long ans = 0;
    
    for(int i = no.size()-1; i >= 0; i--) {
        if(no[i] == '1') {
            ans += (1 << (no.size()-i-1));
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve(9);
    return 0;
}
