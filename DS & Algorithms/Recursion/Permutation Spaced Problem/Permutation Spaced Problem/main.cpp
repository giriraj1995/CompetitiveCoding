#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>
using namespace std;

vector<string> ans;
void solve(string out, string inp){
    
    if(inp.length() == 1)
    {
        ans.push_back(out + inp);
        return;
    }
    
    string out1 = out, out2 = out;
    
    out1.push_back(inp[0]);
    out2.push_back(inp[0]);
    inp.erase(inp.begin()+0);
    out1.push_back('#');
    solve(out1, inp);
    solve(out2, inp);
}

int main(int argc, const char * argv[]) {
    string x;
    cout<<"Enter string: ";
    cin>>x;
    solve("",x);
    
    map<string,int> u;
    
    for(int i = 0; i < ans.size(); i++){
        u.insert(make_pair(ans[i], i));
    }
    
    return 0;
}

