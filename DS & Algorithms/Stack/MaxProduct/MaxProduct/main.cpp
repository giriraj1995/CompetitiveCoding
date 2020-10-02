//
//  main.cpp
//  MaxProduct
//
//  Created by Giriraj Saigal on 01/10/20.
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

vector<int> greaterLeft(vector<int> arr){

    vector<int> ans;
    stack<int> s;
    for(int i = 0; i < arr.size(); i++){

        if(s.empty()){
            ans.push_back(0);
        }else if(arr[i] < arr[s.top()]){
            ans.push_back(s.top()+1);
        }else if(arr[i] >= arr[s.top()]){
            while(!s.empty() && arr[i] >= arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(s.top()+1);
            }
        }
        s.push(i);
    }

    return ans;
}

vector<int> greaterRight(vector<int> arr){

    vector<int> ans;
    stack<int> s;
    for(int i = arr.size()-1; i >= 0; i--){

        if(s.empty()){
            ans.push_back(0);
        }else if(arr[i] < arr[s.top()]){
            ans.push_back(s.top()+1);
        }else if(arr[i] >= arr[s.top()]){
            while(!s.empty() && arr[i] >= arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(s.top()+1);
            }
        }
        s.push(i);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// Complete the solve function below.
int solve(vector<int> arr) {

    vector<int> left = greaterLeft(arr);
    vector<int> right = greaterRight(arr);
    int ans = 0;
    for(int i = 0; i < arr.size(); i++){
        ans = max(ans, left[i] * right[i]);
    }

    return ans;

}

int main(int argc, const char * argv[]) {
    solve({1,2});
    return 0;
}
