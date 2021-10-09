//
//  main.cpp
//  Kth smallest lexical order
//
//  Created by Giriraj Saigal on 09/10/21.
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

int calSteps(long n, long n1, long n2) {
    int steps = 0;
    while (n1 <= n) {
        steps += min(n + 1, n2) - n1;
        n1 *= 10;
        n2 *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {
    int curr = 1;
    k = k - 1;
    while (k > 0) {
        int steps = calSteps(n, curr, curr + 1);
        if (steps <= k) {
            curr += 1;
            k -= steps;
        } else {
            curr *= 10;
            k -= 1;
        }
    }
    return curr;
}

int main(int argc, const char * argv[]) {
    cout << findKthNumber(14,6) << endl;
    return 0;
}
