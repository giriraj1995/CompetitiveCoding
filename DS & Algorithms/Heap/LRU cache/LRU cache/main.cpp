//
//  main.cpp
//  LRU cache
//
//  Created by Giriraj Saigal on 23/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int t = 0;
int c;
unordered_map<int,pair<int, int>> store;
map<int, int> T;

void initial(){
    store.clear();
    T.clear();
}

void LRUCache(int capacity) {
    initial();
    c = capacity;
}

int get(int key) {
    
    if(store.find(key) == store.end()){
        return -1;
    }
    
    int time = store.find(key)->second.second;
    T.erase(T.find(time));
    t++;
    T[t] = key;
    
    return store.find(key)->second.first;
}

void set(int key, int value) {
    
    if(store.size() == c){
        
        int k = T.begin()->second;
        T.erase(T.begin());
        store.erase(store.find(k));
    }
    
    t++;
    store[key] = {value,t};
    T[t] = key;
}


int main(int argc, const char * argv[]) {
    LRUCache(2);
    set(1,10);
    set(5,12);
    get(5);
    get(1);
    set(6,40);
    return 0;
}
