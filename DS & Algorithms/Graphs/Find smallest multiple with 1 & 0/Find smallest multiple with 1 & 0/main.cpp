//
//  main.cpp
//  Find smallest multiple with 1 & 0
//
//  Created by Giriraj Saigal on 03/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

bool keep_check(string t, int N) {
    
    int r = 0;
    for (int i = 0; i < t.length(); i++)
    {
        r = r * 10 + (t[i] - '0');
        r %= N;
    }
    return r;
}


string multiple(int A) {
    
    if(A == 1)
        return to_string(1);
    queue<string> q;
    
    q.push("1");
    string s;
    while(q.size() > 0) {
        s = q.front();
        q.pop();
        
        if(keep_check(s, A) != 0) {
            q.push(s+"0");
            q.push(s+"1");
        }
        else
            break;
    }
    
    return s;
}

string multiple2(int A) {
    
    if(A == 1)
        return "1";
    
    vector<int> p(A, -1);
    vector<int> s(A, -1);
    
    queue<int> q;
    
    q.push(1);
    
    while(q.size() > 0) {
        int k = q.front();
        q.pop();
        
        if(k == 0)
            break;
        
        int left = (k*10+0)%A;
        int right = (k*10+1)%A;
        
        if(p[left] == -1) {
            p[left] = k;
            s[left] = 0;
            q.push(left);
        }
        
        if(p[right] == -1) {
            p[right] = k;
            s[right] = 1;
            q.push(right);
        }
    }
    
    string ans;
    
    for(int i = 0;  i != 1; i = p[i]) {
        ans.push_back('0'+s[i]);
    }
    
    ans.push_back('1');
    
    return string(ans.rbegin(), ans.rend());
}

string multiple3(int N) {
    if(N==1) return "1";
    vector<int> p(N,-1);//parent state
    vector<int> s(N,-1);//step from parent to current
    //BFS
    int steps[2] = {0,1};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==0) break;
        for(int step: steps){
            int next = (curr*10+step)%N;
            if(p[next]==-1){
                p[next]=curr;
                s[next]=step;
                q.push(next);
            }
        }
    }
    //build reversed string
    string number;
    for(int it=0; it!=1; it=p[it])
        number.push_back('0'+s[it]);
    number.push_back('1');
    //return the reverse if it
    return string(number.rbegin(), number.rend());
}


int main(int argc, const char * argv[]) {
    cout<<multiple2(3);
    return 0;
}
