//
//  main.cpp
//  Count And Say
//
//  Created by Giriraj Saigal on 25/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string countAndSay(int A) {
    string ans;
    
    if(A == 0 || A < 0 )
        return ans;
        
    if(A == 1)
        return "1";
        
    vector<string> x(A+1, "");
    
    x[1] = "1";

    for(int i = 2; i <= A; i++){
        string p = x[i-1];
        string c = "";
        int count = 1;
        char pr = p[0], cur;
        for(int j = 1 ;j < p.size(); j++){
            cur = p[j];
            if(cur == pr){
                count++;
            } else {
                c = c + to_string(count) + pr;
                count = 1;
            }
            pr = cur;
        }
        c = c + to_string(count) + pr;
        x[i] = c;
    }
    
    return x[A];
}


int main(int argc, const char * argv[]) {
    cout<<countAndSay(10);
    return 0;
}
