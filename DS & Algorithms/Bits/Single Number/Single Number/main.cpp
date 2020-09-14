#include <iostream>
#include <vector>
using namespace std;

int singleNumber(const vector<int> &A) {
int ans = 0;
for(int i=0;i<A.size();i++)
    ans = ans^A[i];
return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {5, 6, 7, 8, 9, 0, 0, 9, 8, 7, 6, 5, 4,4,87};
    cout<<singleNumber(x)<<endl;
    return 0;
}
