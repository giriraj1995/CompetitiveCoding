//
//  main.cpp
//  Longest Substring without repeat
//
//  Created by Giriraj Saigal on 17/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int lengthOfLongestSubstring(string A) {
    
    if(A.size() == 0 || A.size() == 1)
        return A.size();
    
    int l = 0;
    int k = 0;
    int c = 0;


    for(int i = 0; i < A.size(); i++){
        
        unordered_map<char, int> u;
        u[A[i]] = i;
        c = 1;
        for(int j = i + 1; j < A.size(); j++){
            
            if(u.find(A[j]) != u.end()){
                
                i = u[A[j]];
                break;
                
            }
            
            u[A[j]] = j;
            c++;
        }
        l = max(l, c);
    }
    return l;
}

int main(int argc, const char * argv[]) {
    cout<<lengthOfLongestSubstring("dasgsk")<<endl;
    return 0;
}
