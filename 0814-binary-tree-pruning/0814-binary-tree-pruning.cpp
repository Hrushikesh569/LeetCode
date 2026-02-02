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
     bool dfs(TreeNode* root)
    {
        if(root==NULL ) return false;
        if(root->val==1) return 1;
        return (dfs(root->left) || dfs(root->right));     
    }
    TreeNode* pruneTree(TreeNode* root) {
            if(!root) return root;
            if(!dfs(root->left))
            {
                root->left  = NULL;
            }
            if(!dfs(root->right))
            {
                root->right = NULL;
            }
            pruneTree(root->left);
            pruneTree(root->right);
            if(root->left==NULL && root->right==NULL && root->val==0) return NULL;
            return root;
    }
};