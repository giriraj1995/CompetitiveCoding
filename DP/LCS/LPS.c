#include <stdio.h>
#include "limits.h"


int lcs(char *a, char *b, int n){
    return 0;
}

int main(int argc, const char * argv[]) {
    char *str1 = "agbcba";
    int n=0;
    
    for(int i=0; str1[i]!='\0'; i++)
        n++;
    
    char str2[] = "";
    
    for(int i=0; i<n; i++)
        str2[i] = str1[n-1-i];
    
    str2[n] = '\0';
    
    printf("Lenght of Longest Palindromic Subsequence : %d\n", lcs(str1, str1, n));
    return 0;
}
