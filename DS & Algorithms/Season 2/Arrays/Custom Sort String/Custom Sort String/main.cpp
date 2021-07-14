//
//  main.cpp
//  Custom Sort String
//
//  Created by Giriraj Saigal on 14/07/21.
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

map<char, int> mp;
bool cmp(char a, char b) {
    if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
        return mp[a] < mp[b];
    }else{
        return false;
    }
}

string customSortString(string order, string str) {
    mp.clear();
    
    int i = 0;
    for(char c : order) {
        mp[c] = i++;
    }
    
    sort(str.begin(), str.end(), cmp);
    return str;
}

int main(int argc, const char * argv[]) {
    customSortString("cba", "abcd");
    return 0;
}
