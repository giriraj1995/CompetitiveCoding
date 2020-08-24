#include <iostream>
#include <vector>
using namespace std;

long long int maxpagesinaBook(vector<int> x, int k){
    int max = INT_MIN;
    long long int sum = 0;
    
    for(int i:x){
        sum += i;
        if(i > max)
            max = i;
    }
    
    long long int i = max;
    long long int j = sum;
    long long int res = -1;
    
    while(i <= j){
        long long int m = i + (j-i)/2;
        long long int no = 1;
        long long int sumx = 0;
        
        for(int p = 0 ; p < x.size();){
            sumx += x[p];
            if(sumx > m){
                no++;
                sumx = 0;
                continue;
            }
            p++;
        }
        if(no == k){
            res = m;
            j = m - 1;
        } else {
            if(no > k)
                i = m + 1;
            else
                j = m - 1;
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
    int k = 26;
    vector<int> b = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24};
    cout<<maxpagesinaBook(b,k)<<endl;
    return 0;
}
