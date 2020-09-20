//
//  main.cpp
//  Substr Contatination
//
//  Created by Giriraj Saigal on 20/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool allOnes(vector<int> k){
    
    for(int i : k){
        if(i != 1)
            return false;
    }
    
    return true;
    
}

void solve(vector<string> B, string &o, vector<int> &k, map<string, int> &u){
    if(allOnes(k))
    {
        u.insert(make_pair(o,1));
        return;
    }
    for(int i = 0; i < k.size(); i++){
        if(k[i] == 0){
            k[i] = 1;
            string g = o + B[i];
            solve(B, g , k, u);
            k[i] = 0;
        }
    }
}

vector<int> findSubstring(string A, const vector<string> &B) {
    
    // map<string , int> u;
    // vector<int > ans;
    
    // string o;
    // int n = B.size();
    // vector<int> k(n,0);
    // solve(B,o,k,u);
    
    // for(auto i : u){
    //     string t = i.first;
        
    //     for(int j = 0; j < A.size(); j++){
            
            
            
    //     }
    // }
    
    vector<int > ans;
    
    int n = B.size();
    
    if(n == 0)
        return ans;
        
    int l = B[0].size();
    
    int lenghtofSub = l * n;
    
    if(lenghtofSub > A.size())
        return ans;
        
    if(lenghtofSub == A.size()){
        return {0};
    }
    
    map<string, vector<int>> u;
    
    for(int i = 0; i <= A.size() - lenghtofSub; i++){
        u[A.substr(i, lenghtofSub)].push_back(i);
    }
    
    
    map<string , int> map;
    string o;
    int m = B.size();
    vector<int> k(m,0);
    solve(B,o,k,map);
    
    for(auto i : map){
        string t = i.first;
        
        if(u.find(t) != u.end()){
            
            vector<int> h = u.find(t)->second;
            
            for(auto f : h)
                ans.push_back(f);
            
        }
    }
    
    
    
    return ans;
}




int main(int argc, const char * argv[]) {
    vector<string> x = {"acb", "cac", "bba", "bab", "bba", "ccc", "bac", "bcb" };
    vector<int> k = findSubstring("abbbbbbabcccabbbbacbacaccbbbabbbc", x);
    return 0;
}
