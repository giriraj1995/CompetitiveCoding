//
//  main.cpp
//  488. Zuma Game
//
//  Created by Giriraj Saigal on 05/11/21.
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
unordered_map<char, vector<int>> whereTo(string s, string h) {
    
    unordered_map<char, int> mp;
    
    for(int i = 0; c < h.size(); c++) {
        
    }
    
}

void removeGroups(string &s) {
        if(s.size() <= 2)
            return;
        
        string newS = "";
        char prev = s[0];
        int count = 1;
        
        for(int i = 1; i < s.size(); i++) {
            if(prev == s[i]) {
                count++;
                prev = s[i];
            }else{
                
                if(count < 3) {
                    while(count--) {
                        newS.push_back(prev);
                    }
                }
                prev = s[i];
                count = 1;
            }
        }
        
        if(count < 3) {
            while(count--) {
                newS.push_back(prev);
            }
        }
    
        s = newS;
    }
    
    int solve(string board, string hand) {
        
        if(board.size() == 0)
            return 0;
        
        if(hand.size() == 0)
            return -1;
        
        int ans = INT_MAX;
        for(int i = 0; i < hand.size(); i++) {
            char toInsert = hand[i];
            
            for(int j = 0; j < board.size(); j++) {
                string newBoard = board;
                newBoard.insert(newBoard.begin() + j, toInsert);
                //newBoard.insert(j, toInsert);
                
                removeGroups(newBoard);
                
                string newHand = hand;
                newHand.erase(i,1);
                int tempAns = solve(newBoard, newHand);
                
                if(tempAns == -1)
                    continue;
                
                ans = min(ans, tempAns+1);
            }
        }
        
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    int findMinStep(string board, string hand) {
        return solve(board, hand);
    }

int main(int argc, const char * argv[]) {
    cout << findMinStep("WWRRBBWW", "WRBRW") << endl;
    return 0;
}
