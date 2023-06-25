class Solution {
public:
    int f(int n , int k, vector<vector<int>>&dp){
        if(n<=1)return n;
        if(k==1)return n;

        if(dp[n][k]!=-1)return dp[n][k];


        
        int ans =INT_MAX;
        for(int i = 1;i<n;i++){
            ans= min(ans, max(f(i-1,k-1,dp),f(n-i,k,dp))+1);
        }
        return dp[n][k]=ans;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        int a = f(n,2,dp);
        return a;
    }
};