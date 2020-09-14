#include <stdio.h>
#include <limits.h>

int mcm(int arr[], int i, int j)
{
    if(i >= j)
        return 0;
    
    int temp;
    int min = INT_MAX;
    for(int k = i; k<j;k++)
    {
        temp = mcm(arr,i,k) + mcm(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        if(temp < min)
            min = temp;
    }
    
    return min;
}

int main(int argc, const char * argv[]) {
    int arr[] = {2,5,3,4};
    int n = 4;
    
//    2,5
//    2*5*3 = 30 + 2*3*4 = 54
//    5,3
//    5*3*4 = 60 + 2*5*4 = 100
//    3,4
    
    printf("Min cost Matrix : %d\n", mcm(arr,1,n-1));
    return 0;
}
