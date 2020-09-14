#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int> A, int i, int j){
    int n = (int)A.size();
    int start = i;
    int end = j;
    while(i <= j){
        int mid = i + (j-i)/2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if(A[mid] <= A[prev] && A[mid] <= A[next]){
            return mid;
        } else {
            if(A[mid] >= A[start])
            {
                i = mid + 1;
            } else if(A[mid] <= A[end])
            {
                j = mid - 1;
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    vector<int> A = {6,7,8,9,5};
    cout<<"No of times array is sorted: "<<A.size() - bs(A, 0, (int)A.size()-1)<<endl;
    return 0;
}
