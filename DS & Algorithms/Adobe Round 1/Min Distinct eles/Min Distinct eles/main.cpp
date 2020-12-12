//
//  main.cpp
//  Min Distinct eles
//
//  Created by Giriraj Saigal on 12/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int mindistinct(int Arr[], int N, int K)
{
   unordered_map<int ,int> mp;
   
   for(int i = 0; i < N; i++)
        mp[Arr[i]]++;
    
    vector<pair<int, int>> vec;
    
    for(auto i : mp) {
        vec.push_back({i.second, i.first});
    }
    
    sort(vec.begin(), vec.end());
    
    int ans = mp.size();
    
    while(vec.size() > 0) {
        int count = vec[0].first;
        int ele = vec[0].second;
        
        if(count <= K){
            K = K - count;
            ans--;
        }else
            return ans;
        
        vec.erase(vec.begin());
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1 ,1, 2, 2, 3, 3, 4, 4, 7, 8};
    mindistinct(arr, 10, 4);
    return 0;
}
