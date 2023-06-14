class Solution {
public:

    bool canCross(vector<int>& arr) {
        int n = arr.size();
        set<int>st;
        map<int,set<int>>mp;
        for(int i =0;i<n;i++){
            mp[arr[i]]=st;
        }
        mp[0]={0};
        for(int i =0;i<n;i++){
            set<int>st=mp[arr[i]];

            for(auto& k:st){
                if(mp.find(arr[i]+k)!=mp.end()){
                    if(k>0){
                        mp[arr[i]+k].insert(k);
                    }
                }
                if(mp.find(arr[i]+k-1)!=mp.end()){
                    if(k-1>0){
                        mp[arr[i]+k-1].insert(k-1);
                    }
                }
                if(mp.find(arr[i]+k+1)!=mp.end()){
                    if(k+1>0){
                        mp[arr[i]+k+1].insert(k+1);
                    }
                }
            }
        }
        if(mp[arr[n-1]].size()==0)return false;
        return true;
    }
};