//
//  main.cpp
//  FractionToDecimal
//
//  Created by Giriraj Saigal on 19/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isRepeat(string &x){
    
    int n = (int)x.size();
    
    reverse(x.begin(), x.end());
    
    while(x.size() > 0 && x[0] == '0'){
        x.erase(x.begin());
    }
    
    if(x.size() == 0)
        return false;
    
    if(x.size() != n)
    {
        reverse(x.begin(), x.end());
        return true;
    }
    
    
    reverse(x.begin(), x.end());
    
    unordered_map<char, int> u;
    
    for(int i = 0; i < x.size(); i++){
        
        if(u.find(x[i]) == u.end())
            u[x[i]] = i;
        else{
            int j = u[x[i]];
            x = "(" + x.substr(j, i-j) + ")";
            return true;
        }
    }
    
    
    x = "(" + x + ")";
    return true;
}
typedef long long ll;

string fractionToDecimal(int A, int B) {
    
    if(A==0) return "0";
    if(B==0) return "invalid";
    long long a=(long long)A;
    long long b=(long long)B;
    int sign=(a<0)^(b<0)?-1:1;
    a=abs(a);
    b=abs(b);
    long long initial=a/b;
    string res;
    if(sign==-1)
    {
    res+="-";
    }
    res+=to_string(initial);
    if(a%b==0)
    {
        return res;
    }
    res+=".";
    long long rem=a%b;
    unordered_map<ll,ll> m;
    long long index;
    bool repeat =false;
    while(rem>0&&repeat==false)
    {
        if(m.find(rem)!=m.end())
        {
            index=m[rem];
            repeat=true;
            break;
        }
        else
        {
            m[rem]=res.size();
        }
        rem=rem*10;
        long long temp=rem/b;
        res+=to_string(temp);
        rem=rem%b;
    }
        if(repeat==true)
        {
            res+=")";
            res.insert(index,"(");
        }
        return res;
    
}

int main(int argc, const char * argv[]) {
    cout<<fractionToDecimal(-2,-3)<<endl;
    return 0;
}
