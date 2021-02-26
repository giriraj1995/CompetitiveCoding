//
//  main.cpp
//  Compare Version Numbers
//
//  Created by Giriraj Saigal on 26/02/21.
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

string eleminate(string x) {
    while(x.size() > 0 && x[0] == '0') {
        x.erase(x.begin());
    }
    return x.compare("") == 0 ? "0" : x;
}

int compareVersion(string A, string B) {
    if(A.compare(B) == 0)
        return 0;
        
    vector<string> a;
    string x = "";
    
    for(char c : A) {
        if(c != '.') {
            x += c;
        }else if(c == '.' && x.compare("") != 0){
            a.push_back(eleminate(x));
            x = "";
        }else{
            a.push_back("0");
        }
    }
    
    if(x.compare("") != 0)
        a.push_back(eleminate(x));
    
    vector<string> b;
    x = "";
    
    for(char c : B) {
        if(c != '.') {
            x += c;
        }else if(c == '.' && x.compare("") != 0){
            b.push_back(eleminate(x));
            x = "";
        }else{
            b.push_back("0");
        }
    }
    
    if(x.compare("") != 0)
        b.push_back(eleminate(x));
        
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    
    while(i < n && j < m) {
        if(a[i].size() > b[i].size())
            return 1;
        else if(b[i].size() > a[i].size())
            return -1;
        else if(a[i].compare(b[i]) > 0) {
            return 1;
        }else if(a[i].compare(b[i]) < 0){
            return -1;
        }
        
        i++;
        j++;
    }
    
    if(i < n) {
        while(i < n) {
            if(a[i].compare("0") > 0)
                return 1;
            i++;
        }
        return 0;
    }else if(j < m){
        while(j < m) {
            if(b[j].compare("0") > 0)
                return -1;
            j++;
        }
        return 0;
    }else{
        return 0;
    }
}



int main(int argc, const char * argv[]) {
    compareVersion("4444371174137455", "5.168");
    return 0;
}
