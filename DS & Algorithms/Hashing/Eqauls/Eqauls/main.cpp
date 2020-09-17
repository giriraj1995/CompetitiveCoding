//
//  main.cpp
//  Eqauls
//
//  Created by Giriraj Saigal on 17/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> equal(vector<int> &A) {
    vector<vector<int>> ans;
    
    unordered_map<int, pair<int,int>> u;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = i + 1; j < A.size(); j++){
            
            int sum = A[i] + A[j];
            
            if(u.find(sum) == u.end()){
                u[sum] = {i,j};
            }else{
                
                int x = u.find(sum)->second.first;
                int y = u.find(sum)->second.second;
                
                if(x != i && x != j && y != i && y != j){
                    
                    ans.push_back({x,y,i,j});
                    return ans[0];
                }
                
            }
        }
    }
    
    return {};
}


int main(int argc, const char * argv[]) {
    vector<int> x = { 3, 4, 7, 1, 2, 9, 8};
    equal(x);
    return 0;
}
