//
//  main.cpp
//  Turvo 1
//
//  Created by Giriraj Saigal on 25/10/20.
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

//bool isSafe(int v, vector<int> output, int x) {
//
//    if(output.size() == 0)
//        return true;
//    else {
//        if(output[output.size()-1] == v) {
//            if(v == x) {
//                return true;
//            }else
//                return false;
//        }else{
//            return true;
//        }
//    }
//}
//
//bool solve(vector<int> input, vector<int> &output, int n, int x, vector<vector<int>> &ans) {
//
//    if(n == 0)
//    {
//        ans.push_back(output);
//        return true;
//    }
//
//    for(int i = 0; i < input.size(); i++) {
//
//        if(isSafe(input[i], output, x)) {
//            output.push_back(input[i]);
//            solve(input, output, n-1, x, ans);
//            output.pop_back();
//        }
//
//    }
//    return false;
//}
//
//int solution (int N, int K, int X) {
//   // Write your code here
//    if (N == 0) {
//        return 1;
//    }
//
//    vector<int> input;
//    vector<int> output;
//    vector<vector<int>> ans;
//
//    for(int i = 1; i <= K; i++)
//        input.push_back(i);
//
//    solve(input, output, N, X, ans);
//
//    return ans.size();
//}

int solve(int i, vector<int> A, vector<int> &visited) {

   if(i == A.size()-1 || i == A.size()-2) {
      return A[i];
   }

   int k = INT_MAX;
   if(i - 1 >= 0 && visited[i-1] == 0){
      visited[i] = 1;
      k = min(k, solve(i-1, A, visited));
      visited[i] = 0;
   }

   if(i + 2 < A.size() && visited[i+2] == 0){
      visited[i] = 1;
      k = min(k, solve(i+2, A, visited));
      visited[i] = 0;
   }

   return A[i] + k;
}

int Optimum_jump (int N, vector<int> A) {

   if (N == 0)
      return 0;

   vector<int> visited(A.size(), 0);

   return solve(0, A, visited);
}

int main(int argc, const char * argv[]) {
    cout<<Optimum_jump(5, {1,2,3,4,100});
    return 0;
}
