#include <iostream>
#include <vector>
using namespace std;

string solve1(string A){
    string B = A;
    reverse(B.begin(), B.end());
    int n = (int)A.size();
    int t[n+1][n+1];
    string ans;
    
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0; j <= n; j++){
            cout<<t[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    
    int xi, yj;
    int max = INT_MIN;
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= n; j++){
            if(A[i-1] == B[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
                if(t[i][j] > max){
                    max = t[i][j];
                    xi = i-1;
                    yj = j-1;
                }
            } else {
                t[i][j] = 0;
            }
        }
        
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0; j <= n; j++){
                cout<<t[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    while(max--){
        ans.push_back(A[xi--]);
    }
    return ans;
}

string solve(string str){
  
  int maxLength = 1;
  int start = 0;
  int len = str.size();
  int low, high;
  
  for(int i = 1 ; i < len ; i++){
      low = i - 1;
      high = i;
      while (low >= 0 && high < len
             && str[low] == str[high]) {
          if (high - low + 1 > maxLength) {
              start = low;
              maxLength = high - low + 1;
          }
          --low;
          ++high;
      }
      
      low = i - 1;
      high = i + 1;
      while (low >= 0 && high < len && str[low] == str[high]) {
          if (high - low + 1 > maxLength) {
              start = low;
              maxLength = high - low + 1;
          }
          --low;
          ++high;
      }
  }

  string d = str.substr(start, start + maxLength);
    return d;
  }

string longestPalindrome(string A) {
    string x;
    if(A.size() == 0)
        return x;
    
    return solve(A);
}

int main(int argc, const char * argv[]) {
    cout<<longestPalindrome("abacdfgdcaba");
    return 0;
}
