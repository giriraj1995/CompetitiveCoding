//
//  main.cpp
//  Pretty Json
//
//  Created by Giriraj Saigal on 27/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> prettyJSON(string A) {
    
    vector<string> ans;
    
    if(A.size() == 0)
        return ans;
        
    int curInden = 0;
    int n = A.size();
    
    for(int i = 0; i < n ;){
        string x;
        
        if(A[i] == '{' || A[i] == '[')
        {
            for(int j = 0; j < curInden; j++)
            {
                x = x + "\t";
            }
            x.push_back(A[i]);
            i++;
            curInden++;
        }else if(A[i] == '}' || A[i] == ']'){
            curInden--;
            for(int j = 0; j < curInden; j++)
            {
                x = x + "\t";
            }
            x.push_back(A[i]);
            i++;
        }else{
            
            for(int j = 0; j < curInden; j++)
            {
                x = x + "\t";
            }
            
            while(A[i] != ',' && A[i+1] != '{'
            && A[i+1] != '}' && A[i+1] != '[' && A[i+1] != ']'){
                x.push_back(A[i]);
                i++;
            }
            x.push_back(A[i]);
            i++;
        }
        ans.push_back(x);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    prettyJSON("{id:100,firstName:Jack,lastName:Jones,age:12}");
    
    return 0;
}
