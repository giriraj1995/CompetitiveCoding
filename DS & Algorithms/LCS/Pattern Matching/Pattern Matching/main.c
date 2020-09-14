//
//  main.c
//  LongestRepeationSubSequence
//
//  Created by Giriraj Saigal on 06/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "stdbool.h"

int max(int i, int j)
{
    return i>j?i:j;
}
int min(int i, int j)
{
    return i>j?j:i;
}

bool lcs(char *a, char *b, int n,int m)
{
    int t[n+1][m+1];
    int i=0,j=0;
    
    for(i = 0; i<= n; i++)
        for(j = 0; j<= m; j++)
            if(i ==0 || j == 0)
                t[i][j] = 0;
    
    for(i = 1; i<= n; i++)
        for(j = 1; j<= m; j++)
            if(a[i-1] == b[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
    
    return t[n][m] == min(n,m);
}

int main(int argc, const char * argv[]) {
    char *str = "AABEBCDDXY";
    char *str2 = "ABCXY";
    int n = 10;
    int m = 5;
    printf("Pattern Matching between both strings : %d\n", lcs(str,str2,n,m));
    return 0;
}

