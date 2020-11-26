//
//  main.cpp
//  seats greedy
//
//  Created by Giriraj Saigal on 26/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int diff(vector<int> so, vector<int> c){
    
    int n = so.size();
    int diff = 0;
    for(int i = 0; i < n; i++) {
        diff += abs(so[i] - c[i]);
    }
    
    return diff;
    
}

int seats(string A) {
    
    vector<int> seatsOccupied;
    
    int seats_taken = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 'x'){
            seatsOccupied.push_back(i);
            seats_taken++;
        }
    }
    
    if(seats_taken == 0){
        return 0;
    }
    
    int i = seatsOccupied[0];
    int j = seatsOccupied[seats_taken-1];
    
    vector<int> t;
    int k = i;
    while(k < i + seats_taken) {
        t.push_back(k);
        k++;
    }
    
    int check = diff(seatsOccupied, t);
    
    while(k <= j)
    {
        t.erase(t.begin());
        t.push_back(k++);
        check = min(check, diff(seatsOccupied, t));
    }
    
    return check;
    
}


int main(int argc, const char * argv[]) {
    cout<<seats("..x..");
    cout<<endl;
    return 0;
}
