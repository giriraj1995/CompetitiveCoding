//
//  main.c
//  A - > B
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

char* lcs_print(char str1[], int m, char str2[], int n)
{
    int t[m+1][n+1];
    
    int i=0,j=0;
    
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
    
//    show(m,  n, t);
    
    for(i=1; i<= m; i++)
    {
        for (j=1;j<=n; j++) {
            if(str1[i-1] == str2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
       // show(m,  n, t);
    }
    
    char l[] = "";
    int k = 0;
    int q = m;
    int x = n;
    while(q != 0 && x != 0) {
        if(str1[q-1] == str2[x-1]){
            l[k] = str1[q-1];
            k = k+1;
            q = q-1;
            x = x-1;
        }
        else
        {
            if(t[q-1][x] > t[q][x-1])
            {
                q--;
            }
            else
            {
                x--;
            }
        }
    }
    l[k] = '\0';
    char *p;
    p = (char *)malloc(k * sizeof(char));
    for(int c = 0; c<k; c++)
    {
        p[c] = l[k-1-c];
    }
    p[k] = '\0';
    return p;
}

int main(int argc, const char * argv[]) {
    char *str1 = "heapsagiriigal";
    char *str2 = "xyzpeasaigal";
    int n=0,m=0;
    
    for(int i = 0; str1[i] != '\0' ; i++)
        n++;
    for(int i = 0; str2[i] != '\0' ; i++)
        m++;
    
    int result = lcs(str1, str2, n,m);
    int x,y;
    
    printf("LCS : %d\n", result);
    printf("Print LCS : %s\n", lcs_print(str1, n, str2, m));
    printf("Min no of deletions : %d\n", x = n - result);
    printf("Min no of insertions : %d\n", y = m - result);
    printf("Insertion + Deletion : %d\n", x+y);
    return 0;
}

