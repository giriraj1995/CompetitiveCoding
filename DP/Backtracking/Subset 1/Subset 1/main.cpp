//
//  main.cpp
//  Subset 1
//
//  Created by Giriraj Saigal on 11/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void subset(vector<int> input, vector<int> output, map<vector<int>, int> &u){
    
    if(input.size() == 0)
    {
        u.insert(make_pair(output, 0));
        return;
    }
    
    int x = input[0];
    vector<int> output1 = output;
    vector<int> output2 = output;
    output2.push_back(x);
    input.erase(input.begin() + 0);
    subset(input, output1, u);
    subset(input, output2, u);

}


vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    map<vector<int>, int> u;
    vector<vector<int> > ans;
    vector<int> input = A;
    vector<int> output;
    subset(input, output, u);
    
    map<vector<int>, int>::iterator itr;
    
    for(itr = u.begin(); itr != u.end(); itr++){
             ans.push_back(itr->first);
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    
    vector<int > x = {12, 13};
    vector<vector<int> > y = subsets(x);
    return 0;
}
