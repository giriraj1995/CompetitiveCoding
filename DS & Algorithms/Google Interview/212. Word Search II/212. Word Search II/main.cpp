//
//  main.cpp
//  212. Word Search II
//
//  Created by Giriraj Saigal on 10/11/21.
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

struct Trie{
        char c;
        bool ends;
        vector<Trie*> child;
        string s;
    };
    
    Trie* buildTrie(char c) {
        Trie* t = new Trie();
        
        t->c = c;
        t->ends = false;
        t->child = vector<Trie*>(26, NULL);
        t->s = "";
        
        return t;
    }
    
    void buildTrie(string word, Trie* p) {
        
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(p->child[c-'a'] == NULL) {
                p->child[c-'a'] = buildTrie(c);
            }
            p = p->child[c-'a'];
        }
        
        p->ends = true;
        p->s = word;
        
    }
    
    vector<int> Xs = {1,0,-1,0};
    vector<int> Ys = {0,1,0,-1};
    
    void dfs(int i, int j, vector<vector<char>>& board, Trie* p, set<string> &ans) {
        char c = board[i][j];
             
        if(p == NULL)
            return;
        
        if(p->ends == true) {
            ans.insert(p->s);
        }
        
        for(int k = 0; k < 4; k++) {
            int x = i + Xs[k];
            int y = j + Ys[k];
            
            if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] != '$' && p->child[board[x][y]-'a'] != NULL) {
                board[i][j] = '$';
                dfs(x,y,board,p->child[board[x][y]-'a'],ans);
                board[i][j] = c;
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>> board, vector<string> words) {
        Trie* root = buildTrie('/');
        set<string> ans;
        
        for(string word : words) {
            buildTrie(word, root);
        }
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(root->child[board[i][j]-'a'] != NULL)
                    dfs(i,j,board,root->child[board[i][j]-'a'],ans);
            }
        }
        
        vector<string> ans2;
        
        for(string k : ans)
            ans2.push_back(k);
        
        return ans2;
    }

int main(int argc, const char * argv[]) {
    findWords({
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}},
              {"oath","pea","eat","rain"});
    return 0;
}
