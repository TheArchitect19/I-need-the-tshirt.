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
    void f(TreeNode* t,vector<int>& ans){
        if(t==NULL)return;
        ans.push_back(t->val);
        f(t->left,ans);
        f(t->right ,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        f(root,ans);
        return ans;
    }
};