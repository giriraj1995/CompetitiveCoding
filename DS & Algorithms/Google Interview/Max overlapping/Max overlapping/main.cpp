//
//  main.cpp
//  Max overlapping
//
//  Created by Giriraj Saigal on 06/09/21.
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

int findOverlappingPair(string str1,
                     string str2, string &str)
{
     
    // Max will store maximum
    // overlap i.e maximum
    // length of the matching
    // prefix and suffix
    int max = INT_MIN;
    int len1 = str1.length();
    int len2 = str2.length();
 
    // Check suffix of str1 matches
    // with prefix of str2
    for (int i = 1; i <=
                      min(len1, len2); i++)
    {
         
        // Compare last i characters
        // in str1 with first i
        // characters in str2
        if (str1.compare(len1-i, i, str2,
                                 0, i) == 0)
        {
            if (max < i)
            {
                // Update max and str
                max = i;
                str = str1 + str2.substr(i);
            }
        }
    }
 
    // Check prefix of str1 matches
    // with suffix of str2
    for (int i = 1; i <=
                        min(len1, len2); i++)
    {
         
        // compare first i characters
        // in str1 with last i
        // characters in str2
        if (str1.compare(0, i, str2,
                              len2-i, i) == 0)
        {
            if (max < i)
            {
                 
                // Update max and str
                max = i;
                str = str2 + str1.substr(i);
            }
        }
    }
 
    return max;
}

int main(int argc, const char * argv[]) {
    string x;
    cout << findOverlappingPair("giriraj", "girir", x) << endl;
    return 0;
}
