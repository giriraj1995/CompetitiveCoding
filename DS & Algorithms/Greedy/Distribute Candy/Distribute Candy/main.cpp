//
//  main.cpp
//  Distribute Candy
//
//  Created by Giriraj Saigal on 26/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int candy(vector<int> A) {
    
    int n = A.size();
    vector<int> ans(n,1);
    
    for(int i = 1; i < n; i++) {
        
        if(A[i-1] > A[i]){
            int k = i;
            
            while(k-1 >= 0 && A[k-1] > A[k] && !(ans[k-1] > ans[k])){
                ans[k-1] = ans[k]+1;
                k--;
            }
            
        }else if(A[i-1] < A[i] && !(ans[i-1] < ans[i])){
            ans[i] = ans[i-1] + 1;
        }
        
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum+= ans[i];
    }
    
    return sum;
}


int main(int argc, const char * argv[]) {
    cout<<candy({1,7,7,7,5,2,1,2,3,1,1,2,1});
    cout<<endl;
    return 0;
}
