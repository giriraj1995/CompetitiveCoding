#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> A,int index, int k){
    
    if(A.size() == 1)
        return A[0];
    
    
    int nindex = (index + k - 1)%A.size();
    A.erase(A.begin() + nindex);
    
    
    return solve(A, nindex, k);
}


int main(int argc, const char * argv[]) {
    int n = 100;
    int k = 7;
    
    vector<int> x(n,0);
    
    for(int i = 0; i < n ; i++){
        x[i] = i;
    }
    
    cout<<solve(x,0,k)+1<<endl;
    
    return 0;
}
