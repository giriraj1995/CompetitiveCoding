//
//  main.cpp
//  Shortest Unique Prefix
//
//  Created by Giriraj Saigal on 05/06/21.
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

struct Node{
    int count;
    Node* arr[26];
};

Node* createNode() {
    Node * x = new Node;
    x->count = 0;
    for(int i = 0; i < 26; i++)
        x->arr[i] = NULL;
    return x;
}
Node* createTree(Node* root, string s) {
    Node* p = root;
    
    for(char c : s) {
       p->count++;
       
       if(p->arr[c-'a'] == NULL)
            p->arr[c-'a'] = createNode();
            
       p = p->arr[c-'a'];
    }
    
    return root;
}

string find(Node* root, string s) {
    string ans = "";
    Node* p = root;
    for(char c : s) {
        if(p != NULL && p->count == 1){
            return ans;
        }else{
            ans += c;
            p = p->arr[c-'a'];
        }
    }
    
    return ans;
}

vector<string> prefix(vector<string> A) {
    Node* root = createNode();
    for(string s : A)
        root = createTree(root,s);
    
    vector<string> ans;
    
    for(string s : A)
        ans.push_back(find(root,s));
    
    return ans;
}


int main(int argc, const char * argv[]) {
    prefix({"zebra", "dog", "duck", "dove"});
    return 0;
}
