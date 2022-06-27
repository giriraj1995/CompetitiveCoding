//
//  main.cpp
//  388. Longest Absolute File Path
//
//  Created by Giriraj Saigal on 08/06/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

//void bfs(int u, unordered_map<int,vector<int>> mp, vector<bool> &visited, long long &tmp, vector<int> &C) {
//    // include tmp + C[u]
//    // not include tmp
//    // alone C[i]
//
//    //
//    tmp = max(max((long long)tmp+(long long)C[u], (long long)tmp), (long long)C[u]);
//    visited[u] = true;
//    for(int v : mp[u]) {
//        if(visited[v] == false) {
//            bfs(v, mp, visited, tmp, C);
//        }
//    }
//}
//
//int solve(int A, vector<vector<int>> B, vector<int> C) {
//    unordered_map<int,vector<int>> mp;
//
//    for(auto k : B) {
//        mp[k[0]].push_back(k[1]);
//        mp[k[1]].push_back(k[0]);
//    }
//
//    long long sum = INT_MIN;
//    vector<bool> visited(A, false);
//
//    for(int i = 0; i < A-1; i++) {
//        if(visited[i] == false) {
//            long long tmp = INT_MIN;
//            bfs(i, mp, visited, tmp, C);
//            sum = max(sum, tmp);
//        }
//    }
//
//    return sum;
//}

//int solve(string A) {
//    int i =0;
//    int j = 0;
//    multiset<int> s;
//    s.insert(0);
//    int x = 0;
//    int ans = 0;
//
//    while(j < A.size()) {
//        if(A[j] >= 'A' && A[j] <= 'Z') {
//            x++;
//        }else{
//            x--;
//        }
//        s.insert(x);
//        cout <<(s.lower_bound(x) == s.begin() ? 0 : );
//        ans += *(s.lower_bound(x)--);
//        j++;
//    }
//
//    return ans;
//}

//void solve(int i, int level, vector<string> tree, string input, int &ans) {
//        if(i >= input.size())
//            return;
//
//        int j = i;
//        string fileOrDir = "";
//        bool isFile = false;
//
//        while(j < input.size() && input[j] != 10 && input[j] != 9) {
//            if(input[j] == '.')
//                isFile = true;
//            fileOrDir.push_back(input[j]);
//            j++;
//        }
//
//        if(isFile) {
//            int t = 0;
//            t += level;
//            for(int g = 0; g < level; g++) {
//                t += tree[g].size();
//            }
//            t += fileOrDir.size();
//            ans = max(ans, t);
//        }else{
//            tree[level] = fileOrDir;
//        }
//
//        //next level
//        int nextLevel = 0;
//        if(j < input.size() && input[j] == 10) {
//            j += 1;
//        }
//
//        while(j < input.size() && input[j] == 9) {
//            nextLevel++;
//            j+=1;
//        }
//
//        solve(j, nextLevel, tree, input, ans);
//    }
//
//    int lengthLongestPath(string input) {
//        int ans = 0;
//        vector<string> tree(5, "");
//        solve(0, 0, tree, input, ans);
//        return ans;
//    }

int main(int argc, const char * argv[]) {
//    solve(1, {}, {1});
    //solve("DbIOhYF");
    
    multiset<int> s;
    s.insert(1);
        s.insert(0);
        s.insert(0);
        s.insert(1);
        s.insert(2);
    auto it = s.lower_bound(0);
        cout << "\nThe lower bound of key 0 is ";
        cout << distance(s.begin(),it) << endl;
     it = s.lower_bound(1);
        cout << "\nThe lower bound of key 1 is ";
        cout << distance(s.begin(),it) << endl;
     it = s.lower_bound(2);
        cout << "\nThe lower bound of key 2 is ";
        cout << distance(s.begin(),it) << endl;
    return 0;
}
