class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& costs) {
        if(i == costs.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = costs[i][j] + solve(i+1,j==0?2:j-1, costs);
        int right = costs[i][j] + solve(i+1, j==2?0:j+1, costs);
        
        return dp[i][j] = min(left, right);
    }
    
    int minCost(vector<vector<int>>& costs) {
        dp = vector<vector<int>>(costs.size()+1, vector<int>(costs[0].size()+1, -1));
        return min({solve(0, 0, costs), solve(0, 1, costs), solve(0, 2, costs)});
    }
};
