//
//  main.c
//  LCS_topdown
//
//  Created by Giriraj Saigal on 04/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int max(int i, int j){return i>j?i:j;}

void show(int m, int n, int t[m+1][n+1])
{
    int i,j;
    for(i=0; i<= m; i++)
    {
        for (j=0;j<=n; j++) {
                printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int lcs(char str1[], int m, char str2[], int n)
{
    int t[m+1][n+1];
    
    int i,j;
    
    for(i=0; i<= m; i++)
    {
        for (j=0;j<=n; j++) {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else
                t[i][j] = -1;
        }
    }
    
    show(m,  n, t);
    
    for(i=1; i<= m; i++)
    {
        for (j=1;j<=n; j++) {
            if(str1[i-1] == str2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
        show(m,  n, t);

    }
    return t[m][n];
}

int main(int argc, const char * argv[]) {
    char A[] = "abcdefg";
    int m = 7;
    
    char B[] = "cef";
    int n = 3;
    
    printf("LCS:topdown = %d\n", lcs(A,m,B,n));
    return 0;
}
