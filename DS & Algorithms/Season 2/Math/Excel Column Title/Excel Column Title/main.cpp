//
//  main.cpp
//  Excel Column Title
//
//  Created by Giriraj Saigal on 03/02/21.
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

string convertToTitle(int A) {
    string ans = "";
    
    while(A > 0) {
        int ele = (A%26 - 1 + 26)%26;
        if(A%26 == 0)
            A -= 26;
        ans += (ele + 'A');
        A = A/26;
    }
    
    return string(ans.rbegin(), ans.rend());
}


int main(int argc, const char * argv[]) {
    convertToTitle(52);
    return 0;
}
