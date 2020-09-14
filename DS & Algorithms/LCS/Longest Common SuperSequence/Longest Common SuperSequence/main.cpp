//
//  main.cpp
//  Longest Common SuperSequence
//
//  Created by Giriraj Saigal on 11/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "string"
#include "vector"
#include <algorithm>
#include <functional>
#include <array>

using namespace std;

int max(int i, int j){return i>j?i:j;}

void show(int n, int m, int *t){
    
    for(int i = 0 ; i<= n; i++)
    {
        for(int j = 0; j<=m ; j++)
        {
            printf("%d\t",t[i*n+j]);
        }
        cout<<endl;
    }
    cout<<endl;
}

int solve(vector<string> &A) {
    
    int ans = 0;
    int x = 0;
    if(A.size() == 1){
        string a = A[0];
        return a.size();
    }
    
    if(A.size() == 0){
        return 0;
    }
    
    int p = 0;
    while(p+1 < A.size()){
        
        string a = A[p];
        string b = A[p+1];
        
        int n = a.size();
        int m = b.size();
        
        x = n+m;
        
        int t[n+1][m+1];
        
        for(int i = 0 ; i<= n; i++)
        {
            for(int j = 0; j<=m ; j++)
            {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
        
        for(int i = 0 ; i<= n; i++)
        {
            for(int j = 0; j<=m ; j++)
            {
                printf("%d\t",t[i][j]);
            }
            cout<<endl;
        }
        cout<<endl;
        
        for(int i = 1 ; i<= n; i++)
        {
            for(int j = 1; j<=m ; j++)
            {
                if(a[i-1] == b[j-1])
                {
                    t[i][j] = t[i-1][j-1] + 1;
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
                    
            }
        }
        
        for(int i = 0 ; i<= n; i++)
        {
            for(int j = 0; j<=m ; j++)
            {
                printf("%d\t",t[i][j]);
            }
            cout<<endl;
        }
        cout<<endl;
        string c;
        int i,j;
        i = n;
        j = m;
        while(i != 0 && j!= 0){
            if(a[i-1] == b[j-1])
            {
                c.push_back(a[i-1]);
                i--;
                j--;
            } else {
                if(t[i-1][j] > t[i][j-1]){
                    c.push_back(a[i-1]);
                    i--;
                } else {
                    c.push_back(b[j-1]);
                    j--;
                }
            }
        }
        
        while(i > 0)
        {
            c.push_back(a[i-1]);
            i--;
        }
        
        while(j>0){
            c.push_back(b[j-1]);
            j--;
        }
        
        reverse(c.begin(), c.end());
        A[p+1] = c;
        ans = x - t[n][m];
        p++;
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    vector<string> a = { "cpsklryvmcp", "nbpbwllsrehfmx", "kecwitrsglre", "vtjmxypu" };
    vector<string> b = a;
    int n = a.size();
    int max = INT_MIN;
    sort(a.begin(), a.end());
    do {
        b = a;
        int res = solve(b);
        if(res > max)
            max = res;
    } while (next_permutation(a.begin(), a.end()));
    
    cout<<max<<endl;
    return 0;
}
