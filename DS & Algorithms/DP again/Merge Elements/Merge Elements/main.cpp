//
//  main.cpp
//  Merge Elements
//
//  Created by Giriraj Saigal on 20/11/20.
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

pair<int,int> dp[201][201];
pair<int,int> fun(int i, int j,vector<int> &A)
{
pair<int,int> x;
x.first=0;
x.second=INT_MAX;
if(i>j)
{
return x;
}
if(i==j)
{
x.first=A[i];
x.second=0;
return x;
}
if(dp[i][j].first!=-1)
{
return dp[i][j];
}
int temp;
for(int k=i;k<j;k++)
{
temp=fun(i,k,A).second+fun(k+1,j,A).second+fun(i,k,A).first+fun(k+1,j,A).first;
if(x.second>temp)
{
x.second=temp;
x.first=fun(i,k,A).first+fun(k+1,j,A).first;
}
}
return dp[i][j]=x;
}

int Solution::solve(vector<int> &A) {
memset(dp,-1,sizeof(dp));
return fun(0,A.size()-1,A).second;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
