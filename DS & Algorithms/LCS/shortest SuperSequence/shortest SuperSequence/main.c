//
//  main.c
//  shortest SuperSequence
//
//  Created by Giriraj Saigal on 04/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>

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

int max(int i, int j){return i>j?i:j;}

int lcs(char *str1, char *str2, int n, int m)
{
    int i,j;
    int t[n+1][m+1];
    for(i = 0 ; i<= n ; i++)
        for (j=0; j<=m; j++) {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else
                t[i][j] = -1;
        }
    
    //show(n,m,t);
    
    for(i = 1; i<=n ; i++)
        for (j = 1; j<=m; j++) {
            if(str1[i-1] == str2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    
    return t[n][m];
}

int main(int argc, const char * argv[]) {
    char *str1 = "AGGTAB";
    char *str2 = "GXTXAYB";
    int n=0,m=0;
    
    for(int i = 0; str1[i] != '\0' ; i++)
        n++;
    for(int i = 0; str2[i] != '\0' ; i++)
        m++;
    
    printf("Lenght of shortest SuperSequence : %d\n", m+n-lcs(str1, str2, n,m));
    return 0;
}
