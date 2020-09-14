#include <iostream>
#include <vector>
#include <string>
using namespace std;

int isPalindrom(string x){
    int n = x.size();
    
    int i = 0;
    int j = n-1;
    
    while(i < n && j < n){
        while( x[i] > 122
        || x[i] < 48
        || (x[i] > 57 && x[i] < 65)
        || (x[i] > 90 && x[i] < 97)){
            i++;
            if
        }
        
        while( x[j] > 122
        || x[j] < 48
        || (x[j] > 57 && x[j] < 65)
        || (x[j] > 90 && x[j] < 97)){
            j--;
        }
        
        if(x[i] == x[j] || x[i] == x[j]+32 || x[i] == x[j]-32){
            i++;
            j--;
        } else
            return 0;
    }
    
    return 1;
}

int isPalindrome(string a) {
    
    if(a.size() == 0 || a.size() == 1)
        return 1;
    
    return isPalindrom(a);
}


int main(int argc, const char * argv[]) {
    string a = ".,";
    cout<<isPalindrome(a);
    return 0;
}
