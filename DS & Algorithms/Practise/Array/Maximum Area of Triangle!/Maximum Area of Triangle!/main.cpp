//
//  main.cpp
//  Maximum Area of Triangle!
//
//  Created by Giriraj Saigal on 24/12/20.
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

double Area(double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
{
    double dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return (dArea > 0.0) ? dArea : -dArea;
}

int solve(vector<string> A) {
    int n = A.size();
    int m = A[0].size();
    
        double ans = 0;
    map<int, vector<pair<int, int>>> red, green, blue;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            if(A[i][j] == 'g'){
                green[j].push_back({i,j});
            }
            
            if(A[i][j] == 'r'){
                red[j].push_back({i,j});
            }
            
            if(A[i][j] == 'b'){
                blue[j].push_back({i,j});
            }
        }
    }
    
    if(red.size() == 0 || green.size() == 0 || blue.size() == 0)
        return 0;
    
    for(int j = 0; j < m; j++) {
        
        if(green.find(j) != green.end() && blue.find(j) != blue.end()) {
            
            for(int h = 0; h < m; h++) {
                if(h == j)
                    continue;
                
                if(red.find(h) != red.end()) {
                    vector<pair<int,int>> gr = green.find(j)->second;
                    vector<pair<int,int>> bl = blue.find(j)->second;
                    vector<pair<int,int>> re = red.find(h)->second;

                    for(int g = 0; g < re.size(); g++) {
                            ans = max(ans, (double)(1/2 * (abs(gr[0].first - bl[bl.size()-1].first) + 1) * (abs(j - h) + 1)));
                            ans = max(ans, (double)(1/2 * (abs(bl[0].first - gr[gr.size()-1].first)+1) * (abs(j - h) + 1)));
                    }
                }
            }
        }
        
        if(blue.find(j) != blue.end() && red.find(j) != red.end()) {
            for(int h = 0; h < m; h++) {
                if(h == j)
                    continue;
                
                if(green.find(h) != green.end()) {
                    vector<pair<int,int>> gr = green.find(h)->second;
                    vector<pair<int,int>> bl = blue.find(j)->second;
                    vector<pair<int,int>> re = red.find(j)->second;

                    for(int g = 0; g < gr.size(); g++) {
                        double base = (abs(bl[0].first - re[re.size()-1].first)+1);
                        double height = (abs(j - h) + 1);
                        ans = max(ans, (double)(1.0/2.0 * height * base));
                        ans = max(ans, (double)(1.0/2.0 * (abs(re[0].first - bl[bl.size()-1].first)+1) * (abs(j - h) + 1)));
                    }
                }
            }
        }
        
        if(red.find(j) != red.end() && green.find(j) != green.end()) {
            for(int h = 0; h < m; h++) {
                if(h == j)
                    continue;
                
                if(blue.find(h) != blue.end()) {
                    vector<pair<int,int>> gr = green.find(j)->second;
                    vector<pair<int,int>> bl = blue.find(h)->second;
                    vector<pair<int,int>> re = red.find(j)->second;

                    for(int g = 0; g < bl.size(); g++) {
                        ans = max(ans, (double)(1/2 * (abs(re[0].first - gr[gr.size()-1].first)+1) * (abs(j - h) + 1)));
                        ans = max(ans, (double)(1/2 * (abs(gr[0].first - re[re.size()-1].first)+1) * (abs(j - h) + 1)));
                    }
                }
            }
        }
    }
    
    return ceil(ans);
}


int main(int argc, const char * argv[]) {
    solve({"rrrrr", "rrrrg", "rrrrr", "bbbbb"});
    return 0;
}
