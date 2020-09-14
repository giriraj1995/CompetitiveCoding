#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

int removeDuplicates(vector<int> &A) {
    
    map<int, int> u;
    
    for(int i = 0; i < A.size(); i++){
        
        if(u.find(A[i]) != u.end()){
            map<int, int>::iterator itr;
            itr = u.find(A[i]);
            int s = itr->second;
            u.erase(itr);
            u.insert(make_pair(A[i], ++s));
        } else {
            u.insert(make_pair(A[i], 1));
        }
    }
    
    map<int, int>::iterator itr;
    A.clear();
    int k = 0;
    
    for(itr = u.begin(); itr != u.end() ; itr++){
            A.push_back(itr->first);
            k++;
        if(itr->second > 1){
            A.push_back(itr->first);
            k++;
        }
    }
    
    return k;

}

int main(int argc, const char * argv[]) {
    vector<int> x = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    
    removeDuplicates(x);
    return 0;
}
