//
//  main.cpp
//  Castle on grid 2
//
//  Created by Giriraj Saigal on 29/09/20.
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

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {

    queue<pair<int, int>> q;
    q.push({startX, startY});
    int n = (int)grid.size();

    vector<int> ci(n,-1);
    vector<vector<int>> c(n,ci);

    vector<pair<int,int>> pi(n);
    vector<vector<pair<int,int>>> p(n, pi);

    c[startX][startY] = 0;

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        c[x][y] = 1;
        int xi = x;
        while(xi < n){
            if(grid[xi][y] != 'X' && c[xi][y] == -1){
                p[xi][y] = {x,y};
                c[xi][y] = 0;
                q.push({xi,y});

                if(xi == goalX && y == goalY)
                    break;
            }else if(grid[xi][y] == 'X'){
                break;
            }
            xi++;
        }

        if(xi == goalX && y == goalY)
            break;

        xi = x;

        while(xi >= 0){
            if(grid[xi][y] != 'X' && c[xi][y] == -1){
                p[xi][y] = {x,y};
                c[xi][y] = 0;
                q.push({xi,y});

            if(xi == goalX && y == goalY)
                break;
            }else if(grid[xi][y] == 'X'){
                break;
            }
            xi--;
        }

        if(xi == goalX && y == goalY)
            break;

        int yi = y;

        while(yi >= 0){
            if(grid[x][yi] != 'X' && c[x][yi] == -1){
                p[x][yi] = {x,y};
                c[x][yi] = 0;
                q.push({x,yi});
                if(x == goalX && yi == goalY)
                break;
            }else if(grid[x][yi] == 'X'){
                break;
            }
            yi--;
        }

        if(x == goalX && yi == goalY)
            break;

        yi = y;

        while(yi < n){
            if(grid[x][yi] != 'X' && c[x][yi] == -1){
                p[x][yi] = {x,y};
                c[x][yi] = 0;
                q.push({x,yi});

                if(x == goalX && yi == goalY)
                    break;
            }else if(grid[x][yi] == 'X'){
                break;
            }
            yi++;
        }

        if(x == goalX && yi == goalY)
            break;
    }

    stack<pair<int,int>> s;
    s.push({goalX, goalY});
    int xi = goalX;
    int yi = goalY;

    int o = 0;
    
    while(xi != startX || yi != startY){
        s.push(p[xi][yi]);
        pair<int,int> g = s.top();
        xi = g.first;
        yi = g.second;
        o++;
    }

    return o;
}

int main(int argc, const char * argv[]) {
    vector<string> grid;
    string x = ".X.";
    grid.push_back(x);
    grid.push_back(x);
    grid.push_back("...");
    
    minimumMoves(grid, 0,0,1,2);
    return 0;
}
