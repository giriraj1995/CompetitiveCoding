#include <stdio.h>
#include "limits.h"

int t[1002][1002];
int calls = 0;

int mcm(int arr[], int i, int j)
{
    calls++;
    if(i >= j)
        return 0;
    
    if(t[i][j] != -1)
        return t[i][j];
    
    int k;
    int min = INT_MAX;
    int temp;
    
    for (k = i; k<j; k++) {
        
        temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        
        if(min > temp)
            min = temp;
    }
    return t[i][j] = min;
}

int main(int argc, const char * argv[]) {
    int arr[] = {2,5,3,4,6,8,3,9,5};
    int n = 9;
    
    for(int i = 0; i<1002 ; i++)
    {
        for(int j = 0 ; j<1002 ; j++)
        {
            t[i][j] = -1;
        }
    }
    
    printf("Min cost matrix : %d\n", mcm(arr, 1,n-1));
    printf("Calls : %d\n", calls);

    return 0;
}
