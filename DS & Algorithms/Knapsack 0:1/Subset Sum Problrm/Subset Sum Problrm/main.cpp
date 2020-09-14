#include <iostream>
#include <vector>
using namespace std;

void show(int n ,int w, bool *t[n+1]){
    for(int i = 0; i<= n; i++)
    {
        for(int j = 0; j<= w; j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool subSetSum(vector<int> &a, int w){
    int n = (int)a.size();
    bool *t[n+1];
    
    for(int i = 0 ; i< n+1; i++)
        t[i] = new bool[w+1];
    
    for(int i = 0; i<= n; i++)
    {
        for(int j = 0; j<= w; j++)
        {
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }
    //show(n, w, t);
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= w; j++)
        {
            if(a[i-1] <= j)
            {
                t[i][j] = t[i-1][j-a[i-1]] | t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    //show(n, w, t);
    return t[n][w];
}

int main(int argc, const char * argv[]) {
    vector<int> a = {2,5,7,4};
    a.clear();
    int w = 25;
    cout<<"Subset Sum ? \n"<<subSetSum(a,w)<<endl;
    
    return 0;
}
