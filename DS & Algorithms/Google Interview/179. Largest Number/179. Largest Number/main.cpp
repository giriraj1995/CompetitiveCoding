//
//  main.cpp
//  179. Largest Number
//
//  Created by Giriraj Saigal on 21/09/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;


static bool cmp(string &x, string &y) {
    return (x+y > y+x);
}

string largestNumber(vector<int> nums) {
    vector<string> x;
    
    for (auto &it : nums)
    {
        x.push_back(to_string(it));
    }
    
    sort(x.begin(), x.end(), cmp);
    string ans = "";

    for(string j : x){
        ans += j;
    }

    while(ans.size() > 0) {
        if(ans[0] == '0'){
            ans.erase(ans.begin());
        }else{
            break;
        }
    }

    return ans == "" ? "0" : ans;
}

static bool comp(string &a, string &b)
    {
        return a + b > b + a;
    }
    string largestNumber1(vector<int> nums)
    {
        if (nums.empty())
            return "";
        vector<string> container;
        for (auto &it : nums)
        {
            container.push_back(to_string(it));
        }
        sort(container.begin(), container.end(), comp);
        string ans = "";
        for (auto &it : container)
        {
            ans += it;
        }
        // edge case if ans[0] comes 0 then we should return only '0' not "00"
        return ans[0] == '0'?"0" : ans;
    }
int main(int argc, const char * argv[]) {
    largestNumber({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    return 0;
}
