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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            vector<int>cur;
            cout<<"1"<<endl;
            for(int i = st.size();i>0;i--){
                                        cout<<st.size()<<" ";
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
            ans.push_back(cur);
        }
        return ans;
    }
};