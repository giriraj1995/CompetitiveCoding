//
//  main.cpp
//  Ath palindromic no
//
//  Created by Giriraj Saigal on 19/01/21.
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

long getValue(string s){
    long num  = 0;
    for(long i=0;i<s.size();i++){
        num = num*2 + (s[i]-'0');
    }
    return num;
}
long solve(int A) {
    if(A==1) return A;
    A--;
    queue<string> q;
    q.push("11");
    while(!q.empty()){
        string s = q.front();
        q.pop();
        A--;
        if(!A){
            return getValue(s);
        }
        int mid = s.size()/2;
        if(s.size()%2==0){
            string s0 = s, s1=s;
            s0.insert(mid,"0");
            s1.insert(mid,"1");
            q.push(s0);
            q.push(s1);
        } else{
            string ch(1,s[mid]);
            string temp = s;
            temp.insert(mid,ch);
            q.push(temp);
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    cout<<solve(29)<<endl;
    return 0;
}
