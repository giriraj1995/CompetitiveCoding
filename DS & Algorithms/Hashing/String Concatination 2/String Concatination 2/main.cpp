//
//  main.cpp
//  String Concatination 2
//
//  Created by Giriraj Saigal on 20/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

vector<int> findSubstring(string A, const vector<string> &B) {
    
    int l = (int)A.size();
    int b = (int)B.size();
    vector<int> sol;
    
    if(b == 0)
        return sol;
        
    int len = (int)B[0].size();
    
    map<string, int> count, seen;
    
    for(auto i : B){
        count[i]++;
    }
    
    
    for(int i = 0; i <= l - len*b; i++){
        int j = 0;
        for(j = 0; j < b; j++){
            
            string word = A.substr(i + j*len, len);
            if(count.find(word) != count.end()){
                
                seen[word]++;
                
                if(seen[word] > count[word])
                    break;
                
            }else
                break;
        }
        
        if(j == b){
            sol.push_back(i);
        }
        seen.clear();
    }
    
    return sol;
}
int main(int argc, const char * argv[]) {
    vector<string> x = {"foo", "bar"};
    vector<int> k = findSubstring("barfoothefoobarman", x);
    return 0;
}
