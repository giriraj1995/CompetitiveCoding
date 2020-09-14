#include <iostream>
#include <vector>
using namespace std;
int peak(vector<int> A, int i, int j)
{
    int start = i;
    int end = j;
    while(i <= j){
        int m = i + (j-i)/2;
        
        if(m-1 < start)
        {
            if(m+1 <= end)
                if(A[m] > A[m+1])
                    return A[m];
        }
        
        if(m+1 > end)
        {
            if(m-1 >= start)
                if(A[m] > A[m-1])
                    return A[m];
        }
        
        if(start <= m-1 && end >= m+1)
        {
            if(A[m] > A[m-1] && A[m] > A[m+1])
                return A[m];
            else
            {
                if(A[m] < A[m+1])
                    i = m+1;
                else if(A[m] < A[m-1])
                    j = m-1;
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    vector<int> x = {3,66,1,4,7,2,5,88,45,75,5};
    cout<<"Peak Element will be : "<<peak(x, 0, (int)x.size()-1);
    return 0;
}
