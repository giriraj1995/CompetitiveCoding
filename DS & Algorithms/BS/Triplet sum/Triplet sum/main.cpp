//
//  main.cpp
//  Triplet sum
//
//  Created by Giriraj Saigal on 05/10/20.
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

long smaller(vector<int> a, int ele){

    int i = 0;
    int j = a.size();
    int res = -1;
    while(i <= j){
        int m = i + (j-i)/2;
        if(a[m] == ele){
            return m + 1;
        }else{
            if(ele < a[m]){
                j = m - 1;
            }else{
                res = m;
                i = m + 1;
            }
        }
    }
    return res + 1;
}

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {

    long ans = 0;
    sort(a.begin(), a.end());
    unordered_map<int, bool> t;
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for(int i = 0; i < b.size(); i++){
        if(t.find(b[i]) != t.end())
            continue;
        else
            t[b[i]] = true;
        
        long x = smaller(a, b[i]);
        long y = smaller(c, b[i]);
        long d;
        
        d = x * y;
        ans += d;
    }

    return ans;

}


int main(int argc, const char * argv[]) {
    triplets({1, 3, 5, 7}, {5, 7, 9}, {7, 9, 11, 13});
    return 0;
}
