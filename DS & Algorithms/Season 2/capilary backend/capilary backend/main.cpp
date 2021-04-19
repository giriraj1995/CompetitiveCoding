//
//  main.cpp
//  capilary backend
//
//  Created by Giriraj Saigal on 18/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

vector<int> find(map<int,int> &mp, int &B) {
    map<int,int,greater<int>> mp2;
    for(auto k : mp) {
        mp2.insert({k.second, k.first});
    }
    vector<int> ans;
    int j = 0;
    for(auto k : mp2) {
        j++;
        ans.push_back(k.second);

        if(j == B)
            break;
    }

    return ans;
}

int solve (int n, vector<int> A, vector<int> B) {
   int ans = 0;
   map<int, int> mp;

   for(int i = 0; i < n; i++) {
        mp[A[i]]++;


       if((int)mp.size() >= B[i]) {
           ans++;
            vector<int> arr = find(mp, B[i]);
            for(int g = 0; g < B[i]; g++){
                mp[arr[g]]--;
                if(mp[arr[g]] == 0)
                    mp.erase(arr[g]);
            }
       }

   }
   return ans;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
