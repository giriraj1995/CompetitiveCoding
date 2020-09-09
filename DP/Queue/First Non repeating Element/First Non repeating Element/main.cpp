//
//  main.cpp
//  First Non repeating Element
//
//  Created by Giriraj Saigal on 10/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


int main(int argc, const char * argv[]) {
    
    string y = "abcabc";
    string ans;
    queue<char> q;
    int arr[26] = {0};
    
    for(char c : y){
        q.push(c);
        arr[c - 'a']++;
        
        while(!q.empty()){
            
            if(arr[q.front() - 'a'] > 1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty()){
            ans.push_back('#');
        }
    }
    
    
    cout<<ans<<endl;
    
    return 0;
}
