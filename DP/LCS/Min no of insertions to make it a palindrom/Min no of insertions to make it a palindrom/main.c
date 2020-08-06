#include <stdio.h>
#include "limits.h"

void show(int n, int t[n+1][n+1])
{
    int i,j;
    for(i = 0; i<= n ; i++)
    {
        for (j=0;j<=n; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int max(int i, int j){return i>j?i:j;}

int lcs(char *a, char *b, int n){
    
    int t[n+1][n+1];
        
    int i,j;
    
    for(i = 0; i<= n ; i++)
    {
        for (j=0;j<=n; j++) {
            if(i ==0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = -1;
        }
    }
        
    for(i = 1; i<= n ; i++)
    {
        for (j=1;j<=n; j++) {
            if(a[i-1] == b[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    
    char l[] = "";
    int k = 0;
    int q = n;
    int x = n;
    while(q != 0 && x != 0) {
        if(a[q-1] == b[x-1]){
            l[k] = a[q-1];
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
    
    printf("%s\n", p);
    
    return t[n][n];
}

int main(int argc, const char * argv[]) {
    char *str1 = "+-*><>*-++*";
    char *str2 = "";
    int n=0;
    
    for(int i=0; str1[i]!='\0'; i++)
        n++;
    
    str2 = (char*)malloc(n*sizeof(char));
    
    for(int i=0; i<n; i++)
        str2[i] = str1[n-1-i];
    
    str2[n] = '\0';
    
    int r = lcs(str1, str2, n);
    
    printf("Min no of Insertions to make it a Palindrome : %d\n", n-r);

    return 0;
}


