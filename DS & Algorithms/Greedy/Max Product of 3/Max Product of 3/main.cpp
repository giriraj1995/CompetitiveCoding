//
//  main.cpp
//  Max Product of 3
//
//  Created by Giriraj Saigal on 24/10/20.
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

int maxp3(vector<int> &A) {
    
    int n = A.size();
    
    if(n < 3)
        return 0;
        
    priority_queue<int> maxheap;
    
    for(int i : A){
        maxheap.push(i);
    }
    
    int i = 0;
    int ans = 1;
    
    while(i < 3){
        int k = maxheap.top();
        maxheap.pop();
        ans *= k;
        i++;
    }
    
    return ans;
    
}

int max(int a, int b){
    return a>b?a:b;
}
void calculate_the_maximum(int n, int k) {

    int x = 0;
    int y = 0;
    int z = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            
            if ((i&j) < k)
                x = max(x, i & j);

            if ((i|j) < k)
                y = max(y, i | j);
            
            if((i^j) < k)
                z = max(z, i ^ j);

        }
    }

    printf("%d\n%d\n%d", x,y,z);
}



int main(int argc, const char * argv[]) {
//    vector<int> x = {0, -1, 3, 100, -70, -50};
//    cout<<maxp3(x);
    calculate_the_maximum(5, 4);
    return 0;
}
