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
                return A[m];
            } else {
                if(A[m] > A[m+1])
                    j = m - 1;
                else
                    i = m + 1;
            }
        }
        
        if(m == start){
            if(A[m] > A[m+1])
                return A[m];
            else{
                return A[m+1];
            }
        }
        
        if(m == end){
            if(A[m] > A[m-1])
                return A[m];
            else{
                return A[m+1];
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    vector<int> x = {2,1};
    cout<<"Max Element will be : "<<max_bitoni(x, 0, (int)x.size()-1)<<endl;
    return 0;
}

