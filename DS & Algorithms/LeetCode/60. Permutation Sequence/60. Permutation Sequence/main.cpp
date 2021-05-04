//
//  main.cpp
//  60. Permutation Sequence
//
//  Created by Giriraj Saigal on 03/05/21.
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

string getPermutation(int n, int k) {
    vector<int> vec;
    for(int i = 1; i <= n; i++)
        vec.push_back(i);
    
    do{
        k--;
    }while(k && next_permutation(vec.begin(), vec.end()));
    
    string ans = "";
    
    for(int i = 0; i < n; i++)
        ans+=to_string(vec[i]);
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<getPermutation(4,9)<<endl;
    return 0;
}
