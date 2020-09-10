//
//  main.cpp
//  Sliding window maximum
//
//  Created by Giriraj Saigal on 10/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
  
void printKMax(int A[], int n, int k)
{
    vector<int> ans;
    deque<int> q;
    int i;
    for(i = 0; i < k; i++)
    {
        while(q.size() != 0 && A[i] >= A[q.back()])
            q.pop_back();
    
        q.push_back(i);
    }
    
    for(; i < n ; i++)
    {
        ans.push_back(A[q.front()]);
        
        while(q.size() != 0 && q.front() <= i - k)
            q.pop_front();
        
        while(q.size() != 0 && A[i] >= A[q.back()])
            q.pop_back();
        
        q.push_back(i);
    }
    
    ans.push_back(A[q.front()]);
    
}
  
// Driver program to test above functions
int main()
{
    int arr[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
