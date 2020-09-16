//
//  main.cpp
//  IsValidSudoko
//
//  Created by Giriraj Saigal on 16/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int AllOK(vector<string> x){
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            if(x[i][j] == '.')
                return 0;
        }
    }
    return 1;
}

int isSafe(int x, int y, int k, vector<string> A){
    int i,j;
    
    i = x;
    j = 0;
    
    while(j < 9){
        if(A[i][j] == (char)(k+'0'))
            return 0;
            
        j++;
    }
    
    i = 0;
    j = y;
    
    while(i < 9){
        if(A[i][j] == (char)(k+'0'))
            return 0;
        i++;
    }
    
    int bx;
    int by;
    
    
    if(x >= 0 && x <= 2)
        bx = 0;
    else if(x >= 3 && x <= 5)
        bx = 1;
    else
        bx = 2;
        
    if(y >= 0 && y <= 2)
        by = 0;
    else if(y >= 3 && y <= 5)
        by = 1;
    else
        by = 2;
        
    for(int p = bx*3; p != (bx+1)*3; p++){
        for(int q = by*3; q != (by+1)*3; q++){
            if(A[p][q] == (char)(k + '0'))
                return 0;
        }
    }
    
    return 1;
        
}

void print(vector<string> x){
    
    for(string i : x){
        cout<<i<<endl;
    }
    
    cout<<endl;
    
}

int solve(vector<string> &x){
    
    if(AllOK(x)){
        return 1;
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            
            if(x[i][j] != '.'){
                continue;
            }else{
                for(int k = 1; k <= 9; k++){
                    if(x[i][j] == '.' && isSafe(i,j,k,x)){
                        x[i][j] = (char)(k + '0');
                        print(x);
                        if(solve(x)){
                            return 1;
                        }else
                            x[i][j] = '.';
                    }
                }
                if(x[i][j] == '.')
                    return 0;
            }
        }
    }
    
    return 0;
    
    
}

int isValidSudoku(const vector<string> &A) {
    
    vector<string> x = A;
    int ans = solve(x);
    print(x);
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<isValidSudoku({"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"});
    return 0;
}
