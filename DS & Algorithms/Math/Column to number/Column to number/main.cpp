//
//  main.cpp
//  Column to number
//
//  Created by Giriraj Saigal on 19/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string convertToTitle(int A) {
    
    if(A == 0 || A<0)
        return "";
    
    int rem;
    int x = A;
    vector<string> t;
    string ans;
    
    while(x > 0)
    {
        rem = x%26;
        x = x/26;
        
        if(rem == 0)
        {
            ans.push_back('Z');
            x = x -1;
        }
        else
            ans.push_back(rem + 'A' - 1);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<convertToTitle(943566)<<endl;
    return 0;
}
