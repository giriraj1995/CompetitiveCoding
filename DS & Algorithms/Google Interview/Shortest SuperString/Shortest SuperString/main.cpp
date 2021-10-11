//
//  main.cpp
//  Shortest SuperString
//
//  Created by Giriraj Saigal on 11/10/21.
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

string find(string x, string y) {
    int n = (int)x.size();
    int m = (int)y.size();
    
    for(int i = n; i >= 1; i--) {
        string xd = x.substr(n-i,i);
        if(xd.size() > m)
            continue;
        string yd = y.substr(0,i);
        if(xd == yd)
            return x.substr(0,n-i) + y;
    }
    
    return x+y;
}

int main(int argc, const char * argv[]) {
    cout << find("atgcatc","catg") << endl;
    return 0;
}
