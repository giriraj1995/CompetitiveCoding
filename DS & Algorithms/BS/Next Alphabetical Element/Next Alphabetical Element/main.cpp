#include <iostream>
#include <vector>
using namespace std;

char bs(vector<char> x, int i, int j ,char key){
    char res = '#';
    while (i <= j) {
        int m = i + (j-i)/2;
        
        if(key == x[m])
        {
            i = m + 1;
        } else {
            if(key < x[m]){
                res = x[m];
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<char> x = {'a', 'c', 'h', 'k'};
    
    cout<<bs(x, 0, (int)x.size()-1, 'a')<<endl;
    
    return 0;
}
