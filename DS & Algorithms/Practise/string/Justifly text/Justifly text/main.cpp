//
//  main.cpp
//  Justifly text
//
//  Created by Giriraj Saigal on 16/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

vector<string> fullJustify(vector<string> A, int B) {
        if(A.size() == 0)
            return {};
            
        if(A.size() == 1) {
            if(A[0].compare("") == 0)
                return {};
        }
            vector<string> ans;
        int i = 0;
        int s = 0;
        int w = 0;
        string mak = "";
        while(i < A.size()) {
            int g = 0;
            
            if(s != 0)
                g++;
                
            if(A[i].size() + s + g <= B) {
                s += A[i].size() + g;
                if(g) {
                    mak += " "+A[i];
                }else{
                    mak += A[i];
                }
                w++;
                i++;
            }else{
                int left = B - s;
                
                int add, rem;
                if(w != 1){
                    add = left/(w-1);
                    rem = left%(w-1);
                }
                else{
                    add = left;
                    while(add--) mak += " ";
                    
                    w = 0;
                    s = 0;
                    ans.push_back(mak);
                    mak = "";
                    
                    continue;
                    rem = 0;
                }
                bool flag = false;
                for(int i = 0; i < s; i++) {
                    if(!flag && mak[i] == ' ') {
                        for(int j = 0; j < add; j++){
                            mak.insert(mak.begin()+i,' ');
                            i++;
                            s++;
                        }
                        
    //                    for(int j = 0; j < rem; j++){
    //                        mak.insert(mak.begin()+i,' ');
    //                        i++;
    //                        s++;
    //                    }
                        
                        flag = true;
                    }else if(flag && mak[i] == ' '){
                        for(int j = 0; j < add; j++){
                            mak.insert(mak.begin()+i,' ');
                            i++;
                            s++;
                        }
                    }
                }
                
                int j = 0;
                while(rem > 0) {
                    if(mak[j] == ' ' && mak[j-1] != ' '){
                        mak.insert(mak.begin()+j,' ');
                        j++;
                        s++;
                        rem--;
                    }
                    j = (j + 1) % s;
                }
                
                w = 0;
                s = 0;
                ans.push_back(mak);
                mak = "";
            }
        }
        
        if(mak.size() != B) {
            int left = B - s;
            while(left--)
                mak.insert(mak.begin()+s,' ');
        }
        
        ans.push_back(mak);
        
        return ans;
}


int main(int argc, const char * argv[]) {
    fullJustify({"am", "fasgoprn", "lvqsrjylg", "rzuslwan", "xlaui", "tnzegzuzn", "kuiwdc", "fofjkkkm", "ssqjig", "tcmejefj", "uixgzm", "lyuxeaxsg", "iqiyip", "msv", "uurcazjc", "earsrvrq", "qlq", "lxrtzkjpg", "jkxymjus", "mvornwza", "zty", "q", "nsecqphjy"},14);
    return 0;
}
