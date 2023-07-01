class Solution {
public:

    int f(int i , int j,vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n=grid.size();
        if(i>=n or j>i )return 1e9;
        if(i==n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int op1 =grid[i][j]+f(i+1,j,grid,dp);
        int op2 =grid[i][j]+f(i+1,j+1, grid,dp);
        return dp[i][j]=min(op1, op2);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int ans = f(0,0,grid,dp);
        return ans;
    }
};