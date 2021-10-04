//
//  main.cpp
//  Max substrings without overlap
//
//  Created by Giriraj Saigal on 03/10/21.
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

    
//int findEnd(int st, string s, unordered_map<char, vector<int>> &mp) {
//    int end = st;
//
//    for(int i = st; i <= end; i++) {
//        end = max(mp[s[i]][1], end);
//
//        if(mp[s[i]][0] < st)
//            return -1;
//    }
//
//    return end;
//}
//
//vector<string> maxNumOfSubstrings(string s) {
//    unordered_map<char, vector<int>> mp;
//
//    for(int i = 0; i < s.size(); i++){
//        if(mp.count(s[i])) {
//            mp[s[i]][1] = i;
//        }else{
//            mp[s[i]] = {i,i};
//        }
//    }
//
//    int n = s.size();
//    int subStringStart = -1;
//
//    vector<string> ans;
//    for(int i = 0; i < n; i++) {
//        int subStringEnd = findEnd(i, s, mp);
//        if(subStringEnd != -1) {
//            if(subStringEnd > subStringStart) {
//                ans.push_back("");
//            }
//            subStringStart = subStringEnd;
//            ans[ans.size()-1] = s.substr(i,subStringStart-i+1);
//        }
//    }
//
//    return ans;
//}

// bool customSort(pair<int, int>& p1, pair<int, int>& p2) {
//        return p1.second - p1.first < p2.second - p2.first;
//    }
//    bool isOverlap(vector<pair<int, int>>& arr, int start, int end) {
//        if (arr.empty()) return false;
//
//        for (auto idxs : arr) {
//            int s = idxs.first, e = idxs.second;
//            if (end >= s && e >= start) return true;
//        }
//        return false;
//    }
//    vector<string> maxNumOfSubstrings(string s) {
//        unordered_map<char, pair<int, int>> dict;
//        vector<string> ans;
//        for (int i = 0; i < s.length(); ++i) {
//            if (dict.count(s[i])) dict[s[i]].second = i;
//            else dict[s[i]] = {i, i};
//        }
//
//
//        for (auto& d : dict) {
//            int& start = d.second.first;
//            int& end = d.second.second;
//            stack<pair<int, int>> st;
//            st.push({start, end});
//            while (!st.empty()) {
//                pair<int, int> p = st.top();
//                st.pop();
//                int currStart = p.first, currEnd = p.second;
//                for (int i = currStart; i <= currEnd; ++i) {
//                    if (dict[s[i]].first < start) {
//                        st.push({dict[s[i]].first, start - 1});
//                        start = dict[s[i]].first;
//                    }
//                    if (dict[s[i]].second > end) {
//                        st.push({end + 1, dict[s[i]].second});
//                        end = dict[s[i]].second;
//                    }
//                }
//            }
//        }
//
//        vector<pair<int, int>> subIdxs;
//        for (auto d : dict)
//            subIdxs.push_back(d.second);
//
//        sort(subIdxs.begin(), subIdxs.end(), customSort);
//
//        vector<pair<int, int>> seenIdxs;
//
//        for (auto idxs : subIdxs) {
//            int start = idxs.first, end = idxs.second;
//            if (isOverlap(seenIdxs, start, end)) continue;
//            seenIdxs.push_back({start, end});
//            ans.push_back(s.substr(start, end - start + 1));
//        }
//
//        return ans;
//    }

 bool customsort(pair<int,int> p1, pair<int,int> p2) {
        return p1.second - p1.first < p2.second - p1.first;
    }
    
    bool overlap(pair<int,int> p, vector<pair<int,int>> known) {
        for(int i = 0; i < known.size(); i++) {
        if(p.first <= known[i].second && p.second >= known[i].first)
                return true;
        }
        
        return false;
    }

    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int,int>> mp;
        
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(mp.count(c)) {
                mp[c].second = i;
            }else{
                mp[c] = {i,i};
            }
        }
        
        vector<pair<int,int>> vec;
        
        for(auto k : mp){
            vec.push_back({k.second.first,k.second.second});
        }
        
        for(int k = 0; k < vec.size(); k++) {
        int start = vec[k].first;
            int end = vec[k].second;
            
            stack<pair<int,int>> st;
            st.push({start,end});
            while(st.size() > 0) {
                int low = st.top().first;
                int high = st.top().second;
                st.pop();
                
                for(int d = low; d <= high; d++) {
                    if(mp[s[d]].first < start) {
                        start = mp[s[d]].first;
                        st.push({start, low-1});
                    }
                    if(mp[s[d]].second > end){
                        end = mp[s[d]].second;
                        st.push({high+1,end});
                    }
                }
            }
            
            vec[k].first = start;
            vec[k].second = end;
        }
        
        sort(vec.begin(), vec.end(), customsort);
        
        vector<pair<int,int>> known;
        
        for(int i = 0; i < vec.size(); i++) {
            if(!overlap(vec[i], known)){
                known.push_back(vec[i]);
            }
        }
        
        vector<string> ans;
        
        for(int i = 0; i < known.size(); i++) {
            ans.push_back(s.substr(known[i].first,known[i].second-known[i].first+1));
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    maxNumOfSubstrings("adefaddaccc");
    return 0;
}
