//
//  main.cpp
//  Ways to decode
//
//  Created by Giriraj Saigal on 22/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int numDecodings(string digits) {
    
    int n = digits.size();
    long count[n+1];
    
    count[0] = 1;
    count[1] = 1;
    //for base condition "01123" should return 0
    if(digits[0]=='0')
         return 0;
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
  
        // If the last digit is not 0,
        // then last digit must add to the number of words
        if (digits[i-1] > '0')
            count[i] = count[i-1];
  
        // If second last digit is smaller
        // than 2 and last digit is smaller than 7,
        // then last two digits form a valid character
        if (digits[i-2] == '1' ||  (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }

    return count[n] % 1000000007;
    
}

int main(int argc, const char * argv[]) {
    numDecodings("5163490394499093221199401898020270545859326357520618953580237168826696965537789565062429676962877038781708385575876312877941367557410101383684194057405018861234394660905712238428675120866930196204792703765204322329401298924190");
    return 0;
}
