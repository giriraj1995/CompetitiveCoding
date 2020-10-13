//
//  main.cpp
//  Merge sorted arrays
//
//  Created by Giriraj Saigal on 13/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//



vector<int> solve(vector<vector<int> > &A) {
    
    map<int, int> mp;
    
    for(vector<int> x : A){
        for(int y : x)
            mp[y]++;
    }
        
    vector<int> ans;
    
    for(auto i : mp){
        int k = i.second;
        
        while(k--){
            ans.push_back(i.first);
        }

    }
        
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
