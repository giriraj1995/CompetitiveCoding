//
//  main.cpp
//  Find continius array with sum = 0
//
//  Created by Giriraj Saigal on 15/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> lszero(vector<int> &A) {
    
    map<int, int> u;
    
    int sum = 0;
    int start = 0;
    int end = -1;
    int size = INT_MIN;
    
    vector<int> sol;
    
    for(int i = 0; i < A.size(); i++){
        
        sum += A[i];
        
        if(sum == 0){
            start = 0;
            end = i;
            size = i + 1;
        }
        
        if(u.find(sum) == u.end()){
            u.insert(make_pair(sum, i));
        }else{
            int temp = u[sum];
            int s = i - temp;
            if(s > size){
                start = temp+1;
                end = i;
                size = s;
            }
        }
        
    }
    
    for(int i = start; i <= end; i++){
        sol.push_back(A[i]);
    }
    
    return sol;
    
}

int main(int argc, const char * argv[]) {
    vector<int> x = {-19, 8, 2, -8, 19, 5, -2, -23};
    lszero(x);
    return 0;
}
