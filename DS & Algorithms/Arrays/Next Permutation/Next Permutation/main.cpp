//
//  main.cpp
//  Next Permutation
//
//  Created by Giriraj Saigal on 16/10/20.
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
 
vector<int> nextPermutation(vector<int> ans){
    
    int index = -1;
    
    for(int i = ans.size()-2; i >= 0; i--){
        
        if(ans[i] < ans[i+1]){
            index = i;
            break;
        }
        
    }
    
    if(index == -1){
        sort(ans.begin(), ans.end());
        return ans;
    }else if(index < ans.size()){
        for(int i = ans.size()-2; i >= 0; i--){
            if(ans[i] < ans[i+1]){
                
                break;
            }
        }
        
    }
    return ans;
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = nextPermutation({1,2,3,4,5,7,6});
    return 0;
}
