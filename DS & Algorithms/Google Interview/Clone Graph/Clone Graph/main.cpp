//
//  main.cpp
//  Clone Graph
//
//  Created by Giriraj Saigal on 17/09/21.
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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



Node* cloneGraph(Node* node) {
    if(node == NULL)
        return NULL;
    
    queue<Node*> q;
    map<Node*, Node*> mp;
    Node* cloned = new Node(node->val);
    mp[node] = cloned;
    q.push(node);
    set<Node*> visited_set;
    visited_set.insert(node);

    while(q.size() > 0) {
        Node* act = q.front();
        q.pop();
        
        Node* clo = mp[act];
        
        
        //updated the neigbors of the cloned
        for(Node* temp : act->neighbors) {
            
            Node* clotemp = mp[temp];
            
            if(clotemp == NULL){
                clotemp = new Node(temp->val);
                mp[temp] = clotemp;
            }
            
            clo->neighbors.push_back(clotemp);
            
            if(visited_set.find(temp) == visited_set.end()) {
                visited_set.insert(temp);
                q.push(temp);
            }
        }
    }
    
    return cloned;
}


int main(int argc, const char * argv[]) {
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* thr = new Node(3);
    Node* fou = new Node(4);
    
    one->neighbors.push_back(two);
    one->neighbors.push_back(fou);
    
    two->neighbors.push_back(one);
    two->neighbors.push_back(thr);
    
    thr->neighbors.push_back(two);
    thr->neighbors.push_back(fou);
    
    fou->neighbors.push_back(one);
    fou->neighbors.push_back(thr);
    
    Node * x = cloneGraph(one);
    return 0;
}
