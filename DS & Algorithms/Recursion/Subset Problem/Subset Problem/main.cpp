#include <iostream>
#include <vector>
#include "string"
using namespace std;

int func(string x, int n, string out){
    
    if(n == x.size()){
        cout<<out<<endl;
        return 1;
    }
    
    return func(x,n+1,out + x[n]) + func(x,n+1,out);
}

int main(int argc, const char * argv[]) {
    string x = "abc";
    string out = "";
    int n = 0;
    cout<<func(x,n,out)<<endl;
    return 0;
}
