#include <iostream>
#include <vector>
using namespace std;

int ceil(vector<int> A, int i ,int j, int key){
    int res = -1;
    while(i <= j){
        int m = i + (j-i)/2;
        if(key == A[m]){
            return key;
        } else {
            if(key < A[m])
            {
                j = m - 1;
                res = A[m];
            } else {
                i = m + 1;
            }
        }
    }
    return res;
}

int floor(vector<int> A, int i ,int j, int key){
    int res = -1;
    while(i <= j){
        int m = i + (j-i)/2;
        if(key == A[m]){
            return key;
        } else {
            if(key < A[m])
            {
                j = m - 1;
            } else {
                res = A[m];
                i = m + 1;
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {1,3,5,7,10,15};
    int key = 13;
    
    int c = ceil(A, 0, (int)A.size()-1, key);
    int f = floor(A, 0, (int)A.size()-1, key);
    
    if (c == f)
        cout<<c<<endl;
    else
        cout<<min(abs(key-c),abs(key-f))<<endl;
    return 0;
}
