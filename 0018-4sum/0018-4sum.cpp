class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i =0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            for(int j = i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1])continue;
                int l = j+1;
                int h = n-1;

                while(l<h){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[l];
                    sum+=nums[h];
                    if(sum==target){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);

                        l++;
                        h--;
                        while(l<h and nums[l]==nums[l-1])l++;
                        while(l<h and nums[h]==nums[h+1])h--;
                        
                    }
                    else if(sum>target)h--;
                    else l++;
                }

            }
        }
        return ans;
    }
};