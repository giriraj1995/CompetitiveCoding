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
    
//    show(n, t);
    
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
    
//    show(n, t);

    
//    int x = n;
//    int y = n;
//    int d = 0;
//    char p[] = "";
//
//    while(x>0 && y>0){
//        if(a[x-1] == b[y-1])
//        {
//            p[d] = a[x-1];
//            d++;
//            x--;
//            y--;
//        }
//        else{
//            if(t[x][y-1] > t[x-1][y])
//            {
//                y--;
//            }
//            else
//                x--;
//        }
//    }
//
//    for (int o = 0; o<t[n][n]; o++) {
//        printf("%c", p[o]);
//    }
//
//    printf("\n");
    
    
    return t[n][n];
}

int main(int argc, const char * argv[]) {
    char *str1 = "agbcba";
    int n=0;
    
    for(int i=0; str1[i]!='\0'; i++)
        n++;
    
    char *str2;
    
    str2 = (char*)malloc(n*sizeof(char));
    
    for(int i=0; i<n; i++)
        str2[i] = str1[n-1-i];
    
    str2[n] = '\0';
    
    printf("Lenght of Longest Palindromic Subsequence : %d\n", lcs(str1, str2, n));
    return 0;
}
