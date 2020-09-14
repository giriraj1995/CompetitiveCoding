//
//  main.cpp
//  convert string DP
//
//  Created by Giriraj Saigal on 12/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int lenghtC(string x){
    int count = 0;
    for(char c: x){
        if(c >= 65 && c <= 90){
            count++;
        }
    }
    return count;
}

string abbreviation(string a, string b) {
    
    int count = lenghtC(a);

    if(count > b.size())
        return "NO";

    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];

    for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]
                ||  a[i-1] == b[j-1] + 32
                ||  a[i-1] == b[j-1] - 32){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<"LCS: "<<dp[n][m]<<endl;
    if(dp[n][m] != m)
        return "NO";
    else
        return "YES";

}

int main(int argc, const char * argv[]) {
    abbreviation("beFgH", "EFG");
    return 0;
}
