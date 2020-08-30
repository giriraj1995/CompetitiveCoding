#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>
using namespace std;

vector<string> ans;
void subset(string out, string inp){
    
    if(inp.length() == 0){
        
        ans.push_back(out);
        return;
        
    }
    
    string out1 = out;
    string out2 = out;
    
    out2.push_back(inp[0]);
    inp.erase(inp.begin() + 0);

    subset(out1, inp);
    subset(out2, inp);
    
    return;
}

int main(int argc, const char * argv[]) {
    string x;
    cout<<"Enter string to find Subsets: ";
    cin>>x;
    
    subset("", x);
    
    map<string, string> u;
    
    for(int i = 0; i < ans.size() ; i++){
        u.insert(make_pair(ans[i],ans[i]));
    }
    
    map<string, string>::iterator itr;
    
    for(auto &f:u){
        cout<<f.first<<endl;
    }
    
    return 0;
}
