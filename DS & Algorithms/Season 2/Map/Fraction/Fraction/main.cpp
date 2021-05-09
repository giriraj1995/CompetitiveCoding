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
    bool repeat = false;
    long long index;
    map<long long, long long> mp;
    while(r>0 && repeat == false) {
        if(mp.find(r) != mp.end())
        {
            index = mp[r];
            repeat = true;
            break;
        }else{
            mp[r] = ans.size();
        }
        
        r=r*10;
        long long t = r/B;
        ans+=to_string(t);
        r = r%B;
    }
    
    if(repeat){
        ans += ")";
        ans.insert(index, "(");
    }
    
    return sign ? ans : "-" + ans;
    
    
}



int main(int argc, const char * argv[]) {
    return 0;
}
