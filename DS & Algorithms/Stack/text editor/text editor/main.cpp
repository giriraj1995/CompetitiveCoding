#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string mains = "";
stack<pair<int,string>> s;


void append(string st){
    mains += st;
    s.push({1, st});
}

void removebystring(string st){
    int l = st.size();
    while(l--){
        mains.pop_back();
    }
}

void undo(){
    pair<int,string> k = s.top();
    s.pop();
    if(k.first == 0){
        append(k.second);
    }else{
        removebystring(k.second);
    }
}

void removebylenght(int l){
    string r;
    while(l--){
        r.push_back(mains[mains.size()-1]);
        mains.pop_back();
    }
    reverse(r.begin(), r.end());
    s.push({0, r});
}


int main() {
    int q;
    cin>>q;

    while(s.size() > 0){
        s.pop();
    }

    while(q--){
        
        int qu;
        cin>>qu;

        if(qu == 1){
            string st;
            cin>>st;
            append(st);
        }else if(qu == 2){
            int re;
            cin>>re;
            removebylenght(re);
        }else if(qu == 3){
            int su;
            cin>>su;
            cout<<mains[su-1];
        }else{
            undo();
        }

    }
    return 0;
}

