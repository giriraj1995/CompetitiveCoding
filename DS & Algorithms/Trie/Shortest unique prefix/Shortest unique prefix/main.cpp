//
//  main.cpp
//  Shortest unique prefix
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

class Trie{
    private:
        class Node{
            public:
                bool end;
                Node* child[26];
                Node(){
                    end= false;
                    memset(child, NULL, sizeof(child));
                }
        };
        
    public:
        Node* root;
        Trie(){
            root= new Node();
        }
        
        void insert(string w)
        {
            Node* node= root;
            for(auto c: w)
            {
                if(node->child[c-'a']==NULL)
                    node->child[c-'a']= new Node();
                node= node->child[c-'a'];
            }
            node->end= true;
        }
        
        int findPre(string w, int index, Node* node)
        {
            if(index>=w.size())
                return -1;
            int t= findPre(w, index+1, node->child[w[index+1]-'a']);
            if(t==-1)
                return index;
            
            int cnt= 0;
            for(int i=0;i<26;++i)
                if(node->child[i])
                    cnt++;
                    
            if(t!=index+1 || node->end || cnt>1)
                return t;
            else
                return index;
        }
        
        int pre(string w)
        {
            Node* node= root->child[w[0]-'a'];
            return findPre(w, 0, node);
        }
        
};

vector<string> prefix(vector<string> &A) {
    int n= A.size();
    Trie trie;
    for(auto word: A)
        trie.insert(word);
    vector<string> ans;
    for(auto word: A)
    {
        int len= trie.pre(word);
        ans.push_back(word.substr(0, len+1));
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<string> s = {"zebra", "dog", "duck", "dove"};
    prefix(s);
    return 0;
}
