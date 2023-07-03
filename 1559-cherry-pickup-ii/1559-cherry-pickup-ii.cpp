class Solution {
public:
    int f(int i,int j1, int j2,int n , int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=m || j2>=m || j2<0)return -1;

        if(i==n-1){
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int mx=0;
        for(int dj =-1;dj<=1;dj++){
            for(int dj2=-1;dj2<=1;dj2++){
                int v=0;
                if(j1==j2){
                    v=grid[i][j1];
                }
                else{
                   v=grid[i][j1]+grid[i][j2];
                }
                v+=f(i+1,j1+dj,j2+dj2,n,m,grid,dp);
                mx=max(mx,v);
            }
        }
        return dp[i][j1][j2]=mx;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int ans = f(0,0,m-1,n,m,grid,dp);
        return ans;
    }
};