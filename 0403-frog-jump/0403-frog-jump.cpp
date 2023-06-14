class Solution {
public:
    map<int,bool>st;
    bool helper(long long pre, long long pos,map<pair<int,int>,bool>&dp, vector<int>arr, int n){

           
        
        if(pos>arr[n-1] || st[pos]==false)return 0;
        if(pos==arr[n-1])return true;
        if(dp.find({pre,pos})!=dp.end())return dp[{pre,pos}];

        bool ok; 
        if(pos==0){
            ok= helper(1,pos+1,dp,arr,n);
        }
        else{
            if(pre-1>0)ok = helper(pre-1,pos+pre-1,dp,arr,n);
            if(ok)return true;
            ok = helper(pre,pos+pre,dp,arr,n);
            if(ok)return true;
            ok = helper(pre+1,pos+pre+1,dp,arr,n);
            if(ok)return true;
        }
        dp[{pre,pos}]=ok;
        return ok;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<pair<int,int>,bool>dp;
    
        for(auto & i:stones){
            st[i]=true;;
        }

        return helper(1,0,dp,stones,n);


    }
};