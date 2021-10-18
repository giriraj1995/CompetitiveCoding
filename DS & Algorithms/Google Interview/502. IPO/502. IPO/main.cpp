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

int solve(int n, int k, int w, vector<int>& profits, vector<int>& capital) {
        if(n == profits.size())
            return 0;
        if(k == 0)
            return 0;
        if(w < 0)
            return 0;
        
        
        if(capital[n] <= w) {
           //do work project
            int x = profits[n] + solve(n+1, k-1, w+capital[n], profits, capital);
            //donot work on project
            int y = solve(n+1, k, w, profits, capital);
            
            return max(x,y);
        }else{
            //donot work on project
            int x = solve(n+1, k, w, profits, capital);
            return x;
        }
    }
    
    int findMaximizedCapital(int k, int w, vector<int> profits, vector<int> capital) {
        return solve(0,k,w,profits,capital);
    }

int main(int argc, const char * argv[]) {
    findMaximizedCapital(2,0,{1,2,3},{0,1,2});
    return 0;
}
