#include <iostream>
#include <vector>
using namespace std;

long long int gcd(int a, int b){
    
    if(a > b){
        return gcd(b, a);
    }
    
    if(a == 0)
        return b;

    return gcd(b % a, a);
}

long long int LCM(vector<int> n){
    
    if(n.size() == 1)
        return n[0];
    
    long long int ans = n[0];
    
    for(int i = 1; i < n.size(); i++){
        ans = (ans * n[i])/gcd(ans, n[i]);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1,5,3};
    cout<<LCM(x)<<endl;

    return 0;
}
