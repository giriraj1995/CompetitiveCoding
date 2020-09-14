//
//  main.c
//  Shortest Super Sequence
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

char* lcs(char str1[], int m, char str2[], int n)
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
    char A[] = "abcdokijuvgvghefg";
    char B[] = "akdjsbokijuvgvghvskjbvfbldjsvbaljvkbc";
    int m = 0,n = 0;
    
    for (int i = 0; A[i] != '\0'; i++) {
        m++;
    }
    for (int i = 0; B[i] != '\0'; i++) {
        n++;
    }
    
    printf("LCS:topdown = %s\n", lcs(A,m,B,n));
    return 0;
}

