/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>st;
        st.push(root);
        int x=0;
        while(!st.empty()){
            vector<int>cur;
            cout<<"1"<<endl;
            for(int i = st.size();i>0;i--){
                                        
                TreeNode* node=st.front();
                st.pop();
                cur.push_back(node->val);
                if(node->left){
                    st.push(node->left);
                }
                if(node->right){
                    st.push(node->right);
                }
            }
            if(x%2==0){
                ans.push_back(cur);
                x++;
            }
            else{
                reverse(cur.begin(),cur.end());
                ans.push_back(cur);
                x++;
            }
        }
        return ans;
    }
};