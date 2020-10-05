//
//  main.cpp
//  GeeksForGeeks
//
//  Created by Giriraj Saigal on 04/10/20.
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

int numberOfWays(int n, vector<vector<char>> &mat)
{
    map<pair<int,int>, bool> mp;
    int count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '#'){
                mp[{i,j}] = false;
                count++;
            }
        }
    }
    
    vector<pair<int,int>> d;
    map<vector<pair<int,int>>, bool> z;
    map<int, bool> row;
    map<int, bool> col;
    int ways = 0;
    
    for(auto g : mp){
        
        d.clear();
        for(auto f : mp){
            mp[f.first] = false;
        }
        
        int hashs = 0;
        pair<int, int> p = g.first;
        
        row.clear();
        col.clear();
        d.push_back(p);
        mp[p] = true;
        row[p.first] = true;
        col[p.second] = true;
        hashs++;
        
        
        for(auto k : mp){
            
            if(k.second == false){
                
                pair<int, int> l = k.first;
                if(row.find(l.first) == row.end() && col.find(l.second) == col.end()){
                    mp[k.first] = true;
                    row[l.first] = true;
                    col[l.second] = true;
                    d.push_back(l);
                    hashs++;
                }
                if(hashs == n){
                    ways++;
                    sort(d.begin(), d.end());
                    z[d] = true;
                    break;
                }
            }
        }
    }
    return (int)(z.size()%1000000007);
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> mat = {{'#', '#'},
        {'#', '#'}};
    cout<<numberOfWays(2, mat)<<endl;
    return 0;
}
