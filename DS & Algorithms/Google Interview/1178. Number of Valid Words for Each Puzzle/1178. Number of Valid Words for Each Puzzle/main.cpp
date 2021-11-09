//
//  main.cpp
//  1178. Number of Valid Words for Each Puzzle
//
//  Created by Giriraj Saigal on 09/11/21.
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

//bool check(string word, string pz) {
//
//        for(char c : word) {
//            if(pz.find(c) == string::npos) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
//        int n = puzzles.size();
//        vector<int> ans;
//
//        for(int i = 0; i < n; i++) {
//            string pz = puzzles[i];
//            int count = 0;
//
//            for(int j = 0; j < words.size(); j++) {
//                string wd = words[j];
//
//                char fp = pz[0];
//                if(wd.find(fp) != string::npos && check(wd, pz)) {
//                    count++;
//                }
//            }
//
//            ans.push_back(count);
//        }
//
//        return ans;
//    }

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char, set<int>> mp;
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                mp[words[i][j]].insert(i);
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < puzzles.size(); i++) {
            char f = puzzles[i][0];
            set<int> idxs = mp[f];
            int pz = 0;
            
            for(int j = 0; j < puzzles[i].size(); j++) {
                pz = (1<<(puzzles[i][j]-'a')) | pz;
            }
            
            int count = 0;
            
            for(int ind : idxs) {
                string word = words[ind];
                int wd = 0;
                for(int j = 0; j < word.size(); j++) {
                    wd = (1<<(word[j]-'a')) | wd;
                }
                
                if((pz & wd) == wd)
                    count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<string> w = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> p = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    findNumOfValidWords(w,p);
    return 0;
}
