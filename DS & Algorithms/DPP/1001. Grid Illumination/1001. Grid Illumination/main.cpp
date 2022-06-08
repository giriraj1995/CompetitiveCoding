//
//  main.cpp
//  1001. Grid Illumination
//
//  Created by Giriraj Saigal on 07/06/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<int> gridIllumination(int n, vector<vector<int>> lamps, vector<vector<int>> queries) {
    
    unordered_map<int,int> row;
    unordered_map<int,int> col;
    unordered_map<int,int> diaTopRight;
    int centorDiagonal = 0;
    unordered_map<int,int> diasTopLeft1;
    unordered_map<int,int> diasTopLeft2;
    map<pair<int,int>,bool> lamp;
    
    for(auto k : lamps) {
        int x = k[0];
        int y = k[1];
        
        row[x]++;
        col[y]++;
        diaTopRight[x+y]++;
        if(x == y) {
            centorDiagonal++;
        }else if(y > x) {
            diasTopLeft1[y-x]++;
        }else{
            diasTopLeft2[x-y]++;
        }
        lamp[{x,y}] = true;
    }
        
    vector<int> ans(queries.size(), 0);
    vector<int> Xs = {0,0,0,1,-1,-1,-1,1,1};
    vector<int> Ys = {0,1,-1,0,0,-1,1,-1,1};
    
    int g = 0;
    for(auto k : queries) {
        int x = k[0];
        int y = k[1];
        
        if(row[x] > 0 ||
           col[y] > 0 ||
           diaTopRight[x+y] > 0 ||
           (x == y && centorDiagonal > 0) ||
           (y > x && diasTopLeft1[y-x] > 0) ||
           (x > y && diasTopLeft2[x-y] > 0)) {
            ans[g] = 1;
        }
        
        for(int f = 0; f < 9; f++) {
            int nx = x + Xs[f];
            int ny = y + Ys[f];
            if(nx >= 0 &&
               ny >= 0 &&
               nx < n &&
               ny < n &&
               lamp.count({nx,ny}) > 0) {
                lamp.erase({nx,ny});
                row[nx]--;
                col[ny]--;
                diaTopRight[nx+ny]--;
                if(nx == ny){
                    centorDiagonal--;
                }else if(ny > nx){
                    diasTopLeft1[ny-nx]--;
                }else{
                    diasTopLeft2[nx-ny]--;
                }
            }
        }

        
        g++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    gridIllumination(5,
                     {{0,0},{0,1},{0,4}},
                     {{0,0},{0,1},{0,2}});
    return 0;
}
