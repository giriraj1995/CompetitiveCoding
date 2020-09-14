//
//  main.cpp
//  Special Product
//
//  Created by Giriraj Saigal on 06/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int maxSpecialProduct(vector<int> &A) {
    
    int ans = 0;

    if(A.size() == 0 || A.size() == 1)
        return ans;
        
    for(int i = 0; i < A.size() ; i++){
        
        int j = i - 1;
        int left = -1;
        
        while(j >= 0){
            if(A[j] > A[i]){
                left = j;
                break;
            }
            j--;
        }
        
        if(left == -1)
            return 0;
        
        j = i + 1;
        int right = -1;
        
        while(j < A.size()){
            if(A[j] > A[i]){
                right = j;
                break;
            }
            j++;
        }
        
        if(right == -1)
            return 0;
            
        if((left * right) > ans)
            ans = left*right;
    }
    
    return ans;
    
}

int maxSpecialProduct1(vector<int> &A) {
    long long i,ans=INT_MIN;
    stack<int> s;
    for(i=0;i<A.size();i++){
        while(!s.empty() && A[s.top()]<=A[i]){
            s.pop();
            if(!s.empty())ans=max(ans,s.top()*i);
        }
        s.push(i);
    }
    return ans<0?0:ans%(long long)(pow(10,9)+7);
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1, 4, 3, 4};
    
    cout<<maxSpecialProduct1(x);
    return 0;
}
