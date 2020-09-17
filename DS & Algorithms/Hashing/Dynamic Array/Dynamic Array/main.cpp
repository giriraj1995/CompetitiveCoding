//
//  main.cpp
//  Dynamic Array
//
//  Created by Giriraj Saigal on 17/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> q) {
    int lastAnswer = 0;
    vector<int > ans;
    unordered_map<int, vector<int>> u;

    for(int i = 0; i < q.size(); i++){
        vector<int> query = q[i];
        if(query[0] == 1){
            int t = (query[1] ^ lastAnswer)%n;
            u[t].push_back(query[2]);
        }else{
            int t = (query[1] ^ lastAnswer)%n;
            lastAnswer = u[t][query[2] % u[t].size()];
            ans.push_back(lastAnswer);
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    dynamicArray(2, {{1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}});
    return 0;
}
