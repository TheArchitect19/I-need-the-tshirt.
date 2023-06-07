class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        int n = h.size();
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || h[st.top()] >= h[i])){
                int temp = h[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else width=i-st.top() -1;
                ans=max(ans,width*temp);
            }
            st.push(i);
        }
        return ans;
    }
};