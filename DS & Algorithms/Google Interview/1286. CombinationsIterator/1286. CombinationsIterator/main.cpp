//
//  main.cpp
//  1286. CombinationsIterator
//
//  Created by Giriraj Saigal on 14/11/21.
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

class CombinationIterator {
public:
    int n;
    int d;
    int st;
    int en;
    string x;
    vector<int> m;
    bool isPossible = true;
    
    void increment(int i) {
        if(i < 0){
            isPossible = false;
            return;
        }
        
        m[i]++;
        
        if(m[i] > n-d+i) {
            increment(i-1);
            if(!isPossible)
                return;
            m[i] = m[i-1]+1;
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        x = characters;
        n = characters.size();
        d = combinationLength;
        m = vector<int>(d);
        
        for(int i = 0; i < d; i++)
            m[i] = i;
    }
    
    string next() {
        string ans;
        
        for(int i = 0; i < d; i++)
            ans.push_back(x[m[i]]);
        
        increment(d-1);
        return ans;
    }
    
    bool hasNext() {
        return isPossible;
    }
};



int main(int argc, const char * argv[]) {
    
      //Your CombinationIterator object will be instantiated and called as such:
    CombinationIterator* obj = new CombinationIterator("abcdefghij", 5);
    
    do{
        cout << obj->next() <<endl;
    }while(obj->hasNext());
    
    return 0;
}
