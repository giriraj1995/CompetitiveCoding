//
//  main.cpp
//  Longest Turbulent Subarray
//
//  Created by Giriraj Saigal on 15/09/21.
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


int maxTurbulenceSize(vector<int> arr) {
    int n = (int)arr.size();

    if(n == 1)
        return 1;

    int i = 0;
    int j = 1;
    bool flip = true;

    int ans = 1;
    while(j < n) {
        if(arr[j] == arr[j-1]) {
            i = j;
            j++;
        }

        if(arr[j] > arr[j-1]) {
            if(flip == false){
                i=j-1;
            }
            ans = max(ans, j-i+1);
            j++;

            flip = false;
            continue;
        }

        if(arr[j] < arr[j-1]) {
            if(flip == true){
                i=j-1;
            }
            ans = max(ans, j-i+1);
            j++;

            flip = true;
            continue;
        }
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    cout << maxTurbulenceSize({9,4,2,10,7,8,8,1,9}) << endl;
    return 0;
}
