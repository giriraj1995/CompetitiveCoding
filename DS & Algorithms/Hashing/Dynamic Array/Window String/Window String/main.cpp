//
//  main.cpp
//  Window String
//
//  Created by Giriraj Saigal on 18/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool check(map<char, bool> u){
    
    for(auto i : u){
        if(i.second == false)
            return false;
    }
    
    return true;
}

string minWindow(string A, string B) {
      vector<int> x(128, 0);
      
      for(int i = 0; i < B.size(); i++){
          x[B[i]]++;
      }
      
      int l = INT_MAX;
      int minStart = 0;
      int rem = B.size();
      int end = 0;
      int st = 0;
      
      while(end < A.size()){
          
          x[A[end]]--;
          
          if(x[x[end]] >= 0)
              rem--;
              
          end++;
          
          while(rem == 0){
              
              if(end - st < l){
                  l = end-st;
                  minStart = st;
              }
              
              x[A[st]]++;
              
              if(x[A[st]] > 0)
                  rem++;
                  
              st++;
              
          }
          
      }
      
      if(l == INT_MAX)return "";
      
      return A.substr(minStart, l);
        
}


int main(int argc, const char * argv[]) {
    cout<<minWindow("ADOBECODEBANC", "ABC")<<endl;
    return 0;
}
