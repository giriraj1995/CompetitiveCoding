//
//  main.cpp
//  Ways to form Max Heap
//
//  Created by Giriraj Saigal on 14/05/21.
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

#define MAXN 105 // maximum value of n here



// dp[i] = number of max heaps for i distinct integers
int dp[MAXN];
  
// nck[i][j] = number of ways to choose j elements
//             form i elements, no order */
int nck[MAXN][MAXN];
  
// log2[i] = floor of logarithm of base 2 of i
int log22[MAXN];
  
// to calculate nCk
int choose(int n, int k)
{
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;
  
    if (nck[n][k] != -1)
        return nck[n][k];
  
    int answer = choose(n - 1, k - 1) + choose(n - 1, k);
    nck[n][k] = answer;
    return answer;
}
  
// calculate l for give value of n
int getLeft(int n)
{
    if (n == 1)
        return 0;
  
    int h = log22[n];
  
    // max number of elements that can be present in the
    // hth level of any heap
    int numh = (1 << h); //(2 ^ h)
  
    // number of elements that are actually present in
    // last level(hth level)
    // (2^h - 1)
    int last = n - ((1 << h) - 1);
  
    // if more than half-filled
    if (last >= (numh / 2))
        return (1 << h) - 1; // (2^h) - 1
    else
        return (1 << h) - 1 - ((numh / 2) - last);
}
  
// find maximum number of heaps for n
int numberOfHeaps(int n)
{
    if (n <= 1)
        return 1;
  
    if (dp[n] != -1)
        return dp[n];
  
    int left = getLeft(n);
    int ans = (choose(n - 1, left) * numberOfHeaps(left)) *
                             (numberOfHeaps(n - 1 - left));
    dp[n] = ans;
    return ans;
}
  
// function to initialize arrays
int solve(int n)
{
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
  
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            nck[i][j] = -1;
  
    int currLog2 = -1;
    int currPower2 = 1;
  
    // for each power of two find logarithm
    for (int i = 1; i <= n; i++) {
        if (currPower2 == i) {
            currLog2++;
            currPower2 *= 2;
        }
        log22[i] = currLog2;
    }
  
    return numberOfHeaps(n);
}
int main(int argc, const char * argv[]) {
    cout<<solve(10)<<endl;
    return 0;
}
