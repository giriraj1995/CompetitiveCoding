//
//  main.cpp
//  ActivityNotification
//
//  Created by Giriraj Saigal on 23/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void insert(vector<int> &x, int data){
    if(x.size() == 0)
    {
        x.push_back(data);
        return;
    }

    x.push_back(data);

    int i = x.size()-1;
    while(i >= 1 && x[i] < x[i-1]){
        int temp = x[i];
        x[i] = x[i+1];
        x[i+1] = temp;

        i--;
    }

    return;
}

void searchInsert(vector<int> &x, int key){
    
    vector<int>::iterator itr;

    if(x.size() == 0)
    {
        x.push_back(key);
        return;
    }

    int i = 0;
    int j = x.size()-1;
    
    while(i < j){
        int m = i + (j-i)/2;
        if(x[m] == key){
            x.insert(x.begin() + m, key);
            return;
        }else{
            if(x[m] < key){
                i = m + 1;
            }else{
                j = m - 1;
            }
        }
    }
    if(i == x.size()){
        x.push_back(key);
    }else{
        x.insert(x.begin()+ i, key);
    }
}

int activityNotifications(vector<int> e, int d) {

    int i = 0;
    vector<int> sp;
    while(i < d){
        searchInsert(sp, e[i]);
        i++;
    }

    int notice = 0;

    while(i < e.size()){

        int c = e[i];
        double m;
        
        if(d & 1){
            m = (double)sp[d/2];
        }else{
            m = sp[d/2] + sp[d/2 - 1];
            m = m/2.0;
        }
        
        if(c >= 2 * m)
            notice++;

        sp.erase(sp.begin());
        searchInsert(sp, e[i++]);
    }

    return notice;

}

int main(int argc, const char * argv[]) {
    activityNotifications({1 ,2 ,3 ,4 ,4}, 4);
    return 0;
}
