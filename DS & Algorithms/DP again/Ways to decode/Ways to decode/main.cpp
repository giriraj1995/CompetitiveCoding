//
//  main.cpp
//  Ways to decode
//
//  Created by Giriraj Saigal on 22/10/20.
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

#define M 1000000007
#define ll long long
int numDecodings(string A)
{
    int n = A.size();
    ll dp[n] = {0};
    
    if(A[0]!= '0')
    dp[0] = 1;
    for(int x=1; x<n; x++)
    {
        if(A[x+1] == '0' and x<n-1)
            continue;
            
        int p1 = A[x] - '0';
        int p2 = A[x-1] - '0';
        
        if(A[x] != '0')
        dp[x] = (dp[x]+dp[x-1])%M;
        
      
            if(p1<=6 and p2 == 2)
            {
                if(x == 1)
                dp[x]++;
                
                else
                dp[x] = (dp[x] + dp[x-2])%M;
            }
            
            else if(p2 == 1 and p1<=9)
            {
                if(x == 1)
                dp[x]++;
                
                else
                dp[x]  = (dp[x] + dp[x-2])%M;
            }
    
    }
    
    int ans = dp[n-1]%M;
    return ans;
}

int main(int argc, const char * argv[]) {
    numDecodings("5163490394499093221199401898020270545859326357520618953580237168826696965537789565062429676962877038781708385575876312877941367557410101383684194057405018861234394660905712238428675120866930196204792703765204322329401298924190");
    return 0;
}
