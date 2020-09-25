//
//  main.cpp
//  IsSpecial Substring
//
//  Created by Giriraj Saigal on 25/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isSpecial(string s){

    int i = 0;
    int j = s.size()-1;

    while(i < j){

        if(s[i++] != s[j--])
            return false;

    }

    return true;

}

// Complete the substrCount function below.
long substrCount1(int n, string s) {

    long x = 0;
    x += n;
    
    for(int w = 2; w <= n; w++){

        int i = 0;
        string q;
        while(i < w){
            q += s[i];
            i++;
        }

        if(isSpecial(q)){
            x++;
        }

        while(i < n){
            q.erase(q.begin());
            q += s[i];

            if(isSpecial(q)){
            x++;
            }

            i++;
        }

    }

    return x;


}

map<string, int> u;

long substrCount2(int n, string s) {

    if(n == 0 || n == 1)
        return 0;

    long x = 0;

    if(isSpecial(s)){
        x++;
    }

    string s1 = s;
    string s2 = s;

    s1.erase(s1.begin());
    s2.erase(s2.end()-1);
    
    if(u.find(s1) == u.end()){
        x += substrCount2(n-1, s1);
    }else{
        x += u[s1];
    }
    
    if(u.find(s2) == u.end()){
        x += substrCount2(n-1, s2);
    }else{
        x += u[s2];
    }

    u[s] = x;
    return x;
}

long substrCount(int n, string s) {

    long x = n;

    for(int i = 0; i < n; i++){
        char now = s[i];
        int d = -1;
        for(int j = i + 1; j < n; j++){
            char c = s[j];
            if(now == c){
                if(d == -1 || (j - d) == (d - i))
                    x++;
            }else{
                if(d == -1)
                    d = j;
                else
                    break;
            }
        }

    }

    return x;

}


int main(int argc, const char * argv[]) {
    cout<<substrCount(5,"aabaa");
    
    return 0;
}
