//
//  main.cpp
//  String frequncy
//
//  Created by Giriraj Saigal on 26/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[1001];
    scanf("%s", &s);
    int x[10] = {0};

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '0'){
            x[0]++;
        }
        if(s[i] == '1'){
            x[1]++;
        }
        if(s[i] == '2'){
            x[2]++;
        }
        if(s[i] == '3'){
            x[3]++;
        }
        if(s[i] == '4'){
            x[4]++;
        }
        if(s[i] == '5'){
            x[5]++;
        }
        if(s[i] == '6'){
            x[6]++;
        }
        if(s[i] == '7'){
            x[7]++;
        }
        if(s[i] == '8'){
            x[8]++;
        }
        if(s[i] == '9'){
            x[9]++;
        }
    }

    for(int i = 0; i <= 9; i++){
        printf("%d", x[i]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
