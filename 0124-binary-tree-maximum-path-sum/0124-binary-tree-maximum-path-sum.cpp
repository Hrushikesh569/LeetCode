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
    int maxi ;
    int mini = -1e6;
    int dfs(TreeNode* root)
    {
        if(!root) return -1e9 ; 
       int left = dfs(root->left);
       int right = dfs(root->right);
       int val1 = left+root->val+right;
       int val2 = max(left,right)+root->val;
       int val3 = max({left,right,root->val});
       maxi = max({val1,val2,val3,maxi});
       return max(val2,root->val);
    }
    int maxPathSum(TreeNode* root) {
        maxi = -1e9;
        dfs(root);
        return maxi;
    }
};