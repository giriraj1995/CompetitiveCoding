//
//  main.cpp
//  Rod Cutting
//
//  Created by Giriraj Saigal on 12/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &k, int i, int j, vector<int> &x, int &y, int index)
{
    if(i >= j)
        return 0;
        
    int p;
    int m = (int)k.size();
    int temp;
    int q = 0;
    int min = INT_MAX;
    
    for(p = 0; p < m ; p++)
    {
        if(k[p] >= i && k[p] < j)
        {
            temp = (j-i+1) + solve(k, i, k[p], x,y, index+1) + solve(k, k[p]+1, j, x,y, index+1);
        } else {
            continue;
        }
        
        if(temp < min)
        {
            y = k[p];
            min = temp;
        }
    }
    
    
    
    if(min == INT_MAX)
        return 0;
    else{
        x[index] = y;
        return min;
    }
}


int main(int argc, const char * argv[]) {
    int A = 6;
    vector<int> B = {1,2,5};
    vector<int> ans;
    ans.assign(B.size()+1, 0);
    int n = A;
    int y = INT_MIN;
    // for(i = 1; i<= n; i++)
    // {
    //     arr.push_back(i);
    // }
    

    int res = solve(B, 1, n, ans,y,0);

    
    int x = (int)ans.size();
    
    for(int i = 0; i< x ; i++)
        cout<<ans[i]<<" ";
    
    
    cout<<endl;
    cout<<res;

    return 0;
}
