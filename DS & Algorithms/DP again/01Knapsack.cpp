int ans;
vector<vector<int>> dp;
int solvee(vector<int> &A, vector<int> &B, int i, int C) {
    if(i == A.size()){
        return 0;
    }
    
    if(dp[i][C] != -1)
        return dp[i][C];
    
    int a = 0;
    int b = 0;
    if(B[i] <= C) {
        a = solvee(A,B,i+1,C-B[i]);
        b = solvee(A,B,i+1,C);
        return dp[i][C]=max(A[i] + a, b);
    }
    
    b = solvee(A,B,i+1,C);
    return dp[i][C]=b;
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    dp = vector<vector<int>>(A.size()+1, vector<int>(C+1, -1));
    return solvee(A,B,0,C);
}
