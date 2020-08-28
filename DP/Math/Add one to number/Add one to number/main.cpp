#include <iostream>
#include <vector>
using namespace std;


vector<int> elimateZeros(vector<int> x){
 int n = x.size();
 vector<int> ans;
 int i = 0;
 int z = 0;
 while(i < n)
 {
     if(x[i] == 0)
         z++;
     else
         break;
         
     i++;
 }
 
 for(i = z; i < n; i++)
     ans.push_back(x[i]);
     
 return ans;
}

vector<int> plusOne(vector<int> &A) {
    
    int n = A.size();
    vector<int> ans;
    if(n == 0)
        return ans;
        
    reverse(A.begin(), A.end());
    
    int carry = 1;
    int i = 0;
    
    while(i < n){
        
    if(carry == 0){
            ans.push_back(A[i]);
            carry = 0;
    }else if(carry ==1){
        if(A[i] == 9){
            carry = 1;
            ans.push_back(0);
        }else{
            ans.push_back(A[i]+1);
            carry = 0;
        }
    }
    i++;
    }
    
    if(carry == 1)
        ans.push_back(1);

    reverse(ans.begin(), ans.end());
    
    return elimateZeros(ans);
    
}

int main(int argc, const char * argv[]) {
    vector<int> x = {9,8,9,9,9,9,9,9,9,9,9,9};
    plusOne(x);
    return 0;
}
