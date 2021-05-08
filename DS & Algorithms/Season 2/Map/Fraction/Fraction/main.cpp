//
//  main.cpp
//  Fraction
//
//  Created by Giriraj Saigal on 08/05/21.
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

string fractionToDecimal(int a, int b) {
    
    long long A=abs((long long)a);
    long long B=abs((long long)b);
    bool sign = true;
    
    if((a < 0 && b > 0) || (a > 0 && b < 0))
        sign = false;
    
    if(A == 0)
        return "0";
    
    if(A%B == 0){
        return sign ? to_string(A/B) : "-" + to_string(A/B);
    }
        
    string ans = "";
    long long q = A/B;
    
    ans += to_string(q) + ".";
    
    long long r = A%B;
    
    string afp = "";
    
    set<long long> s;
    while(r<B) {
        
        bool first = false;
        while(r < B) {
            if(first)
                afp += "0";
            r *= 10;
            
            first = true;
        }
        if(s.find(r) != s.end())
        {
            afp = "(" + afp + ")";
            break;
        }
        s.insert(r);
        if(r >= B) {
            q = r/B;
            r = r%B;
            afp += to_string(q);
            if(r == 0)
                break;
        }
    }
    
    return sign ? ans + afp : "-" + ans + afp;
    
    
}



int main(int argc, const char * argv[]) {
    cout<<fractionToDecimal(-1,-2147483648);
    return 0;
}
