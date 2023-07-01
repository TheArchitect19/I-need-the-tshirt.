class Solution {
public:

    int f(int i , int j,vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n=grid.size();
        int m = grid[0].size();
        if(i>=n or j>=m )return 1e9;
        if(i==n-1 and j==m-1)return grid[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int op1 =grid[i][j]+f(i+1,j,grid,dp);
        int op2 =grid[i][j]+f(i,j+1, grid,dp);

        

        return dp[i][j]=min(op1, op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m,-1));
        int ans = f(0,0,grid,dp);

        for(auto& i:dp){
            for(auto& j: i){
                cout<<j<<" ";
            }cout<<endl;
        }

        return ans;

        
        
    }
};