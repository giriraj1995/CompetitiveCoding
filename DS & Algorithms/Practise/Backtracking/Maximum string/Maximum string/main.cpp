//
//  main.cpp
//  Maximum string
//
//  Created by Giriraj Saigal on 26/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

string solve(string A, int B) {
    
    if(B == 0)
        return A;
        
    if(A.size() == 0)
        return A;
        
    map<pair<char, int>, int, greater<pair<char, int>>> mp;
    
    for(int i = 0; i < A.size(); i++) {
        mp[{A[i], i}] = i;
    }
    
    int i = 0;
    
    while(i < A.size()) {
        auto k = mp.begin();
        
        int j = 0;
        while(j < i) {
            k++;
            j++;
        }
        
        char c = k->first.first;
        int ind = k->first.second;
        
        if(A[i] == c){
            i++;
        }else{
            A[ind] = A[i];
            A[i] = c;
            B--;
            A = solve(A, B);
            break;
        }
    }
    
    return A;
}



int main(int argc, const char * argv[]) {
    cout<<solve("7599", 2)<<endl;
    return 0;
}
