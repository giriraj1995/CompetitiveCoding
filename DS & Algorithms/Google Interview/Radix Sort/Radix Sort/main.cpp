//
//  main.cpp
//  Radix Sort
//
//  Created by Giriraj Saigal on 31/10/21.
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

int getMax(vector<int> x) {
    int ans = x[0];
    
    for(int i = 1; i < x.size(); i++) {
        ans = max(ans, x[i]);
    }
    
    return ans;
}

// O(n)
void sortExp(vector<int> &x, int exp) {
    int n = (int)x.size();
    
    vector<int> count(n, 0);
    vector<int> output(n, 0);
    
    for(int i = 0; i < n; i++) {
        count[(x[i]/exp)%10]++;
    }
    
    for(int i = 1; i < n; i++){
        count[i] += count[i-1];
    }
    
    for(int i = n-1; i >= 0; i--){
        output[count[(x[i]/exp)%10]-1] = x[i];
        count[(x[i]/exp)%10]--;
    }
              
    x = output;
}

// d -> digits of max no
//
void radixSort(vector<int> &x) {
    //O(n)
    int m = getMax(x);
    int exp = 1;
    
    //O(d)
    while(m/exp > 0) {
        //O(n)
        sortExp(x, exp);
        exp *= 10;
    }
}


int main(int argc, const char * argv[]) {
    vector<int> x = {12,234,12,80,44,43,1,5,9,44,94,538,26,30,90,45};
    radixSort(x);
    for(int i : x) cout << i << " ";
    cout << endl;
    return 0;
}
