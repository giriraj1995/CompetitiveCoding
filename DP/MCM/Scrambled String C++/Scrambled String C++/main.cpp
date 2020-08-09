//
//  main.cpp
//  Scrambled String C++
//
//  Created by Giriraj Saigal on 09/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "string"
#include <map>
#include <iterator>

using namespace std;

map<pair<string,string>, bool> store;
bool ss(string a, string b)
{
    pair<string, string> pt = make_pair(a,b);
    if(store.find(pt) != store.end())
        return store[pt];
    if(a.compare(b) == 0)
    {
        return true;
    }
    
    if(a.size() <= 1)
    {
        return false;
    }
    
    int n = (int)a.length();
    bool flag = false;
    
    for (int i = 1; i < n; i++) {
        bool first = ss(a.substr(0,i), b.substr(n-i,i));
        bool second = ss(a.substr(i,n-i), b.substr(0,n-i));
        bool cond1 = first && second;
        
        first = ss(a.substr(0,i), b.substr(0,i));
        second = ss(a.substr(i,n-i), b.substr(i,n-i));
        bool cond2 = first && second;;
        
        if(cond1 || cond2)
            return true;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    string str = "saksmhi";
    string tr = "isakxsh";
    
    if(str.length() != tr.length())
        cout<<"Lenght Mismatch"<<endl;
    else if(str.length() == 0 && tr.length() == 0)
        cout<<"Srambled"<<endl;
    else
        cout<<str<<" & "<<tr<<" are srambled string : "<<ss(str, tr)<<endl;

    return 0;
}
