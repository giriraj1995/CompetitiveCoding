//
//  main.cpp
//  CompareVersions
//
//  Created by Giriraj Saigal on 26/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string elimateZero(string x){
    string z;
    
    for(int i = 0; i < x.size(); i++){
        if(x[i] == '0')
            continue;
        else{
            z = x.substr(i,x.size());
            break;
        }
    }
    
    return z;
}

int compareVersion(string A, string B) {
    
    if(A.size() == 0 || B.size() == 0)
        return 0;
    
    vector<string> x;
    vector<string> y;
    
    int n = (int)A.size();
    int m = (int)B.size();
    string p;

    for(int i = 0; i < n; i++){
        if(A[i] != '.')
            p.push_back(A[i]);
        else{
            p = elimateZero(p);
            x.push_back(p);
            p.clear();
        }
    }
    
    x.push_back(elimateZero(p));
    p.clear();
    
    for(int i = 0; i < m; i++){
        if(B[i] != '.')
            p.push_back(B[i]);
        else{
            p = elimateZero(p);
            y.push_back(p);
            p.clear();
        }
    }
    
    y.push_back(elimateZero(p));
    p.clear();
    
    n = (int)x.size();
    m = (int)y.size();
    
    int i = 0;
    int j = 0;
    
    while(i < n && j < m){
                
        string a = x[i];
        string b = y[j];
        
        i++;
        j++;
        
        if(a == b){
            continue;
        }
        
        if(a > b)
            return 1;
        
        if(b > a)
            return -1;
    }
    
    if(n > m){
        for(int f = m ; f < n ; f++){
            if(x[f] != "")
                return 1;
        }
        
        return 0;
    }
    else if(m > n){
        for(int f = n ; f < m ; f++){
            if(y[f] != "")
                return -1;
        }
        
        return 0;
    }
    else
        return 0;
}




int main(int argc, const char * argv[]) {
    cout<<compareVersion("9","65.43.8.591.51.5");
    return 0;
}
