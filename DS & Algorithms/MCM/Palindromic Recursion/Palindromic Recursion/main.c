#include <stdio.h>
#include "string.h"
#include "limits.h"
#include "stdbool.h"

int t[1002][1002];
int calls = 0;
bool is_palindrome(char *str, int i, int j)
{
    while(i <= j){
        if(str[i++] != str[j--])
            return false;
    }
    return true;
}

int mini(int i, int j){return i>j?j:i;}

int mcm_pal(char *a, int i, int j)
{
    calls++;

    if(t[i][j] != -1)
        return t[i][j];
    
    if(i >= j || is_palindrome(a, i, j))
    {
        return 0;
    }
    
    
    int temp; int k;
    int temp1;
    int temp2;
    int min = INT_MAX;
    for(k = i; k < j; k++)
    {
        if(t[i][k] != -1){
            temp1 = t[i][k];
        } else {
            t[i][k] = temp1 = mcm_pal(a, i, k);
        }
        
        if(t[k+1][j] != -1){
            temp2 = t[k+1][j];
        } else {
            t[k+1][j] = temp2 = mcm_pal(a, k+1, j);
        }
        
        temp = temp1 + temp2 + 1;
        min = mini(min, temp);
    }
    
    return t[i][j] = min;
}


int main(int argc, const char * argv[]) {
    char *str = "giriraj";
    int n = 0;
    
    for(int i = 0; i<1002 ; i++)
    {
        for(int j = 0 ; j<1002 ; j++)
        {
            t[i][j] = -1;
        }
    }
    
    for(int i = 0; str[i] != '\0'; i++)
        n++;
    
    printf("No of Partitions to make the string as palindrome: %d\n", mcm_pal(str, 0, n-1));
    printf("Calls: %d\n", calls);

    return 0;
}
