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
        int ans  ;
        void dfs(TreeNode* root , TreeNode* child)
        {
            if(root==NULL || child==NULL) return ; 
            ans = max(ans , abs(root->val-child->val));
            dfs(root,child->left);
            dfs(root,child->right);
        } 
        void check(TreeNode* root)
        {
            if(!root) return ;
            dfs(root,root->left);
            dfs(root , root->right);
            check(root->left);
            check(root->right);
        }
        int maxAncestorDiff(TreeNode* root) {
            ans = -1; 
            check(root);
            return ans; 

        }
    };