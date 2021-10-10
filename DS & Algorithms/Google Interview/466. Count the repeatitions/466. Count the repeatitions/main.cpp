//
//  main.cpp
//  466. Count the repeatitions
//
//  Created by Giriraj Saigal on 10/10/21.
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


int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    unordered_map<int,int> repeatCount(n1+1);
    unordered_map<int,int> nextIndex(n1+1);
    
    repeatCount[0] = 0;
    nextIndex[0] = 0;
    int j = 0;
    int cnt = 0;
    
    for(int k = 1; k <= n1; k++) {
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == s2[j]) {
                j++;
                
                if(j == s2.size()) {
                    j = 0;
                    ++cnt;
                }
            }
        }
        
        if(nextIndex.count(j)) {
            int start = nextIndex[j];
            int prevCount = repeatCount[start];
            int patternCount = ((n1-start)/(k-start)) * (cnt-prevCount);
            int suffixCount = repeatCount[(start + (n1-start)%(k-start))] - prevCount;
            
            return (prevCount+patternCount+suffixCount)/n2;
        }
        
        repeatCount[k] = cnt;
        nextIndex[j] = k;
    }
    
    return repeatCount[n1]/n2;
}

int main(int argc, const char * argv[]) {
    cout << getMaxRepetitions("acb",5,"bcaa",2) << endl;
    return 0;
}
