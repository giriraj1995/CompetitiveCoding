//
//  main.cpp
//  6016. Cells in a Range on an Excel Sheet
//
//  Created by Giriraj Saigal on 06/03/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

vector<string> cellsInRange(string s) {
        vector<string> ans;
        int i = -1;
        
        for(i = 0; i < s.size(); i++) {
            if(s[i] == ':')
                break;
        }
        
        string first = s.substr(0, i);
        string second = s.substr(i+1);
        
        char c0 = first[0];
        string r0 = first.substr(1);
        char c1 = second[0];
        string r1 = second.substr(1);
        
        for(char c = c0; c <= c1; c++) {
            for(int t = stoi(r0); t <= stoi(r1); t++){
                    ans.push_back(c + to_string(t));
                }
        }
        
        return ans;
    }

long long minimalKSum(vector<int> nums, int k) {
    nums.push_back(0);
        nums.push_back(INT_MAX);
            sort(nums.begin(), nums.end());
            long long ans = 0;
            
            for(int i = 0; i < nums.size()-1; i++) {
                long long left = nums[i];
                long long right = nums[i+1];
                
                int total = max(right - left - 1, 0ll);
                long long n = min(total, k);
                k -= n;
                ans += (n * (2 * (left+1) + (n-1))) / 2;
                
                if(k == 0)
                    break;
            }
            
            return ans;
    }

vector<int> replaceNonCoprimes(vector<int> nums) {
        stack<int> s;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            s.push(nums[i]);
        }
        
        vector<int> ans;
        while(s.size() >= 2) {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            
            int g = gcd(first, second);
            if(g > 1) {
                s.push(first / g * second);
                if(ans.size() > 0){
                    s.push(ans[ans.size()-1]);
                    ans.pop_back();
                }
            }else{
                ans.push_back(first);
                s.push(second);
            }
        }
        
        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    //cellsInRange("K1:L2");
    //minimalKSum({96,44,99,25,61,84,88,18,19,33,60,86,52,19,32,47,35,50,94,17,29,98,22,21,72,100,40,84},35);
    replaceNonCoprimes({287,41,49,287,899,23,23,20677,5,825});
    return 0;
}
