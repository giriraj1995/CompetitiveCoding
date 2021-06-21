//
//  main.cpp
//  Smallest sequence with given Primes
//
//  Created by Giriraj Saigal on 21/06/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

vector<int> tech2(int A, int B, int C, int D) {
    if(D == 0)
        return {};
    
    vector<int> x = {A,B,C};
    sort(x.begin(), x.end());
    vector<int> ans(D);
    ans[0] = x[0];
    for(int i = 1; i < D; i++) {
        ans[i] = INT_MAX;
        for(int j = 0; j < i; j++) {
            for(int g = 0; g < 3; g++) {
                if(ans[j] * x[g] > ans[i-1] && x[g] > ans[i-1])
                {
                    ans[i] = min(ans[i], min(ans[j] * x[g], x[g]));
                }else if(ans[j] * x[g] > ans[i-1]){
                    ans[i] = min(ans[i], ans[j]*x[g]);
                }
            }
        }
    }
    return ans;
}

vector<int> solve(int A, int B, int C, int D) {
    set<int>s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    
    vector<int> ans;
    if(D == 0)
        return ans;
    
    while(ans.size() != D) {
        int a = *(s.begin());
        s.erase(s.begin());
        ans.push_back(a);
        s.insert(a*A);
        s.insert(a*B);
        s.insert(a*C);
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    solve(3,11,7,50);
    return 0;
}
