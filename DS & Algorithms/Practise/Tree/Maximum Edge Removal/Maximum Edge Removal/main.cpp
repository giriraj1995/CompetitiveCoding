//
//  main.cpp
//  Maximum Edge Removal
//
//  Created by Giriraj Saigal on 27/12/20.
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

int dfsCount(vector<int> adj[],int i, unordered_map<int,int> &count,vector<int> &visited){
    
    visited[i]=1;
    count[i]=1;
    for(auto j=adj[i].begin();j!=adj[i].end();j++){
    if(!visited[*j]){
    count[i]+=dfsCount(adj,*j,count,visited);
    }
    }
    return count[i];
    
}

int solve(int A, vector<vector<int> > &B) {
    
    if(A%2!=0)
    return 0;
    vector<int> adj[A];
    for(int i=0;i<B.size();i++){
    adj[B[i][0]-1].push_back(B[i][1]-1);
    adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    unordered_map<int,int> count;
    vector<int> visited(A,0);
    dfsCount(adj,0,count,visited);
    int result=0;
    for(auto i=count.begin();i!=count.end();i++){
    if((i->second) %2==0)
    result++;
    }
    return result-1;
    
}

int main(int argc, const char * argv[]) {

    return 0;
}
