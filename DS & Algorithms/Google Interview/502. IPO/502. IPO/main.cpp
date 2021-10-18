//
//  main.cpp
//  502. IPO
//
//  Created by Giriraj Saigal on 18/10/21.
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
#define pii pair<int,int>

int findMaximizedCapital(int k, int w, vector<int> profits, vector<int> capital) {
        priority_queue<pii> pro;
        priority_queue<pii, vector<pii>, greater<pii>> cap;
        int n = profits.size();
        for(int i = 0; i < n; i++) {
            cap.push({capital[i], profits[i]});
        }
        
        int curr = w;
        int ans = 0;
        
        while(cap.size() > 0) {
            int currcap = cap.top().first;
            int currpro = cap.top().second;

            if(currcap <= curr){
                cap.pop();
                pro.push({currpro, currcap});
            }else{
                if(pro.size() == 0 || k == 0)
                    break;
                else{
                    int prepro = pro.top().first;
                    pro.pop();
                    
                    ans += prepro;
                    k--;
                    curr += prepro;
                }
            }
        }
    
    while(k > 0 && pro.size() > 0) {
        int prepro = pro.top().first;
        pro.pop();
        
        ans += prepro;
        k--;
        curr += prepro;
    }
    
    return curr;
}

int main(int argc, const char * argv[]) {
    findMaximizedCapital(1,2,{1,2,3},{1,1,2});
    return 0;
}
