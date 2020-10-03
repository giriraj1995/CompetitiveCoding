//
//  main.cpp
//  Shortest Unique prefix 2
//
//  Created by Giriraj Saigal on 03/10/20.
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

struct Trie{
    bool end;
    Trie* child[26];
    Trie(){
        end = false;
        memset(child, NULL, sizeof(child));
    }
};

Trie* root;

void insert(string x){
    Trie* node = root;
    for(char c : x){
        if(node->child[c - 'a'] == NULL){
            node->child[c - 'a'] = new Trie();
        }
        node = node->child[c - 'a'];
    }
}

int preFind(string x, Trie* node, int index){
    
    if(index >= x.size()){
        return -1;
    }
    
    int t = preFind(x, node->child[x[index+1] - 'a'], index + 1);
    
    if(t == -1)
        return index;
    
    int count = 0;
    
    for(int i = 0; i < 26 ; i++){
        if(node->child[i])
            count++;
    }
    
    if(count > 1 || node->end || index+1 != t){
        return t;
    }else{
        return index;
    }
    
}

int pre(string x){
    
    Trie* node = root->child[x[0] - 'a'];
    return preFind(x, node, 0);
    
}


vector<string> prefix(vector<string> &A) {
    root = new Trie();
    vector<string> ans;
    
    for(string x : A){
        insert(x);
    }
    
    for(string x : A){
        int len = pre(x);
        ans.push_back(x.substr(0,len+1));
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<string> s = {"zebra", "dog", "duck", "dove"};
    prefix(s);
    return 0;
}
