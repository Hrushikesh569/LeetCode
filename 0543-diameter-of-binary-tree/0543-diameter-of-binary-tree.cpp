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
    int maxi = 0 ; 
    int dfs(TreeNode* root)
    {
        if(!root) return 0 ;
        int ans1 = dfs(root->left);
        int ans2 = dfs(root->right);
        maxi = max(ans1+ans2,maxi);
        return max(ans1,ans2)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxi = 0 ;
        dfs(root); 
        return maxi;
    }
};