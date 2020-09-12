//
//  main.cpp
//  Permutation
//
//  Created by Giriraj Saigal on 12/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool allones(vector<int> k){
    
    for(int i: k){
        if(i != 1)
            return false;
    }
    
    return true;
}

void solve(string A, string &output, vector<int> &k, vector<string> &ans){
    
    if(allones(k)){
        ans.push_back(output);
        return;
    }
    
    int n = (int)A.size();
    
    for(int i = 0; i < n ; i++){
        
        if(k[i] == 0){
            k[i] = 1;
            output.push_back(A[i]);
            solve(A, output, k, ans);
            k[i] = 0;
            output.pop_back();
        }
    }
}

void permutation(string A){
    
    vector<string> ans;
    int n = (int)A.size();
    vector<int> k(n,0);
    string output;
    
    solve(A, output, k, ans);
    
    cout<<"done"<<endl;
}

int main(int argc, const char * argv[]) {
    //permutation("abc");

    return 0;
}
