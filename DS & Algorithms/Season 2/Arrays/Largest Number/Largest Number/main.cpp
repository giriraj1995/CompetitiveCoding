//
//  main.cpp
//  Largest Number
//
//  Created by Giriraj Saigal on 28/01/21.
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

bool cmp(string a, string b) {
    if(a+b > b+a) {
        return true;
    }else{
        return false;
    }
}

string largestNumber(const vector<int> &A) {
    vector<string> B;
    
    for(int i : A) {
        B.push_back(to_string(i));
    }
    
    sort(B.begin(), B.end(), cmp);
    
    string ans = "";
    
    for(string i : B) {
        ans += i;
    }
    
    while(ans.size() > 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    
    if(ans.compare("") == 0)
        return "0";
        
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
