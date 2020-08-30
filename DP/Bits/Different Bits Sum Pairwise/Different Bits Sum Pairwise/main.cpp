//
//  main.cpp
//  Different Bits Sum Pairwise
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int cntBits(vector<int> &A) {
    
    long long int ans = 0;
    long long int mod = 1000000007;
    
    for(int i = 0; i < 32 ; i++){
        
        long long int a=0,b=0;
        int j = 0;
        unsigned int x = 1<<i;
        
        while(j < A.size()){
            
            if(A[i] & x)
                a++;
            else
                b++;
            
            j++;
        }

        ans = (ans%mod + (2*(a%mod)*(b%mod)))%mod;
    }
    
    return ans%mod;
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1,3,5};
    cntBits(x);
    return 0;
}
