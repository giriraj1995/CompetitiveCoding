//
//  main.cpp
//  No of SubMatrix to Zero
//
//  Created by Giriraj Saigal on 15/11/20.
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
int zeroes(vector<int> arr, int n)
{
   unordered_map<int, int> mp;
   int count = 0;
   int sum = 0;
   for(int i = 0; i < n; i++)
   {
      sum += arr[i];
      if(sum==0)
      {
          count++;
      }
      if(mp.find(sum) != mp.end())
      {
          count += mp[sum];
      }
      mp[sum]++;
  }
  return count;
}

int solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n==0 || m==0)
    {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        vector<int> arr(n , 0);
        for(int j = i; j < m; j++)
        {
            for(int k = 0; k < n; k++)
            {
                arr[k] = arr[k] + A[k][j];
            }
            ans = ans + zeroes(arr, n);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> x = {
        {-2, -1, 1, 2}
    };
    
    cout<<solve(x);
    return 0;
}
