//
//  main.cpp
//  Clone Graph
//
//  Created by Giriraj Saigal on 22/12/20.
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

//  Definition for undirected graph.
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
 };
 
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited, notvisited;
    
    queue<UndirectedGraphNode *> q;
    q.push(node);
    visited[node] = new UndirectedGraphNode(node->label);
    
    while(q.size() > 0) {
        UndirectedGraphNode* curr = q.front();
        q.pop();
        
        UndirectedGraphNode* newCurr = visited[curr];
        
        for(auto v : curr->neighbors) {
            if(visited.find(v) == visited.end()) {
                q.push(v);
                UndirectedGraphNode* copy = new UndirectedGraphNode(v->label);
                newCurr->neighbors.push_back(copy);
                visited[v] = copy;
            }else{
                UndirectedGraphNode* copy = visited[v];
                newCurr->neighbors.push_back(copy);
            }
        }
    }
    
    return visited[node];
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
