//
//  main.cpp
//  Flavour + cost
//
//  Created by Giriraj Saigal on 16/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void solve(int &i, int &j, vector<int> x, int n){

    while(i < j){
        int m = x[i] + x[j];
        if(m == n){
            return;
        }else{
            if(m > n){
                j--;
            }else
                i++;
        }
    }

}

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {

    unordered_map<int,int> u;
    int k = 0;

    for(int i : cost){
        u.insert(make_pair(i,++k));
    }

    sort(cost.begin(), cost.end());
    int i = 0;
    int j = cost.size() - 1;

    solve(i,j,cost, money);

    int d = u.find(cost[i])->second;
    int a = u.find(cost[j])->second;

}

int main(int argc, const char * argv[]) {
    vector<int> x = {2 ,2 ,4 ,3};
    whatFlavors(x,4);
    return 0;
}
