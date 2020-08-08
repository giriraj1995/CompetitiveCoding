//
//  main.c
//
//
//  Created by Giriraj Saigal on 08/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>
#include "limits.h"
#include "stdbool.h"

int t[1002][1002];
int f[1002][1002];
int calls = 0;

int mcm_TF(char *str, bool isTrue, int i, int j)
{
    calls++;
        
    if(i > j)
        return false;
    
    if(isTrue){
        if(t[i][j] != -1)
            return t[i][j];
    } else {
        if(f[i][j] != -1)
            return f[i][j];
    }
    
    if(i == j){
        if(isTrue == true)
        {
            return str[i] == 'T';
        } else {
            return str[i] == 'F';
        }
    }
    
    int k;
    
    int lt;
    int lf;
    int rt;
    int rf;
    int ans = 0 ;
    
    for(k = i+1; k <= j-1; k++)
    {
        if(t[i][k-1] != -1)
            lt = t[i][k-1];
        else
            t[i][k-1] = lt = mcm_TF(str, true, i, k-1);
        
        if(f[i][k-1] != -1)
            lf = f[i][k-1];
        else
            f[i][k-1] = lf = mcm_TF(str, false, i, k-1);
        
        if(t[k+1][j] != -1)
            rt = t[k+1][j];
        else
            t[k+1][j] = rt = mcm_TF(str, true, k+1, j);
        
        if(f[k+1][j] != -1)
            rf = f[k+1][j];
        else
            f[k+1][j] = rf = mcm_TF(str, false, k+1, j);

        if(str[k] == '&'){
            if(isTrue)
            {
                ans += lt * rt;
            } else {
                ans += lt * rf
                     + lf * rt
                     + lf * rf;
            }
        }
        
        if(str[k] == '|'){
            if(isTrue)
            {
                ans += lt * rt
                     + lt * rf
                     + lf * rt;
            } else {
                ans += lf * rf;
            }
        }
        
        
        if(str[k] == '^'){
            if(isTrue)
            {
                ans += lt * rf
                     + lf * rt;
            } else {
                ans += lt * rt
                     + lf * rf;
            }
        }
    }
    
    if(isTrue){
        return t[i][j] = ans;
    } else {
        return f[i][j] = ans;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    char *str = "T|F&T^F";
    int n = 7;
    
    for(int i = 0; i<1002 ; i++)
    {
        for(int j = 0 ; j<1002 ; j++)
        {
            t[i][j] = -1;
        }
    }
    
    for(int i = 0; i<1002 ; i++)
    {
        for(int j = 0 ; j<1002 ; j++)
        {
            f[i][j] = -1;
        }
    }
    
    printf("No of ways for the expression to be True : %d\n",
           mcm_TF(str, true, 0, n-1));
    
    printf("Calls : %d\n", calls);
    
    return 0;
}
