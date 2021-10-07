//
//  main.cpp
//  Ugly no 2
//
//  Created by Giriraj Saigal on 07/10/21.
//
#define ll long long
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int nthUglyNumber(int n) {
       priority_queue<ll, vector<ll>, greater<ll>> q;
       q.push(2);
       q.push(3);
       q.push(5);
       
       while(n--) {
           int x = q.top();
           q.pop();
           cout
           q.push(x*2);
           q.push(x*3);
           q.push(x*5);
       }
       
       return q.top();
   }

int main(int argc, const char * argv[]) {
    nthUglyNumber(20);
    return 0;
}
