class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j =0;
        int ans=0;
        for(int i =0;i<g.size();i++){
            // int j=0;
            while(j<s.size()){
                if(s[j]>=g[i]){
                    ans++;
                    j++;
                    break;
                }
                j++;
            }
        }
        cout<<j;
        return ans;
    }
};