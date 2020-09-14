//
//  main.c
//  Evaluate Expression to true
// Find number of ways for the expression to be true
//
//  Created by Giriraj Saigal on 08/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>
#include "stdbool.h"
#include "limits.h"

int evaluate_exp(char *str, int i, int j)
{
    if(i == j-2)
    {
        if(str[i+1] == '^'){
            if((str[i] == 't' || str[i] == 'T') && (str[j] == 'f' || str[j] == 'F')){
                return 1;
            } else if((str[i] == 'f' || str[i] == 'F') && (str[j] == 't' || str[j] == 'T')){
                return 1;
            } else {
                return 0;
            }
        }else if(str[i+1] == '&'){
            if((str[i] == 't' || str[i] == 'T') && (str[j] == 't' || str[j] == 'T')){
                return 1;
            } else {
                return 0;
            }
        }else if(str[i+1] == '|'){
            if((str[i] == 't' || str[i] == 'T') || (str[j] == 't' || str[j] == 'T')){
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

int mcm_true(char *str, int i, int j)
{
    if(i > j)
    {
        return 0;
    }
    
    if(i == j)
    {
        if(str[i] == 't' || str[i] == 'T')
            return 1;
        
        return 0;
    }
    
    if((j-i+1)%2 == 0)
    {
        return 0;
    }
    
    if(i == j-2)
    {
        return evaluate_exp(str, i, j);
    }
    
    int k;
    int left = 0;
    int right = 0;
    int max = INT_MIN;
    int temp = 0;
    char l[] = "   ";
    
    for(k = i+1; k <= j-1; k = k+2)
    {
        left = mcm_true(str, i, k-1);
        if(left > 0)
        {
            l[0] = 'T';
        } else {
            l[0] = 'F';
        }
        l[1] = str[k];
        right = mcm_true(str, k+1, j);
        if(right > 0)
        {
            l[2] = 'T';
        } else {
            l[2] = 'F';
        }
        
        l[3] = '\0';
        
        if(evaluate_exp(l, 0, 2))
        {
            temp += 1;
        }
        else
            temp = 0;
        
        if(temp > max)
            max = temp;
    }
    
    return max;
}

int main(int argc, const char * argv[]) {
    char *str = "T|F&T^F";
    
    int n = 0;
    
//    for(int i = 0; i<1002 ; i++)
//    {
//        for(int j = 0 ; j<1002 ; j++)
//        {
//            t[i][j] = -1;
//        }
//    }
    
    for(int i = 0; str[i] != '\0'; i++)
        n++;
    
    
    printf("no of ways Evaluate = %d\n", mcm_true(str, 0, n-1));
    return 0;
}
