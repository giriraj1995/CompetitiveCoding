//
//  main.cpp
//  71. Simplify Path
//
//  Created by Giriraj Saigal on 12/05/21.
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


string simplifyPath(string path) {
    vector<string> st;
    string x = "";
    
    for(int i = 0; i < (int)path.size(); i++) {
        if(path[i] == '/') {
            if(x.compare("") == 0)
                continue;
            
            if(x.compare(".") == 0){
                x = "";
                continue;
            }
            
            if(x.compare("..") == 0){
                if(st.size() > 0)
                    x.pop_back();
                x = "";
                continue;
            }
            
            st.push_back(x);
            x = "";
        }else{
            x.push_back(path[i]);
        }
    }
    
    if(x.compare("") == 0)
    {
        //do nothing
    }
    else if(x.compare(".") == 0){
        //do nothing
    }
    else if(x.compare("..") == 0){
        if(st.size() > 0)
            x.pop_back();
    }
    else
        st.push_back(x);
    
    string ans = "/";
    
    for(string j : st)
        ans = ans + j + "/";
    
    return ans.compare("/")==0 ? ans : ans.substr(0,(int)ans.size()-1);
}


int main(int argc, const char * argv[]) {
    simplifyPath("/a/./b/../../c/");
    return 0;
}
