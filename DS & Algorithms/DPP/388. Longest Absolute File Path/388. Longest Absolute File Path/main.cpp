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
#include <queue>
using namespace std;

void solve(int i, int level, vector<string> tree, string input, int &ans) {
        if(i >= input.size())
            return;
        
        int j = i;
        string fileOrDir = "";
        bool isFile = false;

        while(j < input.size() && input[j] != 10 && input[j] != 9) {
            if(input[j] == '.')
                isFile = true;
            fileOrDir.push_back(input[j]);
            j++;
        }

        if(isFile) {
            int t = 0;
            t += level;
            for(int g = 0; g < level; g++) {
                t += tree[g].size();
            }
            t += fileOrDir.size();
            ans = max(ans, t);
        }else{
            tree[level] = fileOrDir;
        }
        
        //next level
        int nextLevel = 0;
        if(j < input.size() && input[j] == 10) {
            j += 1;
        }
        
        while(j < input.size() && input[j] == 9) {
            nextLevel++;
            j+=1;
        }
        
        solve(j, nextLevel, tree, input, ans);
    }
    
    int lengthLongestPath(string input) {
        int ans = 0;
        vector<string> tree(5, "");
        solve(0, 0, tree, input, ans);
        return ans;
    }

int main(int argc, const char * argv[]) {
    lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    return 0;
}
