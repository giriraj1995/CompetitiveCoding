//
//  main.cpp
//  Castle of grid
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

bool safe(vector<string> grid, int startX, int startY, int goalX, int goalY, vector<pair<int, int>> &points){

    int x = startX;
    int y = startY;
    while(y >= 0){

        if(grid[x][y] == 'X')
            break;

        if(x == goalX && y == goalY)
            return true;

        y--;
    }

    points.push_back({x,y+1});

    x = startX;
    y = startY;

    while(y < grid.size()){

        if(grid[x][y] == 'X')
            break;

        if(x == goalX && y == goalY)
            return true;

        y++;
    }
    
    points.push_back({x,y-1});

    x = startX;
    y = startY;

    while(x < grid.size()){

        if(grid[x][y] == 'X')
            break;

        if(x == goalX && y == goalY)
            return true;

        x++;
    }
    points.push_back({x-1,y});

    x = startX;
    y = startY;
    while(x >= 0){

        if(grid[x][y] == 'X')
            break;

        if(x == goalX && y == goalY)
            return true;

        x--;
    }
    points.push_back({x+1,y});
    return false;
}

bool minMoves(vector<string> &grid, int startX, int startY, int goalX, int goalY, int &moves){

    vector<pair<int, int>> points;

    if(safe(grid, startX, startY, goalX, goalY, points)){
        moves += 1;
        return true;
    }else{
        int ans = INT_MAX;
        int cx;
        int cy;

        moves += 1;
        int f = moves;
        for(int t = 0; t < points.size(); t++){
            cx = points[t].first;
            cy = points[t].second;
            if(!(cx == startX && cy == startY)){
                grid[startX][startY] = 'X';
                moves = f;
                if(minMoves(grid, cx, cy, goalX, goalY, moves)){
                    ans = min(ans, moves);
                }
                grid[startX][startY] = '.';
            }
        }

        if(ans == INT_MAX){
            moves -= 1;
            return false;
        }
        else{
            moves = ans;
            return true;
        }
    }

}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {

    int moves = 0;
    if(minMoves(grid, startX, startY, goalX, goalY, moves)){
        return moves;
    }else{
        return INT_MAX;
    }

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
