//
//  main.cpp
//  4-sum
//
//  Created by Giriraj Saigal on 30/04/21.
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

vector<vector<int> > fourSum(vector<int> &A, int t) {
    sort(A.begin(), A.end());
    set<vector<int>> st;
    int n = A.size();
    
    for(int i = 0; i < n-3; i++) {
        for(int j = i+1; j < n-2; j++) {
            
            long long low = j+1;
            long long high = n-1;
            long long prev_sum = A[i] + A[j];
            
            while(low < high) {
                long long sum = prev_sum + (long long)A[low] + (long long)A[high];
                if(sum == t) {
                    st.insert({A[i], A[j], A[low], A[high]});
                    high--;
                }else if(sum < t) {
                    low++;
                }else if(sum > t) {
                    high--;
                }
            }
        }
    }
    
    vector<vector<int>> ans;
    for(auto k : st)
        ans.push_back(k);
        
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
