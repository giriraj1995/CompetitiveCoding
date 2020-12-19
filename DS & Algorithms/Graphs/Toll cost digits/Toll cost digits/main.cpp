//
//  main.cpp
//  Toll cost digits
//
//  Created by Giriraj Saigal on 18/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int main()
{
    int road_nodes;
    int road_edges;

    cin >> road_nodes >> road_edges;

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);
    
    vector<vector<int>> m(road_nodes+1, vector<int>(road_nodes+1, 0));
    for (int i = 0; i < road_edges; i++) {
        cin >> road_from[i] >> road_to[i] >> road_weight[i];
        m[road_from[i]][road_to[i]] = road_weight[i];
        m[road_to[i]][road_from[i]] = 1000 - road_weight[i];
    }

    map<int, int> mp;
    mp[0] = mp[1] = mp[2]= mp[3]= mp[4]= mp[5]= mp[6]= mp[7]= mp[8]= mp[9] = 0;
    int flag = 0;
    for(int k = 1; k <= road_edges; k++) {
        if(flag == 0){
            for(int i = 1; i <= road_edges; i++) {
                for(int j = 1; j <= road_edges; j++) {
                    flag = 1;
                    if(i == j)
                        continue;
                    else{
                        if(m[i][j] != 0)
                            mp[m[i][j] % 10]++;
                    }
                }
            }
        }

        for(int i = 1; i <= road_edges; i++) {
            for(int j = 1; j <= road_edges; j++) {
                if(i == j)
                    continue;
                else{
                    if(m[i][j] != m[i][k] + m[k][j]){
                        m[i][j] = m[i][k] + m[k][j];
                        mp[m[i][j] % 10]++;
                    }
                }
            }
        }
    }

    for(auto f : mp) {
        cout<<f.second<<endl;
    }
    return 0;
}

