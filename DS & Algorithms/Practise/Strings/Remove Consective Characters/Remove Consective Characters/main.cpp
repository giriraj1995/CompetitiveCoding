//
//  main.cpp
//  Remove Consective Characters
//
//  Created by Giriraj Saigal on 28/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

string solve(string A, int B) {

    if(A.size() == 0 || B <= 0)
        return "";

    int i = 0;
    int j = 0;

    map<char, int> mp;
    int dis = 0;

    while(j < A.size()) {
        mp[A[j]]++;

        if(mp[A[j]] == 1){
            dis++;
        }

        if(j - i + 1 == B) {
            if(dis == 1) {
                A.erase(A.begin()+i,A.begin()+j+1);
                j = i - 1;
                dis = 0;
                mp.clear();
            }else{
                mp[A[i]]--;
                if(mp[A[i]] == 0) {
                    mp.erase(A[i]);
                    dis--;
                }
                i++;
            }
        }

        j++;
    }

    return A;
}

// string solve(string A, int B) {
//     A+="$";
//     string res = "", temp = "";
//     int c = 1;
//     for(int i = 0; i<A.size()-1;i++){
//         temp+=A[i];
//         
//         if(A[i]==A[i+1]){
//             c++;
//             temp+=A[i];
//         }
//         
//         else{
//             if(c!=B)
//                 res+=temp;
//             temp = "";c=1;
//         }
//         
//     }
//     return res;
// }


int main(int argc, const char * argv[]) {
    solve("sooddssshbvsdkjbvddnjknsvjj",2);
    return 0;
}
