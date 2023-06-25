class Solution {
public:

    int f(int i, vector<int>&arr, int k,vector<int>&dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int l  =0;
        int maxi= INT_MIN;
        int ans = INT_MIN;
        int  n  = arr.size();
        for(int j = i;j<min(n, i+k);j++){
            l++;
            maxi= max(maxi,arr[j]);
            int sum = l*maxi + f(j+1,arr,k,dp);
            ans= max(ans, sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        int a = f(0,arr,k,dp);
        return a;
    }
};