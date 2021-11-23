//
//  main.cpp
//  134. Gas Station
//
//  Created by Giriraj Saigal on 22/11/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

int canCompleteCircuit(vector<int> gas, vector<int> cost) {
        queue<int> q;
        
        for(int i = 0; i < gas.size(); i++)
            q.push(i);
        
        int n = gas.size();
        int count = 0;
        
        int initial_gas = 0;
        int start = 0;
        bool first = false;
        unordered_set<int> st;
        
        st.insert(start);
        
        while(true) {
            int idx = q.front();
            q.pop();
            
            count++;
            initial_gas += gas[idx];
            initial_gas -= cost[idx];
            
            if(count == n && initial_gas >= 0)
                return start;
                        
            if(initial_gas < 0) {
                start = (idx + 1) % n;
                initial_gas = 0;
                count = 0;
                
                if(st.count(start))
                    break;
                else
                    st.insert(start);
            }
            
            q.push(idx);
        }
        
        return -1;
    }

int main(int argc, const char * argv[]) {
    cout << canCompleteCircuit({2,3,4}, {3,4,3}) << endl;
    return 0;
}
