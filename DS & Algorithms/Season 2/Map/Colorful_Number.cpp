#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int colorful(int A) {
    set<long long> st;
    vector<int> x;
    while(A > 0) {
        x.push_back(A%10);
        A = A/10;
    }
    reverse(x.begin(), x.end());
    int n = x.size();
    for(int i = 0; i < n; i++) {
        long long p = 1;
        for(int j = i; j >= 0 ; j--) {
            p *= x[j];
            if(st.find(p) != st.end()) {
                return 0;
            }
            st.insert(p);
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    cout<<colorful(argc)<<endl;
    return 0;
}
