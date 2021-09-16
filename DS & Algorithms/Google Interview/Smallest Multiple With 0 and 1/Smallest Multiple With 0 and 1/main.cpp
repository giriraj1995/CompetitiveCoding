//
//  main.cpp
//  Smallest Multiple With 0 and 1
//
//  Created by Giriraj Saigal on 16/09/21.
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

string multiple(int N) {
    if(N == 1)
        return "1";
    
    vector<int> p(N, -1);
    vector<int> s(N, -1);
    queue<int> q;
    q.push(1);
    p[1] = 1;
    vector<int> steps = {0,1};
    while(q.size() > 0) {
        int x = q.front();
        q.pop();
        
        if(x == 0) {
            break;
        }
        
        for(int step : steps) {
            int next = (x*10+step)%N;
            if(p[next] == -1) {
                p[next] = x;
                s[next] = step;
                q.push(next);
            }
        }
    }
    
    int i = 0;
    string ans = "";
    
    while(i != 1 && p[i] != -1) {
        ans.push_back(s[i]+'0');
        i = p[i];
    }
    
    ans += "1";
    return string(ans.rbegin(), ans.rend());
    
}


int main(int argc, const char * argv[]) {
    multiple(7);
    return 0;
}
