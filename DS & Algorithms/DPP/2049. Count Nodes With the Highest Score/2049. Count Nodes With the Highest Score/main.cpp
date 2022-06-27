//
//  main.cpp
//  2049. Count Nodes With the Highest Score
//
//  Created by Giriraj Saigal on 14/06/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

struct Node {
        Node* left;
        Node* right;
    int curr;
    };
    
    int solve(Node* p, Node* prev, int &maxScore, int &noWithMaxScore, int n) {
        if(p == NULL)
            return 0;
        
        int l = solve(p->left, p,maxScore, noWithMaxScore, n);
        int r = solve(p->right, p,maxScore, noWithMaxScore, n);
        
        cout << l << endl;
        cout << r << endl;
        cout << ((prev == NULL) ? 1 : ((n-1)-(l==0?0:l)-(r==0?0:r))) << endl;
        if(((l==0?1:l) * (r==0?1:r) * ((prev == NULL) ? 1 : ((n-1)-(l==0?0:l)-(r==0?0:r)))) > maxScore) {
            maxScore = ((l==0?1:l) * (r==0?1:r) * ((prev == NULL) ? 1 : ((n-1)-(l==0?0:l)-(r==0?0:r))));
            noWithMaxScore = 1;
        }else if(((l==0?1:l) * (r==0?1:r) * ((prev == NULL) ? 1 : ((n-1)-(l==0?0:l)-(r==0?0:r)))) == maxScore) {
            noWithMaxScore++;
        }
        
        return l+r+1;
    }
    
    int countHighestScoreNodes(vector<int> parents) {
        int n = parents.size();
        unordered_map<int,Node* > mp;
        for(int i = 0; i < n; i++) {
            mp[i] = new Node();
            mp[i]->left = mp[i]->right = NULL;
            mp[i]->curr = i;
        }
        
        for(int i = 0; i < n; i++) {
            int p = parents[i];
            int c = i;
            if(p != -1)
                (mp[p]->left == NULL) ? mp[p]->left = mp[c] : mp[p]->right = mp[c];
        }
        
        int maxScore = 0;
        int noWithMaxScore = 0;
        
        solve(mp[0], NULL, maxScore, noWithMaxScore, n);
        return noWithMaxScore;
    }

int main(int argc, const char * argv[]) {
    countHighestScoreNodes({-1,3,3,5,7,6,0,0});
    return 0;
}
