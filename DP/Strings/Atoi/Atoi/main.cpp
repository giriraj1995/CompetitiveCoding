#include <iostream>
#include <vector>
using namespace std;

int convert(vector<int> x){
    int n = x.size();
    
    if(n == 0)
        return 0;

    long long int g = x[0];
    int i = 1;
    while(--n>0){
        g = g * 10 + x[i];
        i++;
        
        if(g > INT_MAX)
            return INT_MAX;
    }
    return g;
}

int atoi1(const string A) {
    int n = A.size();
    
    if(n == 0)
        return 0;
    
    vector<int> x;
    int flag = 0;
    int neg = 0;
    int pos = 0;
    
    for(char c: A){
        if(c == '-')
        {
            if(neg == 0 && flag == 0){
                neg = 1;
                flag = 1;
            }
            else
                break;
        }
        else if(c == '+')
        {
            if(pos == 0 && flag == 0){
                flag = 1;
                pos = 1;
            }
            else
                break;
        }
        else if((c >= 48 && c <= 57))
        {
            flag = 1;
            x.push_back(c - '0');
        }
        else if(c == ' ' && flag == 0)
        {
            continue;
        }
        else
            break;
    }
    
    if(x.size() > 10){
        if(neg == 1)
            return INT_MIN;
        else
            return INT_MAX;
    }
    
    long long int r = convert(x);
    
    if(neg == 1 and r == INT_MAX)
        return INT_MIN;
        
    if(neg == 1)
        return r * -1;
    
    return r;
    
}



int main(int argc, const char * argv[]) {
    cout<<atoi1("-88297")<<endl;
    return 0;
}
