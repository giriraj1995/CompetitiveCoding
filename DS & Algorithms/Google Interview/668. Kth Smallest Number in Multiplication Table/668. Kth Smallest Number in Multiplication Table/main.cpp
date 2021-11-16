//
//  main.cpp
//  668. Kth Smallest Number in Multiplication Table
//
//  Created by Giriraj Saigal on 16/11/21.
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

int solve(int i, int j, int m, int n, int k) {
        
        if(i == m)
            return i * (j + k - 1);
        
        int ni = i+1;
        int nj = j+1;
        int cmp = ni*nj;
        
        k--;
        
        int t = j+1;
        int low = min(m,n);
    int prev = -1;
    
        while(true) {
            
            while(k > 0 && t <= n && t*i < cmp) {
                if(t <= low) {
                    k--;
                }
                
                if(k == 1)
                    return (t * i);
                
                k--;
                
                if(k == 1)
                    return (t * i);
                
                prev = t*i;
                t++;
            }
            
            if(k <= 0)
                return t*i;
                
            if(t > n){
                t = nj;
                i++;
                j++;
                
                if(i == m) {
                    return i * (t + k - 1);
                }
                
                ni = i+1;
                nj = j+1;
                cmp = ni*nj;
                continue;
            }
            
            cmp = (nj+1) * ni;
            
            if(ni != nj && nj <= m && ni <= n){
                k--;
            }
            
            if(k == 1) {
                return min(prev, cmp);
            }
            
            k--;
            
            if(k == 1) {
                return min(prev, cmp);
            }
            
            nj++;
        }
        
        return -1;
    }
    
    int findKthNumber(int m, int n, int k) {
        int i = 1;
        int j = 1;
        
        if(k == 1)
            return 1;
        
        if(m > n)
            return solve(i, j, n, m, k);
            
        return solve(i,j,m,n,k);
    }

int main(int argc, const char * argv[]) {
    cout << findKthNumber(10, 6, 36) << endl;
    return 0;
}
