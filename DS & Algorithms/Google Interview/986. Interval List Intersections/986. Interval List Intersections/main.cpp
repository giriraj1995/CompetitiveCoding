//
//  main.cpp
//  986. Interval List Intersections
//
//  Created by Giriraj Saigal on 24/11/21.
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

//vector<vector<int>> intervalIntersection(vector<vector<int>> firstList, vector<vector<int>> secondList) {
//        int n = (int)firstList.size();
//        int m = (int)secondList.size();
//
//        if(n == 0 && m == 0)
//            return {};
//
//        if(n == 0)
//            return secondList;
//
//        if(m == 0)
//            return firstList;
//
//
//        vector<pair<int,int>> vec;
//
//        for(int i = 0; i < n; i++){
//            vec.push_back({firstList[i][0],0});
//            vec.push_back({firstList[i][1],1});
//        }
//
//        for(int i = 0; i < m; i++){
//            vec.push_back({secondList[i][0],0});
//            vec.push_back({secondList[i][1],1});
//        }
//
//        sort(vec.begin(), vec.end());
//
//        int count = 0;
//        vector<vector<int>> ans;
//        int st = -1;
//        int en = -1;
//
//        for(int i = 0; i < vec.size(); i++) {
//            if(vec[i].second == 0) {
//                count++;
//
//                if(count == 2)
//                    st = vec[i].first;
//            }else{
//                count--;
//
//                if(count == 1){
//                    en = vec[i].first;;
//                    ans.push_back({st,en});
//                }
//            }
//        }
//
//        return ans;
//    }

bool intersect(vector<int> v1, vector<int> v2) {
        if(v1[0] <= v2[1] && v1[1] >= v2[0])
            return true;
        
        return false;
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>> firstList, vector<vector<int>> secondList) {
        int n = firstList.size();
        int m = secondList.size();
        
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        
        while(i < n && j < m) {
            if(intersect(firstList[i], secondList[j])) {
                ans.push_back({max(firstList[i][0], secondList[j][0]),
                              min(firstList[i][1], secondList[j][1])});
            }
            
            if(firstList[i][1] <= secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    intervalIntersection({{0,2},{5,10},{13,23},{24,25}},
    {{1,5},{8,12},{15,24},{25,26}});
    return 0;
}
