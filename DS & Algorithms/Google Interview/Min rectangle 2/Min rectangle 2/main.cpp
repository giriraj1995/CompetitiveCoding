//
//  main.cpp
//  Min rectangle 2
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

//int minAreaRect(vector<vector<int>>& points) {
//    map<int, set<int>> mp;
//    int n = points.size();
//
//    // O(n)
//    for(int i = 0; i < n; i++) mp[points[i][0]].insert(points[i][1]);
//
//    int ans = INT_MAX;
//
//    //(n)
//    for(auto i = mp.begin(); i != mp.end(); ++i) {
//        if(i->second.size() < 2) continue;
//        auto k = i;
//        ++k;
//        for(auto j = k; j != mp.end(); ++j) {
//            if(j->second.size() < 2) continue;
//            vector<int> v;
//
//            set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), back_inserter(v));
//            if(v.size() == 0)
//                continue;
//            for(int t = 0; t < v.size()-1; t++) {
//                ans = min(ans, abs(j->first-i->first) * (v[t+1] - v[t]));
//            }
//        }
//    }
//
//     return ans == INT_MAX ? 0 : ans;
//}
//
//bool is90(int x1, int y1, int x2, int y2, int x3, int y3) {
//    return ((y2-y1) / (x2-x1)) * ((y3-y1) / (x3-x1)) == -1;
//}
//
//double findarea(int x1, int y1, int x2, int y2, int x3, int y3) {
//    double ans =
//    (double)sqrt((double)pow(x1-x2,2) + (double)pow(y1-y2,2)) * (double)sqrt(pow(x1-x3,2) + (double)pow(y1-y3,2));
//    return ans;
//}
//
//double minAreaFreeRect(vector<vector<int>> points) {
//    map<int, set<int>> mp;
//    int n = points.size();
//
//    for(int i = 0; i < points.size(); i++) {
//        mp[points[i][0]].insert(points[i][1]);
//    }
//
//    double ans = minAreaRect(points);
//    ans = ans == 0 ? INT_MAX : ans;
//    cout << ans << endl;
//
//    for(auto i = mp.begin(); i != mp.end(); i++) {
//        int x1 = i->first;
//        for(int y1 : i->second) {
//            auto k = i;
//            ++k;
//            for(auto j = k; j != mp.end(); ++j) {
//                int x2 = j->first;
//                for(int y2 : j->second) {
//
//                    int x3 = x2;
//
//                    for(int y3 : j->second) {
//                        if(y3 == y2)
//                            continue;
//
//                        if(is90(x1,y1,x2,y2,x3,y3)) {
//                            //find 4th vertex
//                            int xm = x2 + x3 - x1;
//                            int ym = y2 + y3 - y1;
//
//                            if(mp.count(xm) && mp[xm].count(ym)) {
//                                ans = min(ans, findarea(x1,y1,x2,y2,x3,y3));
//                            }
//                        }
//                    }
//
//                    auto h = j;
//                    ++h;
//                    for(auto z = h; z != mp.end(); ++z) {
//                        int x3 = z->first;
//                        for(int y3 : z->second) {
//                            if(is90(x1,y1,x2,y2,x3,y3)) {
//                                //find 4th vertex
//                                int xm = x2 + x3 - x1;
//                                int ym = y2 + y3 - y1;
//
//                                if(mp.count(xm) && mp[xm].count(ym)) {
//                                    ans = min(ans, findarea(x1,y1,x2,y2,x3,y3));
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//
//    return ans;
//}

double minAreaFreeRect(vector<vector<int>> points) {
        int n = points.size();
        map<int,set<int>> mp;
        
        for(int i = 0; i < n; i++) mp[points[i][0]].insert(points[i][1]);
        double ans = 500;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int dx1 = points[j][0] - points[i][0];
                int dy1 = points[j][1] - points[i][1];
                
                for(int k = j+1; k < n; k++) {
                    int dx2 = points[k][0] - points[i][0];
                    int dy2 = points[k][1] - points[i][1];
                    
                    if(dy2 * dy1 + dx1 * dx2 != 0) continue;
                    
                    int x = dx1 + points[k][0];
                    int y = dy1 + points[k][1];
                    
                    if(mp.count(x) && mp[x].count(y)) {
                        ans = min(ans, sqrt(dx1*dx1 + dy1*dy1) * sqrt(dx2*dx2 + dy2*dy2));
                    }
                }
            }
        }
        
        return (ans == 500) ? 0 : ans;
    }

int main(int argc, const char * argv[]) {
    minAreaFreeRect({{0,1},{2,1},{1,1},{1,0},{2,0}});
    return 0;
}
