//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by Giriraj Saigal on 25/04/21.
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

bool palin(string s) {
    int i = 0, len = s.length();
    while(i<len/2 and (s[i] == s[len-1-i])) i++;
    return (i == len/2);
}
void split(string A, vector<vector<string> > &res, vector<string> &vec) {
    if (A.size() == 0)  {
        res.push_back(vec);
        return;
    }
    for (int len=1; len <= A.size(); len++) {
        if (palin(A.substr(0, len))) {
            vec.push_back(A.substr(0, len));
            split(A.substr(len), res, vec);
            vec.pop_back();
        }
    }
}
vector<vector<string> > partition(string A) {
    vector<vector<string> > res;
    vector<string> vec;
    split(A, res, vec);
    return res;
}

int main(int argc, const char * argv[]) {
    partition("giriraj");
    return 0;
}
