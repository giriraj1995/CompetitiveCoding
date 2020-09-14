//
//  main.cpp
//  Substring
//
//  Created by Giriraj Saigal on 25/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int strStr(const string A, const string B) {
    
    if(A.size() == 0 || B.size() == 0)
        return -1;
        
    if(A.size() < B.size())
        return -1;
    
    if(A.size() == B.size())
    {
        if(A == B)
            return 0;
        else
            return -1;
    }
    
    int k = 0;
    int start = 0;
    int i = 0;
    
    while(i < A.size() && k < B.size()){
        if(A[i] == B[k])
        {
            start = i;
            int p = 0;
            int count = 0;
            
            while(A[i+p] == B[k+p]){
                count++;
                p++;
                if(count == B.size())
                    return start;
            }
            start = -1;
        }
        
        i++;
    }
        
    return -1;
}


int main(int argc, const char * argv[]) {
    string x = "bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaagiribabbbaabaaaba";
    string y = "giri";
    return 0;
}
