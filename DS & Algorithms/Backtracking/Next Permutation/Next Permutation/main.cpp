//
//  main.cpp
//  Next Permutation
//
//  Created by Giriraj Saigal on 14/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getPermutation(int A, int B) {

    vector<int> v;
    for(int i=1;i<=A;i++)v.push_back(i);

    do{
        B--;
    }while(next_permutation(v.begin(),v.end()) && B!=1);

    string s="";
    for(int i: v){
        s = s +  to_string(i);
    }
    return s;
}

int main(int argc, const char * argv[]) {
    getPermutation(3,1);
    return 0;
}
