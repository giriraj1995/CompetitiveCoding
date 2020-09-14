#include <iostream>
#include <vector>
using namespace std;

int max_bitoni(vector<int> A, int i, int j)
{
    int start = i;
    int end = j;
    while(i <= j){
        int m = i + (j-i)/2;
        if(m > start && m < end)
        {
            if(A[m] > A[m+1] && A[m] > A[m-1])
            {
                return m;
            } else {
                if(A[m] > A[m+1])
                    j = m - 1;
                else
                    i = m + 1;
            }
        }
        
        if(m == start){
            if(A[m] > A[m+1])
                return start;
            else{
                return start +1;
            }
        }
        
        if(m == end){
            if(A[m] > A[m-1])
                return end;
            else{
                return end-1;
            }
        }
    }
    return 0;
}




int main(int argc, const char * argv[]) {
    
    vector<int> x = {1,2,3,4,5,6,7,8,9,10,2,1};
    int index = max_bitoni(x,0,(int)x.size()-1);
    //then BS on 0 - index;
    //then BS on decreasing on index +1 - size-1;
    return 0;
}


