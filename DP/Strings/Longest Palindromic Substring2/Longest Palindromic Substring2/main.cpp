#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solve(string str){
    string ans;
    int n = (int)str.size();
    int start = 0;
    int maxLength = 1;
    int h;
    int l;
    
    for(int i = 1; i < n ; i++){
        l = i - 1;
        h = i;
        
        while(l >= 0 && h < n && str[l] == str[h]){
            if(h-l+1 > maxLength){
                start = l;
                maxLength = h-l+1;
            }
            l--;
            h++;
        }
        
        l = i - 1;
        h = i + 1;
        
        while(l >= 0 && h < n && str[l] == str[h]){
            if(h-l+1 > maxLength){
                start = l;
                maxLength = h-l+1;
            }
            l--;
            h++;
        }
    }
    
    for(int j = start; maxLength--; j++){
        ans.push_back(str[j]);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    string k = "forgeeksskeegfor";
    cout<<solve(k)<<endl;
    return 0;
}
