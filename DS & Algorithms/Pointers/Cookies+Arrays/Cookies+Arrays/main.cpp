//
//  main.cpp
//  Cookies+Arrays
//
//  Created by Giriraj Saigal on 16/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> insert(vector<int > x, int data){

    vector<int > ans;

    int i = 0;
    int j = 0;

    while(i < 1 && j < x.size()){

        if(data < x[j]){
            ans.push_back(data);
            i++;
        }else{
            ans.push_back(x[j]);
            j++;
        }
    }
    
    while(i < 1){
        ans.push_back(data);
        i++;
    }

    while(j < x.size())
    {
        ans.push_back(x[j]);
        j++;
    }
    

    return ans;
}

int cookies(int k, vector<int> A) {

    if(A.size() == 0 || A.size() == 1)
        return -1;

    sort(A.begin(), A.end());
    int moves = 0;

    while(A[0] < k){
        int p = A[0];
        int q = A[1];
        int r = p*1 + q*2;
        A.erase(A.begin());
        A.erase(A.begin());

        A = insert(A, r);

        if(A.size() < 2){
            return 0;
        }
        moves++;
    }

    return moves;
    
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1 ,2 ,3 ,9 ,10 ,12};
    cookies(7,x);
    return 0;
}
