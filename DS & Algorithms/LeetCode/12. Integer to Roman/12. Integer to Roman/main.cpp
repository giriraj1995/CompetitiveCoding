//
//  main.cpp
//  12. Integer to Roman
//
//  Created by Giriraj Saigal on 05/03/21.
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

string intToRoman(int num) {
    int x = num;
    string ans = "";
    while(x > 0) {
        
        bool M = false;
        int Mcount = 0;
        while(x >= 900) {
            
            if(x >= 1000){
                x -= 1000;
                Mcount++;
            }else{
                M = true;
                //ans += "CM";
                x -= 900;
            }
            
        }
        
        while(Mcount--){
            ans += 'M';
        }
        
        if(M)
            ans += "CM";
        
        bool D = false;
        int Dcount = 0;
        while(x >= 400) {
            
            if(x >= 500){
                x -= 500;
                Dcount++;
            }else{
                D = true;
                //ans += "ID";
                x -= 400;
            }
            
        }
        
        while(Dcount--){
            ans += 'D';
        }
        
        if(D)
            ans += "CD";
        
        bool C = false;
        int Ccount = 0;
        while(x >= 90) {
            
            if(x >= 100){
                x -= 100;
                Ccount++;
            }else{
                C = true;
                //ans += "IC";
                x -= 90;
            }
            
        }
        
        
        while(Ccount--){
            ans += 'C';
        }
        
        if(C)
            ans += "XC";
        
        bool L = false;
        int Lcount = 0;
        while(x >= 40) {
            
            if(x >= 50){
                x -= 50;
                Lcount++;
            }else{
                L = true;
                //ans += "IC";
                x -= 40;
            }
            
        }
        
        while(Lcount--){
            ans += 'L';
        }
        
        if(L)
            ans += "XL";
        
        bool X = false;
        int Xcount = 0;
        while(x >= 9) {
            
            if(x >= 10){
                x -= 10;
                Xcount++;
            }else{
                X = true;
                //ans += "IX";
                x -= 9;
            }
            
        }
        
        
        while(Xcount--){
            ans += 'X';
        }
        
        if(X)
            ans += "IX";
        
        bool V = false;
        int Vcount = 0;
        while(x >= 4) {
            
            if(x >= 5){
                x -= 5;
                Vcount++;
            }else{
                V = true;
                //ans += "IV";
                x -= 4;
            }
        }
        
        while(Vcount--){
            ans += 'V';
        }
        
        if(V)
            ans += "IV";
        
        int Icount = 0;
        while(x >= 1) {
            x -= 1;
            Icount++;
        }
        
        if(Icount <= 3)
            while(Icount--){
                ans += 'I';
            }
        else
            ans += "IV";
        
        break;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<intToRoman(1994)<<endl;
    return 0;
}
