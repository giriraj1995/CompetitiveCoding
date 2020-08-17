//
//  main.cpp
//  square root with BS
//
//  Created by Giriraj Saigal on 16/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int bs(int a){
    int i = 1;
    int j = a;
    float ans;
    while(i <= j){
        long long int m = i + (j-i)/2;
        long double mul = m*m;
        if(m*m == a)
            return m;
        else{
            if(m*m > a)
            {
                j = m-1;
            }
            else
            {
                ans = m;
                i = m+1;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<bs(930675566);
    return 0;
}
