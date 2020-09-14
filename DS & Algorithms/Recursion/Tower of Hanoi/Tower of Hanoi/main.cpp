#include <iostream>
#include <vector>
using namespace std;

int calls = 0;
void TOH(int n, string a, string b, string c)
{
    if(n == 1)
    {
        calls++;
        string x = "Shift " + a + " to " + c;
        cout<<x<<endl;
        return;
    }
    
    TOH(n-1, a, c, b);
    TOH(1, a, b, c);
    TOH(n-1, b, a, c);
}

int main(int argc, const char * argv[]) {
    int n = 10;
    TOH(n,"S","H","D");
    cout<<calls/(60.0*60.0*24.0)<<endl;
    vector<int> x = {1,2};
    x.erase(x.begin()+0);
    cout<<x[0];
    return 0;
}
