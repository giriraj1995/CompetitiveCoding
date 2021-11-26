//
//  main.cpp
//  1182. Shortest Distance to Target Color
//
//  Created by Giriraj Saigal on 26/11/21.
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

vector<int> shortestDistanceColor(vector<int> colors, vector<vector<int>> queries) {
        set<int> three;
        set<int> one;
        set<int> two;
        
        for(int i = 0; i < colors.size(); i++){
            if(colors[i] == 3)
                three.insert(i);
            
            if(colors[i] == 1)
                one.insert(i);
            
            if(colors[i] == 2)
                two.insert(i);
        }
        
        vector<int> ans;
        
        for(int i = 0; i < queries.size(); i++) {
            int ind = queries[i][0];
            int color = queries[i][1];
            set<int> temp;
            
            if(color == 3) {
                temp = three;
            }
            
            if(color == 1){
                temp = one;
            }
            
            if(color == 2){
                temp = two;
            }
            
            if(temp.size() == 0){
                ans.push_back(-1);
                continue;
            }
                
            if(*temp.lower_bound(ind) == ind){
                ans.push_back(0);
                continue;
            }

            if(temp.lower_bound(ind) == temp.begin()){
                int idx = *temp.lower_bound(ind);
                ans.push_back(abs(idx - ind));
                continue;
            }

            ans.push_back(min(abs(*temp.lower_bound(ind) - ind),abs(*(--(temp.lower_bound(ind))) - ind)));
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    shortestDistanceColor({1,1,2,1,3,2,2,3,3},{{1,3},{2,2},{6,1}});
    return 0;
}
