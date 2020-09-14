//
//  main.cpp
//  3 Sum Zero
//
//  Created by Giriraj Saigal on 01/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> > threeSum(vector<int> &A) {
    
    
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    map<vector<int>,int> u;
    
    if(A.size() <= 2)
        return ans;
    
    int n = A.size();
    for(int i = 0; i < n-2; i++){
        int left = i + 1;
        int right = n - 1;
        
        while(left < right){
            long long int a,b,c;
            a = A[i];
            b = A[left];
            c = A[right];
            
            long long int sum = a+b+c;
            if(sum == 0)
            {
                vector<int> x;
                x.push_back(A[i]);
                x.push_back(A[left]);
                x.push_back(A[right]);
                u.insert(make_pair(x,rand()));
                left++;
                right--;
            }else{
                if(sum > 0)
                    right--;
                else
                    left++;
            }
        }
        
    }
    
    map<vector<int>,int>::iterator itr;
    
    for(itr = u.begin() ; itr != u.end() ; itr++){
        ans.push_back(itr->first);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<int> x = {2147483647, -2147483648, -2147483648, 0, 1 };
    threeSum(x);
    return 0;
}
