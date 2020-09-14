//
//  main.cpp
//  Egg Dropping Problem
//
//  Created by Giriraj Saigal on 09/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "limits"
using namespace std;

int max(int i, int j){return i>j?i:j;}
int t[1002][1002];
int calls = 0;
int ed(int f, int e)
{
    calls++;
    if(f == 0 || f == 1)
        return f;
    
    if(e == 1)
        return f;
    
    if(t[f][e] != -1)
        return t[f][e];
    
    int k;
    int min = INT_MAX;
    int temp1;
    int temp2;
    
    for(k = 1; k<=f; k++)
    {
        if(t[k-1][e-1] != -1)
            temp1 = t[k-1][e-1];
        else
            t[k-1][e-1] = temp1 = ed(k-1, e-1);
        
        if(t[f-k][e] != -1)
            temp2 = t[f-k][e];
        else
            t[f-k][e] = temp2 = ed(f-k, e);
        
        int temp = 1 + max(temp1, temp2);
        
        if(temp < min)
            min = temp;
    }
    return t[f][e] = min;
}

int main(int argc, const char * argv[]) {
    int f = 5;
    int e = 3;
    
    memset(t, -1, sizeof(t));
    
    cout<<"# Min no. of attempts to know the floor height : "<<ed(f,e)<<endl;
    cout<<"# Calls : "<<calls<<endl;
    return 0;
}
