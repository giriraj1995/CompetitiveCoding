#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#define N 9

void print(int sol[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            cout<<sol[i][j]<<" ";
            
        }
        cout<<endl;
    }
    cout<<endl;
}

bool hasValueinBlock(int blockX, int blockY, int v, int su[N][N]){
    
    for(int i = blockX*3; i != (blockX+1)*3; i++){
        
        for(int j = blockY*3; j != (blockY+1)*3; j++){
            
            if(su[i][j] == v)
                return false;
        }
        
    }
    return true;
}

bool isSafe(int x, int y, int su[N][N], int v){
    
    int i = 0;
    int j = y;
    while(i < N){
        
        if(su[i][j] == v)
            return false;
            
        i++;
    }
    
    i = x;
    j = 0;
    while(j < N){
        
        if(su[i][j] == v)
            return false;
            
        j++;
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
        
    if(!hasValueinBlock(bx,by,v, su))
        return false;
        
    
    return true;
}

bool allNonZero(int sol[N][N]){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            if(sol[i][j] == 0)
                return false;
            
        }
    }
    return true;
}

bool solve(int sol[N][N]){
    
    if(allNonZero(sol)){
        return 1;
    }
    
    for(int i = 0; i < N; i++){
        
        for(int j = 0; j < N; j++){
            
            if(sol[i][j] != 0)
                continue;
            for(int k = 1; k<=N; k++){
            if(sol[i][j] == 0 && isSafe(i,j,sol,k)){
                
                sol[i][j] = k;
                print(sol);
                if(solve(sol)){
                    return 1;
                }
                else
                    sol[i][j] = 0;
            }
            }
            
            if(sol[i][j] == 0)
                return 0;
        }
    }
    return 0;
}


int main() {
    
    int su[N][N];
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            cin>>su[i][j];
            
        }
    }
    
//    {
//        {3 ,0 ,6 ,5 ,0 ,8 ,4 ,0 ,0},
//        {5, 2, 0, 0, 0, 0, 0, 0, 0},
//        {0, 8, 7, 0, 0, 0, 0, 3, 1},
//        {0, 0, 3, 0, 1, 0, 0, 8, 0},
//        {9, 0, 0, 8, 6, 3, 0, 0, 5},
//        {0, 5, 0, 0, 9, 0, 6, 0, 0},
//        {1, 3, 0, 0, 0, 0, 2, 5, 0},
//        {0, 0, 0, 0, 0, 0, 0, 7, 4},
//        {0, 0, 5, 2, 0, 6, 3, 0, 0}
//    };
        
    bool ans = solve(su);
    
    if(ans == true)
    {
        print(su);
    }
    
    return 0;
}
