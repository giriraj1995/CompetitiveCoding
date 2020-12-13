//
//  main.cpp
//  Boolean Matrix
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


void make1row(int i, vector<vector<int> > &matrix) {
    for(int j = 0; j < matrix[0].size(); j++)
        matrix[i][j] = 1;
}

void make1col(int j, vector<vector<int> > &matrix) {
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][j] = 1;
}


void booleanMatrix(vector<vector<int> > &matrix)
   {
      
   int n = matrix.size();

   if(n == 0)
       return;
   
   int m = matrix[0].size();
   
   if(m == 0)
       return;
       
   bool col = false;
   bool row = false;
   
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
           if(i == 0 && matrix[i][j] == 1)
               row = true;
               
           if(j == 0 && matrix[i][j] == 1)
               col = true;
           
           if(matrix[i][j] == 1)
           {
               matrix[i][0] = 1;
               matrix[0][j] = 1;
           }
       }
   }
   
   for(int i = 1; i < n; i++) {
       for(int j = 1; j < m; j++) {
           if(matrix[i][0] == 1 || matrix[0][j] == 1)
               matrix[i][j] = 1;
       }
   }

   if(row) {
       for(int j = 0; j < m; j++)
           matrix[0][j] = 1;
   }
   
   if(col) {
       for(int i = 0; i < n; i++)
           matrix[i][0] = 1;
   }
   return;
   }

int main(int argc, const char * argv[]) {
    vector<vector<int>> m = {{ 1, 0, 0},
    { 1, 0, 0},
    { 1, 0, 0},
        { 0, 0, 0}};
    booleanMatrix(m);
    return 0;
}
