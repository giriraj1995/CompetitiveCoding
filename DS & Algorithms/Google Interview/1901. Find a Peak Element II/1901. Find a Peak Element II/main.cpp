//
//  main.cpp
//  1901. Find a Peak Element II
//
//  Created by Giriraj Saigal on 25/11/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int find(vector<vector<int>>& mat, int row, int i, int j) {
        if(i > j)
            return -1;
        
        int m = i + (j-i)/2;
        
        if(m == 0) {
            if(mat[row][m] > mat[row][m+1]){
                if(row == 0 && row == mat.size()-1) {
                    return m;
                }else if(row == 0) {
                    if(mat[row][m] > mat[row+1][m])
                        return m;
                    else
                        return find(mat, row, m+1, j);
                }else if(row == mat.size()-1) {
                    if(mat[row][m] > mat[row-1][m])
                        return m;
                    else
                        return find(mat, row, m+1, j);
                }else{
                    if(mat[row][m] > mat[row-1][m] && mat[row][m] > mat[row+1][m])
                        return m;
                    else{
                        return find(mat, row, m+1, j);
                    }
                }
            }
            else
                return find(mat, row, m+1, j);
        }
        
        else if(m == mat[row].size()-1){
            if(mat[row][m] > mat[row][m-1]){
                if(row == 0 && row == mat.size()-1) {
                    return m;
                }else if(row == 0) {
                    if(mat[row][m] > mat[row+1][m])
                        return m;
                    else
                        return -1;
                }else if(row == mat.size()-1) {
                    if(mat[row][m] > mat[row-1][m])
                        return m;
                    else
                        return -1;
                }else{
                    if(mat[row][m] > mat[row-1][m] && mat[row][m] > mat[row+1][m])
                        return m;
                    else{
                        return -1;
                    }
                }
            }
            else
                return -1;
        }
        
        else{
            if(mat[row][m] > mat[row][m-1] && mat[row][m] > mat[row][m+1]){
                if(row == 0 && row == mat.size()-1) {
                    return m;
                }else if(row == 0) {
                    if(mat[row][m] > mat[row+1][m])
                        return m;
                    else{
                        int left = find(mat, row, i, m-1);
                        if(left != -1)
                            return left;
                        int right = find(mat, row, m+1, j);
                        return right;
                    }
                }else if(row == mat.size()-1) {
                    if(mat[row][m] > mat[row-1][m])
                        return m;
                    else{
                        int left = find(mat, row, i, m-1);
                        if(left != -1)
                            return left;
                        int right = find(mat, row, m+1, j);
                        return right;
                    }
                }else{
                    if(mat[row][m] > mat[row-1][m] && mat[row][m] > mat[row+1][m])
                        return m;
                    else{
                        int left = find(mat, row, i, m-1);
                        if(left != -1)
                            return left;
                        int right = find(mat, row, m+1, j);
                        return right;
                    }
                }
            }else{
                int left = find(mat, row, i, m-1);
                if(left != -1)
                    return left;
                int right = find(mat, row, m+1, j);
                return right;
            }
        }
    }
    
    vector<int> transpose(vector<vector<int>>& mat) {
        vector<int> x;
        for(int i = 0; i < mat.size(); i++)
            x.push_back(mat[i][0]);
        return x;
    }
    
    vector<int> solve(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> vec;
        bool row = false;
        bool col = false;
        
        if(n == 1){
            row = true;
            vec = mat[0];
        }
        
        if(m == 1){
            col = true;
            vec = transpose(mat);
        }
        
        vec.push_back(-1);
        
        int i = 0;
        
        if(vec[i] > vec[i+1]) {
            if(row)
                return {0,i};
            else
                return {i,0};
        }
        
        for(int i = 1; i < vec.size()-1; i++){
            if(vec[i] > vec[i-1] && vec[i] > vec[i+1])
                if(row)
                    return {0,i};
                else
                    return {i,0};
        }
        
        return {-1,-1};
    }
    
    vector<int> findPeakGrid(vector<vector<int>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(n == 1 && m == 1)
            return {0,0};
        
        if(n == 1 || m == 1)
            return solve(mat);
        
        for(int i = 0; i < mat.size(); i++) {
            int j = find(mat, i, 0, mat[i].size()-1);
            if(j != -1)
                return {i,j};
        }
        return {-1,-1};
    }

int main(int argc, const char * argv[]) {
    findPeakGrid({{10,50,40,30,20},{1,500,2,3,4}});
    return 0;
}
