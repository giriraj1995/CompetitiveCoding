//
//  main.cpp
//  Word Abr
//
//  Created by Giriraj Saigal on 28/06/22.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


struct Node{
        vector<Node*> child;
        vector<int> re;
        vector<vector<int>> lastChar;
    };
    
    void createTree(string s, Node* p, int ind, int x, int f) {
        int n = (int)s.size();
        for(int i = 0; i < n-2; i++) {
            char c = s[i];
            Node* tmp = p->child[c-'a'];
            if(tmp == NULL) {
                tmp = new Node();
                tmp->child = vector<Node*>(26, NULL);
                tmp->re = vector<int>(400,0);
                tmp->lastChar = vector<vector<int>>(400);
            }
            tmp->re[ind] = n-2-i;
            tmp->lastChar[x].push_back(ind);
            p->child[c-'a']=tmp;
            p = tmp;
        }
    }
    
    void traverse(vector<string> &ans, Node* p, string inp, char lastChar, int x){
        if(p == NULL)
            return;
        
        if(p->lastChar[x].size() == 1){
            int ind = p->lastChar[x][0];
            ans[ind] = inp + to_string(p->re[ind]) + lastChar;
            return;
        }
                                             
        for(int i = 0; i < 26; i++) {
            Node* c = p->child[i];
            if(c != NULL){
                inp.push_back(i+'a');
                traverse(ans, c, inp, lastChar, x);
                inp.pop_back();
            }
        }
    }
    
    vector<string> wordsAbbreviation(vector<string> words) {
        vector<string> ans = words;
        
        int i = 0;
        unordered_map<string, vector<int>> mp;
        
        for(string s : words) {
            if(s.size() <= 3)
                ans[i] = s;
            else{
                string abr = s.substr(0,1) + to_string(s.size()-2) + s.substr(s.size()-1);
                mp[abr].push_back(i);
            }
            i++;
        }
        
        Node* p = new Node();
        p->child = vector<Node*>(26, NULL);
        p->lastChar = vector<vector<int>>(26);
        p->re = vector<int>(mp.size());
        
        int x = 0;
        for(auto k : mp) {
            if(k.second.size() == 1) {
                ans[k.second[0]] = k.first;
            }else{
                for(int j : k.second) {
                    createTree(words[j], p, j, x,(int)mp.size());
                }
            }
            x++;
        }
        
        x = 0;
        for(auto k : mp) {
            if(k.second.size() != 1) {
                traverse(ans, p, "", k.first[k.first.size()-1], x);
            }
            x++;
        }
        
        i = 0;
        for(string f : ans) {
            if(f.size() == words[i].size())
                ans[i] = words[i];
            i++;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<string> ans = wordsAbbreviation({"bbabaaaabbbbababaababaaabbbaaabaababbabbaaaaababbbababbaaababbbbbbbbbbaaaaabbbaabaaaaabab","ababaaabaabbabbabbbbaaababaaabaabbbabbbabaabbbabbbaaaababbaaaababbabababbaababbab","baaabaaaabbaaaabaabaababaaaaababbabaabbaaaa","bbbaa","abbababbabbbbabaaababaaaaababbaabbaabbbaaaba","bbaaabbabababbbaaaaabbabaabbbbabbabaaabbaaaabbabbbbbaaabbabaabbbbaabbaabbbbababbbbaabbbbbabbbaaaabaaaababbbbbaabbbbabbabaabaaabbaaaaabababababbaaaabbaaaabbbbabbbbbbbbbbbabaaaabbbababbbbab","aaaaabbbbbaabaababaaaabbaabaababbbbabbaabaaabbbaaabbbbbbbbbbabbbaabaabbbbabaaaaaaaabaabbbbbabaabbbbbbbbabaabbaaabbbbbabaaaababaaabbaaabbbbabbbbbaaaabaabbabbbaaaaaaabbaaaaaaabababbbaabaaaaaabbbbaabab","bb","bbabaababbbbbbbbbababbabbaabaaaaaaababbababbbbaabbbbbbbabbbabbbbbaaabaaabaaaabaaababbbbbabbbbaaabbbaababbbbaabaaab","abaaaababbbaabaaaabbbbbabbbaaaabbaaabbbaaaabababababbaabaaabaabaabababaabbbabbabaaabaaaaaababbbbbabaaaaaabaaabaabaabbabaaabaabbbbbaaabbbbbbabaaabbbabbaaaaaabaaabbbbababbaabbbaabaaabaaabaa","aaaaabaabbbaaabbabbabababb","ababaabaaabbbbabaabbbbbbaaabbbaabbbbabbabaabbabaaaa","abaaaaabbbaabbabaabbbbaababbaabbbabbabaaaababbbbbbabaaaaabbaaaabaabababbbabbabbbbbbaabaaabbaabbaababaababaaabbababbbaabaabbbababaabbabaaaaababbaaabbbbababbbabbbaabbabbabbabaaba","bababaabababaabababbabbabbbaaabaaabaabaaabaababbbbbabbababbbabbabaabaaabaaababababbabaabaaabbbaaaabaaaaabab","bbbaaabbaaabbbaaaaabbabaaabbabbbaabbababbbbaababaaabaabbaaabbbbaabbaabbbaaaabbbbabbabbabbaabbabababaababbaaaabaabababababbaaababababbababbbaaababbbbaabb","baaaaabaababbbbbaabaaabbabbbbbbaaabbbbbaaabababbbabbaaaabaaaaabbaaaabaabababaaaaaaaaabbabbbaabbababbabbabbbbbbbbaababbabbababbbbabaaaaaaaaaaababbbabaabaaababaaaaabbaa","bbababaaababbabbbbaaaaaabaabaabbabbababaabaabbbabaababbbbabaaabbbabababbbabaaabbbbabaaaaabaaabbbaabbaabbaabbaaabbbabaabbbbabbabbaa","babaabbbbaaaaabbaabbaabaaababaaaabbbaaababaaababaaabaabbbbbaababababbabbbbbbbabaababaab","baabaaaabbaabbaaabaaaaaabbaabbaababbbbabbababbbbbbbabaaaabbaabbbaabbbbabbaaaabaababbbabbbbbaabaaabbbbabbbababbaabbababbaabbbbbbbababaabbbbaaaaaaabbaaabbbaabbbbabbbaaaabbabaaaaaaaaaab","bbababbbaabbbbaaaaabaabaabaabaababbabbabbabbbbbbbabbabaaaabbaaabbabbabaaaaaabaaaababaabbbbbbabbbbbbabbbaabbbababaaabbaaabbbaaabbbbabbaabbaabbababaaabbabbabbaabbbbbbabbbaabaabababbaaba","ababbabbaaabaaaaabaabbbababbabababbaabbabaaaaaaaaaabbabaabbbbaabababaaaababbabbbbaaabbbaaaabaababbabbabaabaaaabbbaaaababbaabababbaabbaabbaaaabbbbbbbaaaababaabbbbababaabbbaabbbbabbabababbabb","abbababbaabaabbaabbbaaaaaabbaabaaababbbabbaaabbaaaabbbbbbbabaaababaaabbabbbabaaaaabaaaaababbaaaaababaabbbaaabaabbabbbabaabbaaaabaaabaaaaaaaaababbabbababbabaaaababaaaabbbaabbbabaab","bbbbb","abababbabaaabbbbaaaaabbbaabbabababaaaabaabaabbbbaabbaaaaabaaaababaaaaabbaaabbaaabaaabbbbbaabbbabaabbaaabbaabbaabbbabaaaaabbbbaaaabbbabbbaaaabbabbbaaaabbaabababa","bbaababbbbaabbbbbbaababbbabaababbababaaaababaaabbabaababbbbbbbbaaabbababbbaabbaabaaaaabbabbaaabaabbaabaabaabbbaaaaabaaaaaabbbabaabaaaaaabbabbaabaababaabbaabababaaaababaabbbbaabbbbbaabbbabba","aabbbaaabbbbbaaaababaabbaabbabbabbabbbbabaaaaaababbbaaaabbbbabb","aaaaabbaaaaabbabaaaaabbaaaabbaababbabbabaaaabbbbaaaaaababaa","aaabbbaaaaabbabbaabbabaababbbabababbbbbbbaaabababaaababbbbabbbaabbbbbabbbabbbbbaaaaabbbabbbbabbbaababaababbababbabbabbaabaaaabab","aabaabbabbaababbaabababbababbbaaaaabaabbbbaabbbbbbabaabbaaaaaaababbbbbaaabaabaabbabbbaabababaababbbbbbbbb","baaabbabaabbaabbabababababbbbaabbbba","abaabbaababbaaaaaaaabbbbbabababaaaabbabbabbbaaabbaabaaaabbbbaaaabbaabaab","baababb","aaabbbbabababbbabbbbaabbaaaab","babbbbbaabaabbbbababbbbaaabbaabbaaaaabbaabbbabbbababaabbaaaabbabaaababbbbbabbbaaaaabbbababaababaaaaaabbbbbabaaabababbbaababbaabbaaaaaabababaabbababaaababbabbabbbaabaaaabaababa","baaaababbaaabbaaabaaaaaaabaababbaabbaaabbabbabaaabaaaabbbbbabababbbaabbbbbaaabbabbabbbbbbaaabababaaabaabbabbbbaa","bbbaaaabbbbbabaabaaaaaabbbbbbbabbbabbb","abaabbbabbbaabababbbabbababbbbabababbbbbaabbbabbabbaaaababbbbbbbb","abbbaaaaaababbaabbaaaabbbbbbbbaaabbabababbaaabbabbaaaabbabbbbaa","bbabbabbbabababbaabbbaabbbbabbaaaabbbababbaaaaaaaaaaaaaaabbababbbbbabbbaabaaaaaaaaaaaababaaabbbababaabbabaaaaaaaaaaabbabaabbaabbabaabbbbbaabaababbabaabbaabaabbababbbaaa","abaaabbabbbbaaaaabababaaaaabbbbabababbabbaaaaabababbabaabbbaabbbbbabbbabaabaaaabaaaaabaabaaaabaaaaaaaababaaaaabaaabbabbbabbbbbbbbabbbabbabababaaaaaaaabbabbabbaaaaaaabbaabbabaabba","abbaabbbaabbbbaaabaabaaaabbbabbaabbaaabaababbbababaabbbababbaaabbbbbbababbab","abaaabaaaabbabababaababbbbbbbbaabbaabbaababbababaabbaaabbabaabaabaaaabaaababbbabababbbababbaabbbabbbbaaabbaaaaabaabaaaabaababbaaabbaaaaabaabbaaaaaabaabbababaabbaabbaaabbaabaaabbaaabaabbbbaaaaaabba","ababbbbaaaaaabbbababaabbabbbbbbabababbabbbbabbbbbaaaabbbbaabababababbabbaabbaaabbbbaaabbbabbababaabbbbbababb","bbaab","baabaabbaabbabaaabbabbababaaabbabbbbbaaba","bbbabababaabbbaababaaabbbbaabaaaaaaabaabaababbbabbbaabaaaaaaaabbababbbbaabbabbb","bbabababbababbaabbbababababaaabaabaabaaaaaaaabbaabbaababbaaababbbbaabbaabbaabbaba","aabbaabbbaaaaababbbaa","bbbaaababbabaaaabbbabbaababaaaaabbaaaabbbaaaaaabbbababbaaaaabbabbbaaaaaaaa","babaabbabbaababbbbbbbbbbbbabaabaaabababbaabbbaabbbaaaaababbaabbabaaaabbaabbbaabbaabbababbabbaaaaabbaabaababababaabababaaaaababaabaabababba","bbbabbabaaaabaaabbbbaaaaaaaabaaaababbaaaabbbbababaabbbaaaaaabaababbbbabbbbabbaabbabbbaabbaaaabbbbbaabaababaaabbaaaababaabaaaaaaaab","baabbaaabbbbababbbbaabbbaabababbbabbabbbbaaabaabbbbababaabbaabaaababbbaaaabba","bbaabbbbbaabbbbbbaaaabaababbaaabbaaaababbbaaabbaaaaabbaabbbabaabbabbbbbbbbabababbbaababbbabbbaab","bbbaabbabbaabbaabaaaaaaabbaabbbaabbbaaaaabbaaaaaaabaabbabaaababbbaabbbabbabaabbabbbaaaaaaabaabbbabaaabaababbbaaabababaaaaabaaaabaaababbbaaabbbbbbaaaaaaabaabbaabbababaababbbababbbbbbaa","bbbbababbaabbabaaaababaaabbabbbaaabaaabbaaabbabaababbaaaaabaabbbbababbbbbbbbaaaabbbabbbaababababaabbbbaabababbbabaabaabbaaaaaaaaaaababbaaaaaabababaabbbbbbbabaabbbbbaabaabbbabaa","abbabbababbbbbbbabaabbaabaababbbaaaaabababbbbbbaabbabaabaababaaabababbaabbbbaabaaabbbaab","bbbaabbabbbabbaabaabaabaaababbaaabaaabbbbbabaaaababaaaaaababbbbaaaabbbbabaabbbbbabaababababa","aababbbaababaaabaaaaaaabbbbababbbaaaabbabababbababaabbbabbbbbbababbabbbaaaaaaaabbbbabaababaababaaabbaabaabbbbabbaabababbaaaabaaaabbabaabbbbbbabaabbbbaaaababaababaababbaabbbbbbbabaa","aaabaabbabababaaabbabaaaaaaabababaabaabbaababaabaaabbbbabbbaabaaaabaabbbbbbbaaaabbbbabbbaabbbaabbbbbabbaabbabbbbbbba","aaa","bbbbaaaaabbaaabaaabbaabbaabbabbabbaababaaaaabbbabaaaabaaaabaaababbaabaabbbbabbabbbbbababbabaabaabaababbaaaabbbaabbaabaaababbbbabaaaaaaaabbbaabaabbabbaabaaba","aaaababbbabababbbaabbabbbababaaaabb","bbbaababbbaaabaa","aaabbaaaabbbabaaabaabbabaaabbbbbbbbaabababbbaabbbaabbbababbbaabbbbabbbaabbbaababbbbbaaababbbbbbabaabababbbaaaabbaaabaababababababbab","bbbbabbbbbabbaabbabaaaababbaa","bbabbbbbaaaaababbbbaababaabbbbbbbbbababbababbababbababaabbbbbaaabbaaababbbbbbaabbbababaaaabaaaabbabaababaaababbaabaaaa","bbbabbbbabbbbabbabbabbbabababaabababbabbababaaaabaabbbbaabbbbbbbabbbbbbaabaaabbbbabaaaabbbbabaaaabbbbaabaababbbbbaaabbabbbbbbaabbaaabaabbbabaab","aaabababaababbbbbaaabbbbbbaaabbaaaaaababbbabababbbaabbaababaaaaaaabbaabbbaaaabaaabbaaaaba","babbbaaababbbbabaabaabbaababaaaaaabbaabaaaaabbbbaaaaaababbaaab","aabbbaabbbbbabaabaaaaabbbbaabaabbbbbaabaabbbbbbaababbbbabbbaaba","aaabababbbaaabababbbbababbaabbabbabbbaabbaabaabbabbbbabbaaaaaaababaaaababbbababbbababbabbabbbbbbaaaababbaaabaabbaababbbabaababbaaaaaababbabbababbaaa","abaabbaabbbbbaaabaaaaabbaaabaaaaaaaaababbbabaabbababbbabbbaababb","abbbbabbabbbbbbbbabbbaabbaabbbbbbbbbbabbbbabbaabbbbbbbaabbbbb","abbbbbaaaaabaabbaabbabbbababaaaaaababbbaaabbaabaaababaabbbaaaaaaaabaabbabbbabbabbbbaabbbbabbabaaaaaaabaaababababbbbabbaabaabbaaabbbaabbbaababaaaabababbbbbbbaabbbbaabababbabaabbaaabbaa","bbbaabaaabaababababababaaaaabbabaaabbababbabbbbbaababbaabbaabbbbbbabbbbbbbbbbabaabbaabbbbababbaaaabbbabbbabbabbababbaaaabbbbbbbabaaabbaabaabaaba","bbabbbbbaaaaaabaabaaabaaabaaabaabaababaaabbbaabababaaaabbaababbbabababbbbbabaaaaaaabbabbbabbaaabbabaabaaabbbabbaabaaabbbbbbaabbaababbbbbba","aababbbbbbabbaabaabbabbaababababbbbbabbaabababbbaaababbbbbaaaa","bbbaabbaaabaaaabbabbbaaaabaabbababbbbbababbbaaaaaababbaabaabaabaabbbbbbbbabbabbbbaaabaaaaabbbbabaaababbababbaaaabbabbbbbaabbbbbababbbabbabbbbabbababbbbaabbaababbbbbbaaaabaa","bbbabaabaabababbbabbbabbbaaaaabbbbaabba","bababbababbaabbaabbaaabbababbabbbaabaababbbaabbbaabbbababbbaaaaaabbaabbabbabbabbbbbbaaababbbabbaababaababaaaaaababababbbabbbabaabababbaabbbaaabbaabbbbaababaaaaba","bbbbaaabbbababaaabbaaaababaaabbbbabbaabaabbaaaaaaabaababbabbabbabaababaabaaaaaabaabbbaaaaabaaaabaabbbbbababaaabaabbbbaaabbaabb","baabbaaaabbaaaabbaaaaa","abbabaaaabaabaabbaababbaaababaaababbbaaabbbbaaaabbabaababbbaabaaababbbaaaaababbaabbbaabbbaaaababbbaabaabaaabbaabbbaabbaaab","bbbaaabbaaabaaabbbabbbbaabaabaabababababaaabaabababbabbaababbbabaaaaaabbabababababababaabbbbbbbaaaabbaaabaaabbbaabbbbababaaaabbabbababbabbbababbabbbbbababaaababbbbbabab","baaabbbababbbabababaabbbbabbabaabbababaabbaaaaaaaabbababaaababbbbabbbaaabaaaaabbbabbbbbbbabbababab","aaabaaaaabbbabbbbbbbaaaabbabaabaabaabbaabaababaabbbabbaabba","baabaababaaaabbbbbabababbabbb","abababaabbbbbaba","abbbaaaaabbbbabbabbbbbbbbbbbabaababaabbbbabbbbbbabaaaabaabbabaaabaabaaaaaaababaababaababbbbbbabbbababbbaabbaabbb","babaaba","ababbbabaabbaababaaaabbbbaababbbababaabbbaabaabaaaaaabbababaababaabbabbaabaaa","baabbbaaaabbabbbbaaaabaabbaaaabbbaaaaabbbbaabbbbaababbbabbabaabbbbbbbbbaabbbbaabbaaba","abbbabaaabbabaabbbabaaaabbaababbaaaabaabbbbbabaaababbbaaababbbabbbbaaaaabaaabbbbbaabbaababbaabb","abaaaaabbaabaabbaabbbaaabaaaaabbbaaaabbaababaabbaaaababbbbaaababbbbbababbaabbababbaababbaaababbaabaabbaabaabaaabbbb","bbaabbaaabbbaabbaabaaaabbbbbabbbbbabaaabbabbbbbaaaabaaabbaaaabbbbabaa","abbabaabaaabaaaabbaabbababaabbabbbbbaabaaabaaaaaaaaabbbbababbababbbbaaabbabbaabbbbbbbbbababbbababbb","bababbbbbabbbabbbbbaaaaaabbaababaabaabbaaaabaaaaabbabaabbbaabaabbbbababbaaaaabbaaaabaaaaababaaababbaabbaaabbaaabaaaaa","babbbbbaaaababbabbabbaabababaaababaabbabbbabbabaabaaabaabaaabaaababaabbaaaaaababaaabbabbbbabababababbaabbbaabbbabaababbbba","abbaabaabbbaaabbbbbabaaabbaaabb","aaabbaaaabbaaabbbbbbaabaababbaaababaabaaaaabbaaabaabaabbbbabaaaaaaaababbbaaabaaababbbaaabbbbbabbbbaabaaaabbabbaaabaaaabbaaaabbaabbbaabbbaabaa","aa","abaababbaaaabbbaaababbbaaabbaaabaababbabbaabaabbb","babaaaabaaababbaaabaaababaabbbbabbababababbbabaababaabbbbaabbbbabaabbabaabaaaaaababaaabbbaabbabbabaabbbabbbbbabaaaabbbbabaaaaabbaabbaabaabbababaaaababaaba","bbbbaabbabbbabaabbbbbaababaababbababbbbbbabbabbbbabbaabaaaaaaaaabaabaaabbaabbaaabbbbaaabaabbbababaaaaabbbaaabaabbaabbbbaba","abbabbbbbbbbbaabab","abaaababbabbbbaaaab","abbbabababbaaabaabbaa","babaaabbabbababbbabaaaaabbaabaabaabbbabaabbabaabaaababbaabaabbaabaababaaaaaaaabaabbababaaaaabbaababababbbba","babbaabbabababbbabaaaaabbabbbaabbbbababbbaaababbbaabaabbaaabbbbaaaabaabaaaaaaabbaababbbbabaabaabbabbaabbbbabbabbaaabbabbbbbbaaaabbaaabbabaabbbababbbbbabbabbabba","abaababababaabbbbbbaaaabbbbbbbbaabbbaabbaabbbabbabbaaabaaaaaaabbbbbaaaaabaab","aaababbabbbbaaabaaaabaaabbababbbbabaabbabaaabaabbbbbaaaabbbbabbababbabbaaaabbbabbaaabbababbabaaaaaabaabaaabaabbaaaabb","abbbbaabbababbbaabbbabbabaabbbbaaabbaababbaaaaaabbbaabbbbbabaaaabbbaaabbbaaaaaaabaababbabbabaaaaabaaaabaabaaabbbabaaabaabaaabaababbbbbbabbbaa","babbbbbbbabbabbbbabbbaaabbabbbbaaababbabababaabbbbbbabbbbabababbaaaaabaabaababbaa","bbbbbbbabbaaaaabbabbbaaaabbabaaabbbaabbbabbbbaabbaababaaabbabaaaaaaaabaaabbbabbbbaaaaababbabbbababbaaabbaabbaabaaabbabaaaabbbbbaababaabaababbbbbaaaabaaababbbabbbaa","abbbbaabbbbabbbaaababababaaabbabaabaaabababaabaabbabbbbbbaabbabbaaaaaababaaabbabbbbabbbaabbbabaaabbaaaaaabaaabaa","bbaaabaaabaabaabaabbbbaabbbababbbbbbaaaabbbaaabbbaaaabaaabaaaaaaabbbaaaabbabaababaaabbaaaaabbbabaaaabbbbbbbbbbaababaabbbaaabbbabaaaabbbb","aaabbaaabbbbababbabbbaaababaababaaababbbaaababaabbaaabbababababbabbababbaabaaaabababbaaababbbbabbbbbbbaaabaabbabaabbbbbbbaabbbababbbbbbaabaaaabbabbaabbaa","aabaaaabbabaaabaabaababaabbabababbbbabaabaabaabbbbbabaaaaabaaabbbaabbbaabbbbaaabaabaabbabbbaaaabbbbbaabbaabaabaaaabbabbbbaabaabbbaabbabbabaaabaababaabaababbbbbabbabaabbaaaabaaabbbaabbaabbbaaaaaab","babbaaaba"});
    return 0;
}
