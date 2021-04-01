//
//  main.cpp
//  Commutable Islands
//
//  Created by Giriraj Saigal on 26/03/21.
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

void dfs(vector<vector<int>> vis_arr, map<pair<int,int>, bool> &arr_un, int i, int j){
    vector<int> Xs = {0,1,0,-1,1,-1,1,-1};
    vector<int> Ys = {-1,0,1,0,1,-1,-1,1};
    vis_arr[i][j] = 1;
    arr_un[{i,j}] = true;

    for(int k = 0; k < 8; k++) {
        int x = Xs[k] + i;
        int y = Ys[k] + j;

        if(x >= 0 && y >= 0 && x < vis_arr.size() && y < vis_arr[0].size() && vis_arr[x][y] == 0) {
            dfs(vis_arr, arr_un, x,y);
        }
    }
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> arr = {
        {1,0,1,0,0,0,0,1},
        {0,0,1,1,0,1,1,1},
        {1,1,0,0,0,0,0,0},
        {1,0,0,0,1,0,1,1}};
    
    int n = (int)arr.size();
    int m = (int)arr[0].size();
    
    vector<vector<int>> vis_arr(n, vector<int>(m, 0));
    map<pair<int,int>, bool> arr_un;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0)
                vis_arr[i][j] = -1;
            else{
                arr_un[{i,j}] = false;
            }
        }
    }
    
    int noOfIs = 0;
    
    for(int i = 0; i < arr_un.size(); i++) {
        for(auto k : arr_un) {
            if(k.second == false) {
                noOfIs++;
                dfs(vis_arr, arr_un, k.first.first, k.first.second);
            }
        }
    }
    
    cout<<"No of islands = "<<noOfIs<<endl;
    
    
    
    return 0;
}
