//
//  main.cpp
//  Alien Dictonary
//
//  Created by Giriraj Saigal on 15/01/21.
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
#include<unordered_set>
using namespace std;

void topo(int u, vector<bool> &vis, string &ans, unordered_set<int> adj[]) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) topo(v, vis, ans, adj);
    }
    
    ans.insert(ans.begin(),'a' + (char)u);
}
string findOrder(string dict[], int N, int K) {
    unordered_set<int> adj[K];
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < min(dict[i].size(), dict[i+1].size()); j++) {
            if(dict[i][j] != dict[i+1][j]) {
                adj[dict[i][j]-'a'].insert(dict[i+1][j]-'a');
                break;
            }
        }
    }
    string ans;
    vector<bool> vis(K, false);
    
    for(int i = 0; i < K; i++) {
        if(!vis[i]) {
            topo(i, vis, ans, adj);
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    string dict[] = {"bhhb", "blkbggfecalifjfcbkjdicehhgikkdhlachlgbhji", "cfjjhcifladadbgcleggjgbcieihabcglblflgajgkejccj", "dlgdhiha", "ehggedljjhfldcajeceaeehkalkfeidhigkifjl", "gdalgkblahcldahledfghjb", "geldbblaaflegjhlfjlgblfbdc", "ibjceciedbiilkjliijgklcgliaeeic" "jcebjkfgfibfckfiikklecihik", "jdkcabjjjckgdblkljf", "jijlbjbliigkffhkchkclkhafbiiiblcglhfjkflbjjkih", "kfd" "lhdgidialgabfklffahiihceflebfidl"};
    cout<<findOrder(dict, 13,12)<<endl;
    return 0;
}
