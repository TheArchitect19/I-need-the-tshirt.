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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            vector<int>cur;
            for(int i =q.size();i>0;--i){
                TreeNode* N = q.front();
                q.pop();
                cur.push_back(N->val);
                if(N->left){
                    q.push(N->left);
                }
                if(N->right){
                    q.push(N->right);
                }
            }
            ans.push_back(cur);
        }
        return ans.size();

    }
};