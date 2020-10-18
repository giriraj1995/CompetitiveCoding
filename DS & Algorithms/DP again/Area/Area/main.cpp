//
//  main.cpp
//  Area
//
//  Created by Giriraj Saigal on 17/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()  {
    int base;
    int height;
    
    cin>>base>>height;
    
    double areaE;
    
    areaE = (3.141592653589 * pow(height/2, 2)) / 2.0;
    
    double actual = base*height;
    
    double prob = 1.0 - areaE/actual;
    
    cout<< fixed << setprecision(8) << prob << endl;
    
    return 0;
}

