//
//  main.cpp
//  Swap Nodes
//
//  Created by Giriraj Saigal on 18/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createTree(vector<vector<int>> indexes){
    int n = indexes.size();

    if(n == 0)
        return NULL;

    Node* root = new Node();
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    queue<Node*> q;
    q.push(root);

    for(int i = 0; i < n; i++){
        Node* temp = q.front();
        q.pop();

        if(indexes[i][0] != -1){
            Node* node = new Node();
            node->data = indexes[i][0];
            node->left = NULL;
            node->right = NULL;

            temp->left = node;
            q.push(temp->left);
        }


        if(indexes[i][1] != -1){
            Node* node = new Node();
            node->data = indexes[i][1];
            node->left = NULL;
            node->right = NULL;

            temp->right = node;
            q.push(temp->right);
        }
    }

    return root;

}

int func(Node *p, Node *root, int h){
    if(p == root)
        return h;
    else if(root == NULL)
        return 0;
    else{
        return func(p, root->left, h+1) + func(p, root->right, h+1);
    }
}

Node* swap(Node *p, Node* root, int k){

    if(p == NULL)
        return NULL;

    if(func(p, root, 1) % k == 0){
        Node* temp = p->left;
        p->left = p->right;
        p->right = temp;
        p->left = swap(p->left, root, k);
        p->right = swap(p->right, root, k);
        return p;
    }else{
        p->left = swap(p->left, root, k);
        p->right = swap(p->right, root, k);
        return p;
    }
}

void inOrder(vector<int> &a, Node *p){
    if(p){
        inOrder(a, p->left);
        a.push_back(p->data);
        inOrder(a, p->right);
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> ans;
    Node * root = createTree(indexes);
    for(int i = 0; i < queries.size(); i++){
        vector<int> a;
        root = swap(root, root,queries[i]);
        inOrder(a, root);
        ans.push_back(a);
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> indexes = {{2, 3},
        {-1, 4},
        {-1, 5},
        {-1, -1},
        {-1, -1}};
    vector<int> x = {2};
    swapNodes(indexes, x);
    return 0;
}
