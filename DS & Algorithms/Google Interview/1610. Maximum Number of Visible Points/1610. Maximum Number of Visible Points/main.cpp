//
//  main.cpp
//  1610. Maximum Number of Visible Points
//
//  Created by Giriraj Saigal on 29/10/21.
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

double getangle(vector<int> point, vector<int> location) {
        double x;
        if((point[0] - location[0] == 0) && point[1] > location[1]){
            x = 90.0;
            return x;
        }else if((point[0] - location[0]) == 0 && point[1] < location[1]){
            x = 270.0;
            return x;
        }
        
        x = atan2((point[1] - location[1] * 1.0) , (point[0] - location[0] * 1.0)) * 360 / (2 * 2 * acos(0.0));
        
        if(x < 0)
            x += 360;
        
        return x;
    }
    
int visiblePoints(vector<vector<int>> points, int angle, vector<int> location) {
        vector<double> angles;
        int same = 0;
        
        for(int i = 0; i < points.size(); i++) {
            if(points[i][0] == location[0] && location[1] == points[i][1]) {
                same++;
            }else{
                angles.push_back(getangle(points[i], location));
            }
        }
        
        sort(angles.begin(), angles.end());
        
        deque<double> q;
        int ans = 0;
        
        for(int i = 0; i < angles.size(); i++) {
            q.push_back(angles[i]);
            while(angles[i] - q.front() > angle) {
                q.pop_front();
            }
            ans = max(ans, (int)q.size());
        }
        
        for(int i = 0; i < angles.size(); i++) {
            angles[i] = angles[i] + 360;
            q.push_back(angles[i]);
            while(angles[i] - q.front() > angle) {
                q.pop_front();
            }
            ans = max(ans, (int)q.size());
        }
        
        return same + ans;
    }

int main(int argc, const char * argv[]) {
    cout << visiblePoints({{45,26},{82,12},{33,83},{58,50},{55,92},{66,42},{25,74},{74,74},{36,87},{7,41},{89,36},{44,22},{84,9},{96,90},{75,51},{87,15},{50,75},{90,84},{56,18},{43,48},{23,27},{100,34}},
                          12,
                          {32,37}) << endl;
    return 0;
}
