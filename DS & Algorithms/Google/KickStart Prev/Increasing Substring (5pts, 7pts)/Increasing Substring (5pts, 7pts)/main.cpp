#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

void increasing_substring(vector<string> st){
    int t = (int)st.size();
    int r = 0;
    
    while(t--) {
        cout<<"Case #" + to_string(r+1)+": ";
        int n = (int)st[r].size();
        string x = st[r];
        
        int ans = 1;
        cout<<ans<<" ";
        
        for(int i = 1; i < n; i++) {
            if(x[i] > x[i-1]) {
                ans++;
            }else{
                ans = 1;
            }
            
            cout<<ans<<" ";
        }
        
        cout<<endl;
        r++;
    }
    
    return;
}
int main() {
    increasing_substring({"ABBC","ABACDA"});
}
