class Solution {
public:

    int f(int i,vector<int>& nums,vector<int>& dp){
        if(i==0)return nums[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int p = nums[i]+f(i-2,nums,dp);
        int np = f(i-1,nums,dp);

        return dp[i]=max(p,np);

    }


    int rob(vector<int>& nums) {
        

        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = f(n-1,nums,dp);
        return ans;
    }
};