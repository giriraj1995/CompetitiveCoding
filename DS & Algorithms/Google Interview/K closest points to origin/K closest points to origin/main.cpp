//
//  main.cpp
//  K closest points to origin
//
//  Created by Giriraj Saigal on 26/10/21.
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

bool cmp1(vector<int> x, vector<int> y) {
    return (x[0]*x[0] + x[1]*x[1]) < (y[0]*y[0] + y[1]*y[1]);
}

bool cmp2(vector<int> x, vector<int> y) {
    return (x[0]*x[0] + x[1]*x[1]) <= (y[0]*y[0] + y[1]*y[1]);
}
    
int partition(int st, int en, int k, vector<vector<int>>&points) {
    vector<int> pivot = points[st];
    int i = st;
    int j = en;
    
    while(i < j){
        do{i++;}while(cmp2(points[i],pivot));
        do{j--;}while(cmp1(pivot,points[j]));
        if(i < j) {
            vector<int> temp =points[i];
            points[i] = points[j];
            points[j] = temp;
        }
    }
    
    vector<int> temp = points[st];
    points[st] = points[j];
    points[j] = temp;
    
    return j;
}
    
void quicklysort(int st, int end, int k, vector<vector<int>>& points) {
    int p = partition(st, end, k, points);
    if(p-st+1 == k)
        return;
    else if(p-st+1 < k) {
        quicklysort(p+1,end,k - (p-st+1),points);
    }else{
        quicklysort(st, p, k,points);
    }
}
    vector<vector<int>> kClosest(vector<vector<int>> points, int k) {
        points.push_back({10001,10001});
        int n = points.size();
        quicklysort(0, n-1, k, points);
        points.resize(k);
        return points;
    }

int main(int argc, const char * argv[]) {
    kClosest({{0,1},{1,0},{0,11},{1,3},{6,1},{12,-20},{0,-1},{12,-6}},5);
    return 0;
}
