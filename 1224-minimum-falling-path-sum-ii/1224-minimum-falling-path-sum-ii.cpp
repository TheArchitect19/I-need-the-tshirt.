class Solution {
public:

    int f(int i, int last, vector<vector<int>>& grid, int m,vector<vector<int>>& dp){
        if(i==0){
            int mi = INT_MAX;

            for(int j= 0;j<m;j++){
                if(j!=last){
                    mi= min(mi,grid[0][j]);
                }
            }
            return dp[0][last]=mi;
        }
        if(dp[i][last]!=-1)return dp[i][last];
        int mi=INT_MAX;
        for(int j=0;j<m;j++){
            if(j!=last){
                int p = grid[i][j] + f(i-1,j,grid,m,dp);
                mi= min(mi,p);
            }
        }
        return dp[i][last]=mi;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m+2,-1));
        int ans= f(n-1,m+1,grid, m,dp);
        return ans;
    }
};