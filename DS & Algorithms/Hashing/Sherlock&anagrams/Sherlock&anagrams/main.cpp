//
//  main.cpp
//  Sherlock&anagrams
//
//  Created by Giriraj Saigal on 22/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int sherlockAndAnagrams(string s) {

    unordered_map<string, int> u;

    int count = 0;
    int n = (int)s.size();

    for(int i = 1; i < n; i++){
        
        int sum = 0;

        for(int j = 0; j+i <= n; j++){
            
            string sub = s.substr(j,i);
            sort(sub.begin(), sub.end());
            
            if(u.find(sub) != u.end()){
                sum += u.find(sub)->second;
            }
            
            u[sub]++;
        }
        count += sum;
        u.clear();
    }

    return count;

}


int main(int argc, const char * argv[]) {
    cout<<sherlockAndAnagrams("kkkk");
    return 0;
}
