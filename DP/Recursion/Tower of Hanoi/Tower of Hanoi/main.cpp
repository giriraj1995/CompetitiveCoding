#include <iostream>
#include <vector>
using namespace std;

void TOH(int n, string a, string b, string c)
{
    if(n == 1)
    {
        string x = "Shift " + a + " to " + c;
        cout<<x<<endl;
        return;
    }
    
    TOH(n-1, a, c, b);
    TOH(1, a, b, c);
    TOH(n-1, b, a, c);
}

int main(int argc, const char * argv[]) {
    int n = 1;
    TOH(2,"A","B","C");
    return 0;
}
