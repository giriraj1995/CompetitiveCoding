#include <iostream>
#include <vector>
using namespace std;

int bs(vector<int> A, int i ,int j, int k){
    int res = 0;
    while(i <= j){
        int m = i + (j-i)/2;
        if(A[m] == k)
            return k;
        else{
            if(k < A[m]){
                j = m - 1;
            }
            else{
                res = A[m];
                i = m + 1;
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {1,2,3,4,8,10,10,12,19};
    int k = 0;
    int ans = bs(A, 0, (int)A.size()-1, k);
    
    cout<<"Floor Element will be: "<<ans<<endl;
    
    return 0;
}
