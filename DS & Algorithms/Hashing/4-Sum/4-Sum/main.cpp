//
//  main.cpp
//  4-Sum
//
//  Created by Giriraj Saigal on 16/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(vector<int> in, vector<int> &out, map<vector<int>,int> &u, int sum){
    
    if(sum == 0){
        if(out.size() == 4){
            u.insert(make_pair(out, 0));
        }
    }
    
    if(out.size() > 4)
        return;
    
    if(in.size() == 0){
        return;
    }
    
    vector<int> out1 = out;
    int x = in[0];
    in.erase(in.begin());
    out1.push_back(x);
    
    solve(in, out1, u, sum-x);
    solve(in, out, u, sum);
}

vector<vector<int> > fourSum(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    vector<int> out;
    map<vector<int>, int> u;

    solve(A, out, u, B);
    
    map<vector<int>, int>::iterator itr;

    for(itr = u.begin(); itr != u.end(); ++itr){
        ans.push_back(itr->first);
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    vector<int> x = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
    int B = -3;
    fourSum(x,B);
    
    return 0;
}
