//
//  main.cpp
//  Reverse String word by word
//
//  Created by Giriraj Saigal on 25/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string solve(string A) {
    
    vector<string> x;
    int flag = 0;
    string p;
    for(int i = 0; i < A.size(); i++){
        if(A[i] != ' '){
            flag = 1;
            p.push_back(A[i]);
        } else if(flag == 1){
            x.push_back(p);
            p.clear();
            flag = 0;
        }
    }
    
    x.push_back(p);
    
    int d = x.size();
    string ans = "";
    for(int i = d-1; i >= 0; i--){
        if(x[i] == " " || x[i] == "")
            continue;
        ans = ans + x[i] + " ";
    }
    
    return ans.substr(0, ans.size()-1);
    
}


int main(int argc, const char * argv[]) {
    cout<<solve("       fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq                 ")<<endl;
    return 0;
}
