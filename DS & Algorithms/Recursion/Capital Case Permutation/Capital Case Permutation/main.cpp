#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> ans;
map<string, int> u;
void solve(string i, string o){
    
    if(i.size() == 0)
    {
        u.insert(make_pair(o, rand()));
        ans.push_back(o);
        return;
    }
    
    string o1 = o;
    string o2 = o;
    
    char c = i[0];
    i.erase(i.begin() + 0);
    
    o1 = o1 + char((int)c-32);
    o2 = o2 + c;
    
    solve(i, o1);
    solve(i, o2);
}

int main(int argc, const char * argv[]) {
    
    string x;
    cin>>x;
    
    solve(x, "");
    
    x[0] = toupper(x[0]);
    x[1] = tolower(x[1]);

    cout<<x<<endl;
    return 0;
}
