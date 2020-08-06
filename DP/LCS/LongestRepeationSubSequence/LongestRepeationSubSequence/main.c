//
//  main.c
//  LongestRepeationSubSequence
//
//  Created by Giriraj Saigal on 06/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>
#include "string.h"

int max(int i, int j)
{
    return i>j?i:j;
}

int lcs(char *a, char *b, int n)
{
    int t[n+1][n+1];
    int i=0,j=0;
    
    for(i = 0; i<= n; i++)
        for(j = 0; j<= n; j++)
            if(i ==0 || j == 0)
                t[i][j] = 0;
    
    for(i = 1; i<= n; i++)
        for(j = 1; j<= n; j++)
            if(a[i-1] == b[j-1] && i!=j)
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
    
    return t[n][n];
}

int main(int argc, const char * argv[]) {
    char *str = "AABEBCDD";
    int n = 8;
    printf("Lenght of longest Repeating SubSequence : %d\n", lcs(str,str,n));
    return 0;
}
