//
//  main.cpp
//  81. Search in Rotated Sorted array 2
//
//  Created by Giriraj Saigal on 10/09/21.
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
int find(vector<int> x, int i, int j) {
    if(i > j)
        return (int)x.size();
    int m = i+(j-i)/2;
    if(m == 0) {
        if(x[0] <= x[1])
            return 0;
        return 1;
    }else if(m == x.size()-1){
        if(x[m] < x[m-1])
            return m;
        else
            return m+1;
    }else{
        if(x[m] <= x[m+1] && x[m] < x[m-1])
            return m;
        else {
            int left = find(x, i, m-1);
            if(x[m] >= x[0]) {
                if(left != 0 && left != x.size())
                    return left;
                
                int right = find(x, m+1, j);
                if(right != 0 && right != x.size())
                    return right;
                
                return left;
            }else{
                return left;
            }
        }
    }
}

int minIdx(vector<int> num ) {
        int ans = -1;
        int i = 0;
        int j = (int)num.size()-1;
        
        while(i <= j) {
            int m = i + (j-i)/2;
            
            if(m == 0) {
                if(num[m] <= num[m+1])
                    return 0;
                else
                    return m+1;
            }else if(m == (int)num.size()-1) {
                if(num[m] < num[m-1])
                    return m;
                else
                    return m+1;
            }else{
                if(num[m] <= num[m+1] && num[m] < num[m-1]){
                    return m;
                }else if(num[m] >= num[0]){
                    i = m+1;
                }else{
                    j = m-1;
                }
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<int> x = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    cout << find(x, 0, x.size()-1) <<endl;
    return 0;
}
