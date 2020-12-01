//
//  main.cpp
//  snakes and ladders
//
//  Created by Giriraj Saigal on 01/12/20.
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

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
        
    unordered_map<int, int> lad;
    unordered_map<int, int> sna;

    for(int i = 0; i < ladders.size(); i++) {
        lad[ladders[i][0]] = ladders[i][1];
    }
    
    vector<int> visited(101, 0);
    visited[0] = -1;
    
    for(int i = 0; i < snakes.size(); i++) {
        sna[snakes[i][0]] = snakes[i][1];
    }
    
    vector<int> level(101, 1000);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    level[1] = 0;
    
    while(q.size() > 0) {
        int x = q.front();
        q.pop();
        
        if(x == 100) {
            return level[100];
        }
        
        for(int i = 1; i <= 6; i++){
            if(visited[x+i] == 0 && (x + i) <= 100) {
                int flag = 0;
                
                if(lad.find(x+i) != lad.end()) {
                        
                        flag = 1;
                        q.push(lad[x+i]);
                        visited[lad[x+i]] = 1;
                    
                        if(level[lad[x+i]] > level[x] + 1){
                            level[lad[x+i]] = level[x] + 1;
                        }
                }
                
                if(sna.find(x+i) != sna.end()){
                        flag = 1;
                        q.push(sna[x+i]);
                        visited[sna[x+i]] = 1;
                        
                        if(level[sna[x+i]] > level[x] + 1){
                            level[sna[x+i]] = level[x] + 1;
                        }
                }
                
                if(flag == 1){
                    q.push(x+i);
                    visited[x+i] = 1;
                    if(level[x+i] > level[x] + 1)
                        level[x+i] = level[x]+1;
                }
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    quickestWayUp({
        {32 ,62},
        {42 ,68},
        {12 ,98}}, {{95,13},{97,25},{93,37},{79,27},{75,19},{49,47},{67,17}});
    return 0;
}
