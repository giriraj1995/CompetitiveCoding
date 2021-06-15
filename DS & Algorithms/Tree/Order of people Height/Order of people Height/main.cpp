//
//  main.cpp
//  Order of people Height
//
//  Created by Giriraj Saigal on 15/06/21.
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

bool compare(vector<int> x, vector<int> y) {
    if(x[0] > y[0])
        return true;
    else if(x[0] < y[0])
        return false;
    else{
        if(x[1] > y[1])
            return false;
        else
            return true;
    }
}
vector<vector<int>> reconstructQueue(vector<vector<int>> people) {
    sort(people.begin(), people.end(), compare);
        vector<vector<int>> ans;
        int temp = people.size();
    int x = 0;
        while(x < temp) {
            int ele = people[x][0];
            int k = people[x][1];
            ans.insert(ans.begin()+k,{ele,k});
            x++;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    reconstructQueue({{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}});
    return 0;
}
