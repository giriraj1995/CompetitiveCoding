//
//  main.cpp
//  isPalindrom
//
//  Created by Giriraj Saigal on 07/02/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

int isPalindrome(string A) {
    string x = "";
    for(char c : A) {
        if(isalpha(c) != 0 || isdigit(c) != 0) {
            x += c;
        }
    }
    
    int j = x.size()-1;
    int i = 0;
    
    for(int i = 0; i < x.size(); i++) {
        if(x[i] >= 65 && x[i] <= 90){
            x[i] += 32;
        }
    }
    
    while(i < j) {
        if(x[i] == x[j] || x[i]+32 == x[j] || x[i] == x[j]+32) {
            i++;
            j--;
            continue;
        }
        return 0;
    }
    
    return 1;
}


int main(int argc, const char * argv[]) {
    cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
    return 0;
}
