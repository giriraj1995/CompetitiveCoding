#include <iostream>
#include <vector>
using namespace std;

int lenght(vector<int> A){
    int n = A.size();
    
    if(n == 0 || n == 1 || n == 2)
        return n;
    
    int d = A[1] - A[0];
    int p = d;
    int lenght = 2;
    int max = 1;
    
    for(int i = 2; i < n; i++){
        
        int x = A[i] - A[i-1];
        
        if(x == p)
        {
            lenght++;
        }
        else
        {
            lenght = 2;
        }
        
        if(lenght > max)
            max = lenght;
        
        p = x;
        
    }
    
    return max;
    
}


int main(){
    
    int t;
    cin>>t;
    int d = 1;
    
    while(d <= t){
        int n;
        cin>>n;
        vector<int> x;
        int val;
        
        for(int i = 0; i < n; i++){
            cin>>val;
            x.push_back(val);
        }
        int ans = lenght(x);
        cout<<"Case #"<<d<<": "<<ans<<endl;
        d++;
    }
    
    return 0;
}
