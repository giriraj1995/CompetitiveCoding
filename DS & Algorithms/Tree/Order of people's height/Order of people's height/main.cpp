//
//  main.cpp
//  Order of people's height
//
//  Created by Giriraj Saigal on 08/10/20.
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

vector<int> order1(vector<int> &heights, vector<int> &infronts)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> v(heights.size(), -1);
    map<int, int> mp;
    
    for(auto i=0; i<heights.size(); i++)
    {
        mp[heights[i]] = infronts[i];
    }
    
    for(auto it : mp)
    {
        int i = 0, j = 0;
        
        while(i != it.second)
        {
            if(v[j] == -1)
                i++;
            j++;
        }
        while(v[j] != -1)
        {
            j++;
        }
        v[j] = it.first;
    }
    
    return v;
}

bool cmp(pair<int,int>& a,pair<int,int>& b)
{
    if(a.first>b.first || (a.first == b.first && a.second<b.second))
        return true;
    return false;
}
vector<int> order(vector<int> &A, vector<int> &B)
{
    vector<pair<int,int>> arr;
    
    for(int i=0;i<A.size();i++)
        arr.push_back({A[i],B[i]});
        
    sort(arr.begin(),arr.end(),cmp);
    vector<int> ans;
    
    for(int i=0;i<arr.size();i++)
        ans.insert(ans.begin()+arr[i].second,arr[i].first);
        
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> y = {0, 1, 2, 0, 3, 2};
    vector<int> x = {5, 3, 2, 6, 1, 4};
    order(x, y);
    return 0;
}
