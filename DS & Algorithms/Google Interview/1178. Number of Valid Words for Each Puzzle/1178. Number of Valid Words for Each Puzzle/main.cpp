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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
