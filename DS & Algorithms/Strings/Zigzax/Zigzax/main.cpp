//
//  main.cpp
//  Zigzax
//
//  Created by Giriraj Saigal on 26/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string A, int B) {
    
    vector<string> arr(B, "");
    
    int flag = 0;
    
    int n = A.size();
    int i = 0;
    int k = 0;
    while(i < n){
        if(k - 1 == -1)
            flag = 0;
        
        if(k + 1 == B)
            flag = 1;
            
        if(flag == 0){
            arr[k] += A[i];
            i++;
            k = (k + 1)%B;
        }else if(flag == 1){
            arr[k] += A[i];
            i++;
            k = (k - 1)%B;
        }
    }
    
    string ans = "";
    
    for(string x:arr)
        ans += x;
        
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<convert("", 3)<<endl;
    return 0;
}
