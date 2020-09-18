//
//  main.cpp
//  Ransom String
//
//  Created by Giriraj Saigal on 17/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {

    map<string, int> u;

    for(string x : magazine) {
        if(u.find(x) != u.end()){
            int d = u.find(x)->second;
            u.erase(u.find(x));
            u.insert(make_pair(x, d+1));
        }else
            u.insert(make_pair(x, 1));
    }

    int flag = 0;

    for(string x : note) {
        if(u.find(x) == u.end()){
            flag = 1;
            break;
        }else{
            int d = u.find(x)->second;
            if(d == 0){
                flag = 1;
                break;
            }else{
                u.erase(u.find(x));
                u.insert(make_pair(x, d-1));
            }
        }
    }

    if(flag == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}

int main(int argc, const char * argv[]) {
    checkMagazine({"twO", "twO"}, {"two", "times", "two", "is", "four"});
    return 0;
}
