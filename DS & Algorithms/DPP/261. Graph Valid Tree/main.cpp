class Solution {
public:
    
    bool solve(int parent, int u, vector<int> &visited, unordered_map<int, vector<int>> &mp) {
        
        visited[u] = 2;

        for(int v : mp[u]) {
            if(v == parent)
                continue;
            
            if(visited[v] == 2)
                return false;
            
            if(!solve(u, v, visited, mp))
                return false;
        }
        
        return true;    
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        
        for(auto k : edges) {
            mp[k[0]].push_back(k[1]);
            mp[k[1]].push_back(k[0]);
        }
        
        vector<int> visited(vector<int>(n, 0));
        
        bool ans = solve(-1, 0, visited, mp);
        
        if(ans == false)
            return ans;
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0)
                return false;
        }
        
        return true;
    }
};
